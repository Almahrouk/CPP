// positive integer sequence
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <ctime>

class PmergeMe
{
    private:
        enum Status
        {
            SUCCESS = 0,
            InvalidInput,
        };
        std::string      _input;
        std::vector<int>  _vec_origin;
        std::vector<int>  _vec;
        std::deque<int>  _deque_origin;
        std::deque<int>  _deque;

    public:
        PmergeMe();
        PmergeMe(const std::string &input);
        PmergeMe(const PmergeMe &obj);
        PmergeMe &operator=(const PmergeMe &obj);
        ~PmergeMe();

        bool isValidInput(const std::string &input) const;

        const std::string      &getInput() const;
        const std::vector<int>  &getVector() const;
        const std::deque<int>  &getDeque() const;
        void setInput(const std::string &input);
        void setOriginVector(const std::vector<int> &vec);
        void setVector(const std::vector<int> &vec);
        void setOriginDeque(const std::deque<int> &deque);
        void setDeque(const std::deque<int> &deque);

        void mergeSortVector(std::vector<int> vec) const;
        void mergeSortDeque(std::deque<int> deque) const;
        void mergeVector(std::vector<int> leftVector, std::vector<int> rightVector, std::vector<int> vec) const;
        void mergeDeque(std::deque<int> leftDeque, std::deque<int> rightDeque, std::list<int> list) const;
        
        int run(const std::string &input);
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &PmergeMe);

#endif