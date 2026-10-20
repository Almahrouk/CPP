#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <sys/time.h>


PmergeMe::PmergeMe() : _origin(), _vec(), _deque() {}

PmergeMe::PmergeMe(const PmergeMe &obj)
    : _origin(obj._origin), _vec(obj._vec), _deque(obj._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
    {
        _origin = obj._origin;
        _vec = obj._vec;
        _deque = obj._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

const std::vector<int> &PmergeMe::getOrigin() const { return _origin; }
const std::vector<int> &PmergeMe::getVector() const { return _vec; }
const std::deque<int>  &PmergeMe::getDeque() const  { return _deque; }


static double nowInMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

template <typename Container>
static void printNumbers(const Container &numbers)
{
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << numbers[i];
    }
    std::cout << std::endl;
}

// Returns 1, 3, 5, 11, 21, ... until the last number is >= size.
// for vector + deque
static std::vector<int> generateJacobsthal(int size)
{
    std::vector<int> jacob;
    if (size <= 0)
        return jacob;

    int a0 = 1;
    int a1 = 3;
    jacob.push_back(a0);
    while (a1 <= size)
    {
        jacob.push_back(a1);
        int next = a1 + (2 * a0); // J(n) = J(n-1) + 2J(n-2)
        a0 = a1;
        a1 = next;
    }
    if (jacob.back() < size)
        jacob.push_back(a1);
    return jacob;
}

// vector

static void binaryInsertVector(const std::vector<int> &values, std::vector<int> &chain,
                               int newIndex, size_t searchEnd)
{
    size_t left = 0;
    size_t right = searchEnd;

    while (left < right)
    {
        size_t middle = left + (right - left) / 2;
        if (values[chain[middle]] < values[newIndex])
            left = middle + 1;
        else
            right = middle;
    }
    chain.insert(chain.begin() + left, newIndex);
    // std::cout << "NEW Chain: " << std::endl;
    // printNumbers(chain);
    // First time: [(3) 1 0 5 2] -> add b3 = 1, its index = 3
    // Secound time: [3 1 (4) 0 5 2] -> add b2 = 5, its index = 4
    // Therd time: [3 (6) 1 4 0 5 2] -> add b4 = 2, its index = 6
}

// Insert b2, b3, ... in Jacobsthal order.
// mainChain[i] = a(i+1), pending[i] = b(i+1).
// If there is a straggler, it is the last element of pending.
static void insertPendingVector(const std::vector<int> &values, std::vector<int> &chain,
                                const std::vector<int> &mainChain, const std::vector<int> &pending)
{
    const size_t pairCount = mainChain.size();
    const size_t pendingCount = pending.size(); // loser (b) + remaning -> b2, b3, b4, b5, 
    std::vector<int> jacob = generateJacobsthal(static_cast<int>(pendingCount)); // 1, 3, 5, 11, 21, ...
    // std::cout << "Values: " << std::endl; 
    // printNumbers(values); // origin vector [7 3 9 1 5 8 2]
    // std::cout << "Chain: " << std::endl;
    // printNumbers(chain); // index of winners in winner vector: winner vector + b1: [b1 a1 a2 a3] = [3 7 9 8] => ther index: [1 0 2 5]
    // std::cout << "Main Chain: " << std::endl;
    // printNumbers(mainChain); // index of winners in winner vector: winner vector: [a1 a2 a3] = [7 9 8] => ther index: [0 2 5]
    // std::cout << "Pending: " << std::endl;
    // printNumbers(pending); // index of losers in losers vector: losers vector: [b1 b2 b3 b4] = [3 5 1 2] => ther index: [1 4 3 6]

    size_t inserted = 1;                            // b1 is already in the chain

    for (size_t j = 1; j < jacob.size() && inserted < pendingCount; j++)
    {
        size_t groupEnd = std::min(static_cast<size_t>(jacob[j]), pendingCount); // G1: [b2, b3], G2: [b4, b5], G3: [b6, b7, ..., b11]
        // std::cout << "Group End: " << groupEnd << std::endl; // Loop1: 3, Loop2: 4
        for (size_t n = groupEnd; n > inserted; n--)        // high to low: G1: [b3, b2], G2: [b4]
        {
            size_t searchEnd = chain.size();                // straggler: whole chain
            if (n <= pairCount)                             // normal loser: stop at its winner
                searchEnd = std::find(chain.begin(), chain.end(), mainChain[n - 1]) - chain.begin();
            // std::cout << "Search End: " << searchEnd << std::endl; // G1: [L1: 3, L2: 3], G2: [L1: 6]
            binaryInsertVector(values, chain, pending[n - 1], searchEnd);
            // just the remaning value needs to search with: searchEnd = chain.size()
        }
        inserted = groupEnd;
    }
}

// Returns the indices of `values` in sorted order.
static std::vector<int> fordJohnsonVector(const std::vector<int> &values)
{
    const size_t total = values.size();
    std::vector<int> result;

    if (total == 0)
        return result;
    if (total == 1)
    {
        result.push_back(0);
        return result;
    }

    // 1. Pairs: winner = bigger, loser = smaller
    const size_t pairCount = total / 2;
    std::vector<int> winners, losers, winnerValues;
    for (size_t p = 0; p < pairCount; p++)
    {
        int first = static_cast<int>(2 * p);
        int second = first + 1;
        if (values[first] < values[second]) 
            std::swap(first, second);
        winners.push_back(first);
        losers.push_back(second);
        winnerValues.push_back(values[first]);
    }

    // 2. Sort the winners recursively
    std::vector<int> order = fordJohnsonVector(winnerValues);

    // 3. mainChain = a1..ak (sorted), pending = b1..bk (+ straggler last)
    std::vector<int> mainChain, pending;
    for (size_t k = 0; k < pairCount; k++)
    {
        mainChain.push_back(winners[order[k]]);
        pending.push_back(losers[order[k]]);
    }
    if (total % 2 == 1) // if odd
        pending.push_back(static_cast<int>(total - 1));

    // 4. Start chain: b1, a1, a2, ..., ak
    std::vector<int> chain;
    chain.push_back(pending[0]);
    chain.insert(chain.end(), mainChain.begin(), mainChain.end());

    // 5. Insert the remaining b's in Jacobsthal order
    insertPendingVector(values, chain, mainChain, pending);
    return chain;
}

static void sortVector(std::vector<int> &numbers)
{
    std::vector<int> positions = fordJohnsonVector(numbers);
    std::vector<int> sorted;

    for (size_t i = 0; i < positions.size(); i++)
        sorted.push_back(numbers[positions[i]]);
    numbers.swap(sorted);
}

// deque

static void binaryInsertDeque(const std::deque<int> &values, std::deque<int> &chain,
                              int newIndex, size_t searchEnd)
{
    size_t left = 0;
    size_t right = searchEnd;

    while (left < right)
    {
        size_t middle = left + (right - left) / 2;
        if (values[chain[middle]] < values[newIndex])
            left = middle + 1;
        else
            right = middle;
    }
    chain.insert(chain.begin() + left, newIndex);
}

static void insertPendingDeque(const std::deque<int> &values, std::deque<int> &chain,
                               const std::deque<int> &mainChain, const std::deque<int> &pending)
{
    const size_t pairCount = mainChain.size();
    const size_t pendingCount = pending.size();
    std::vector<int> jacob = generateJacobsthal(static_cast<int>(pendingCount));
    size_t inserted = 1;

    for (size_t j = 1; j < jacob.size() && inserted < pendingCount; j++)
    {
        size_t groupEnd = std::min(static_cast<size_t>(jacob[j]), pendingCount);

        for (size_t n = groupEnd; n > inserted; n--)
        {
            size_t searchEnd = chain.size();
            if (n <= pairCount)
                searchEnd = std::find(chain.begin(), chain.end(), mainChain[n - 1]) - chain.begin();
            binaryInsertDeque(values, chain, pending[n - 1], searchEnd);
        }
        inserted = groupEnd;
    }
}

static std::deque<int> fordJohnsonDeque(const std::deque<int> &values)
{
    const size_t total = values.size();
    std::deque<int> result;

    if (total == 0)
        return result;
    if (total == 1)
    {
        result.push_back(0);
        return result;
    }

    const size_t pairCount = total / 2;
    std::deque<int> winners, losers, winnerValues;
    for (size_t p = 0; p < pairCount; p++)
    {
        int first = static_cast<int>(2 * p);
        int second = first + 1;
        if (values[first] < values[second])
            std::swap(first, second);
        winners.push_back(first);
        losers.push_back(second);
        winnerValues.push_back(values[first]);
    }

    std::deque<int> order = fordJohnsonDeque(winnerValues);

    std::deque<int> mainChain, pending;
    for (size_t k = 0; k < pairCount; k++)
    {
        mainChain.push_back(winners[order[k]]);
        pending.push_back(losers[order[k]]);
    }
    if (total % 2 == 1)
        pending.push_back(static_cast<int>(total - 1));

    std::deque<int> chain;
    chain.push_back(pending[0]);
    chain.insert(chain.end(), mainChain.begin(), mainChain.end());

    insertPendingDeque(values, chain, mainChain, pending);
    return chain;
}

static void sortDeque(std::deque<int> &numbers)
{
    std::deque<int> positions = fordJohnsonDeque(numbers);
    std::deque<int> sorted;

    for (size_t i = 0; i < positions.size(); i++)
        sorted.push_back(numbers[positions[i]]);
    numbers.swap(sorted);
}

// parsing + run

bool PmergeMe::parse(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        const char *argument = argv[i];

        if (*argument == '\0')
            return false;
        for (const char *c = argument; *c; c++)
        {
            if (!std::isdigit(static_cast<unsigned char>(*c)))
                return false;
        }
        errno = 0;
        long number = std::strtol(argument, NULL, 10);
        if (errno == ERANGE || number > INT_MAX)
            return false;
        _origin.push_back(static_cast<int>(number));
    }
    return !_origin.empty();
}

int PmergeMe::run(int argc, char **argv)
{
    if (argc < 2 || !parse(argc, argv))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    _vec = _origin;
    _deque.assign(_origin.begin(), _origin.end());

    std::cout << "Before: ";
    printNumbers(_origin);

    double startTime = nowInMicroseconds();
    sortVector(_vec);
    double vectorTime = nowInMicroseconds() - startTime;

    startTime = nowInMicroseconds();
    sortDeque(_deque);
    double dequeTime = nowInMicroseconds() - startTime;

    std::cout << "After:  ";
    printNumbers(_vec);

    std::cout << "Time to process a range of " << _origin.size()
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _origin.size()
              << " elements with std::deque  : " << dequeTime << " us" << std::endl;
    return 0;
}