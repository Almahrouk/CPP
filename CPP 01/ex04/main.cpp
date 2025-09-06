#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>


int main(int ac, char **av)
{
    std::string fileName;
    std::string s1;
    std::string s2;
    std::ifstream src;
    std::ofstream dest;
    std::string line;
    std::string destFileName;

    if(ac < 4)
    {
        std::cout << "Invalid input: ./replace <filename> <s1> <s2>" << std::endl;
        return EXIT_FAILURE;
    }
    fileName = av[1];
    src.open(fileName.c_str());
    if(!src.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return EXIT_FAILURE;
    }
    s1 = av[2];
    s2 = av[3];
    destFileName = fileName + ".replace";
    dest.open(destFileName.c_str());
    if (!dest)
    {
        std::cerr << "Error creating file!" << std::endl;
        return EXIT_FAILURE;
    }
    while(std::getline(src, line))
    {
        // std::cout << line << std::endl;
        size_t pos;
        pos = 0;
        while( (pos = line.find(s1, pos)) != std::string::npos )
        {
            line.erase(pos, s1.size());
            line.insert(pos, s2);
        }
        // std::cout << line << std::endl;
        dest << line << std::endl;
    }
    src.close();
    dest.close();
    return EXIT_SUCCESS;
}
