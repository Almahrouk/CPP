#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

static void printResult(const std::string& test, bool passed)
{
    std::cout << (passed ? "[OK]   " : "[FAIL] ")
              << test << std::endl;
}

int main()
{
    std::cout << "===== Serializer Tests =====" << std::endl;

    // ------------------------------------------------------------
    // Test 1: Basic serialization/deserialization
    // ------------------------------------------------------------
    Data data;

    data.number = 42;
    data.text = "Hello, Serializer!";

    Data* original = &data;

    uintptr_t raw = Serializer::serialize(original);
    Data* restored = Serializer::deserialize(raw);

    printResult(
        "deserialize(serialize(ptr)) == ptr",
        restored == original
    );

    std::cout << "Original pointer : " << original << std::endl;
    std::cout << "Serialized value : " << raw << std::endl;
    std::cout << "Restored pointer : " << restored << std::endl;

    // Make sure the data is still accessible
    if (restored)
    {
        printResult(
            "Data contents preserved",
            restored->number == 42 &&
            restored->text == "Hello, Serializer!"
        );
    }

    // ------------------------------------------------------------
    // Test 2: Another Data object
    // ------------------------------------------------------------
    Data data2;

    data2.number = -123;
    data2.text = "Another object";

    Data* original2 = &data2;

    uintptr_t raw2 = Serializer::serialize(original2);
    Data* restored2 = Serializer::deserialize(raw2);

    printResult(
        "Second object pointer restored correctly",
        restored2 == original2
    );

    printResult(
        "Second object contents preserved",
        restored2 &&
        restored2->number == -123 &&
        restored2->text == "Another object"
    );

    // ------------------------------------------------------------
    // Test 3: Different objects produce different addresses
    // ------------------------------------------------------------
    printResult(
        "Different objects have different pointers",
        original != original2
    );

    printResult(
        "Different objects serialize to different values",
        raw != raw2
    );

    // ------------------------------------------------------------
    // Test 4: Null pointer
    // ------------------------------------------------------------
    Data* nullPtr = NULL;

    uintptr_t nullRaw = Serializer::serialize(nullPtr);
    Data* nullRestored = Serializer::deserialize(nullRaw);

    printResult(
        "NULL pointer survives serialization",
        nullRestored == NULL
    );

    // ------------------------------------------------------------
    // Test 5: Serialize the same pointer twice
    // ------------------------------------------------------------
    uintptr_t rawAgain = Serializer::serialize(original);

    printResult(
        "Same pointer produces same serialized value",
        rawAgain == raw
    );

    Data* restoredAgain = Serializer::deserialize(rawAgain);

    printResult(
        "Same serialized value restores same pointer",
        restoredAgain == original
    );

    // ------------------------------------------------------------
    // Test 6: Pointer remains usable after deserialization
    // ------------------------------------------------------------
    restored->number = 100;

    printResult(
        "Deserialized pointer can access original object",
        data.number == 100
    );

    // ------------------------------------------------------------
    // Summary
    // ------------------------------------------------------------
    std::cout << "============================" << std::endl;

    return 0;
}
