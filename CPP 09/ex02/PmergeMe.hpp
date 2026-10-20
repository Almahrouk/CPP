#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    ~PmergeMe();

    int run(int argc, char **argv);

    const std::vector<int> &getOrigin() const;
    const std::vector<int> &getVector() const;
    const std::deque<int>  &getDeque() const;

private:
    bool parse(int argc, char **argv);

    std::vector<int> _origin;
    std::vector<int> _vec;
    std::deque<int>  _deque;
};

#endif