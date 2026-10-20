#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _input(""), {}

PmergeMe::PmergeMe(const std::string &input)
    : _input(input) {}

PmergeMe::PmergeMe(const PmergeMe &obj)
    : _input(obj._input) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
    {
        _input = obj._input;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidInput(const std::string &input) const
{

}

const std::string &PmergeMe::getInput() const
{
    return _input;
}

const std::vector<int> &PmergeMe::getOriginVector() const
{
    return _vec_origin;
}

const std::vector<int> &PmergeMe::getVector() const
{
    return _vec;
}

const std::deque<int> &PmergeMe::getOrigindeque() const
{
    return _deque_origin;
}

const std::deque<int> &PmergeMe::getdeque() const
{
    return _deque;
}

void PmergeMe::setInput(const std::string &input)
{
    _input = input;
}

void PmergeMe::setOriginVector(const std::vector<int> &vec)
{
    _vec_origin = vec;
}

void PmergeMe::setVector(const std::vector<int> &vec)
{
    _vec = vec;
}

void PmergeMe::setOriginDeque(const std::deque<int> &deque)
{
    _deque_origin = deque;
}

void PmergeMe::setDeque(const std::deque<int> &deque)
{
    _deque = deque;
}

bool PmergeMe::isValidNumber(const std::string &input) const
{
    
    return (input[i] >=  '0' && input[i] <=  '9');
}

void PmergeMe::mergeSortVector(std::vector<int> vec) const
{
    std::vector<int> leftVec;
    std::vector<int> rightVec;

    if (vec.size() <= 1)
        return ;
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        if (i < vec.size() / 2)
            leftVec.push_back(*it);
        else
            rightVec.push_back(*it);
    }
    mergeSortVector(leftVec);
    mergeSortVector(rightVec);
    mergeVector(leftVec, rightVec, vec);
}

void PmergeMe::mergeSortDeque(std::deque<int> deque) const
{
    std::deque<int> leftDeque;
    std::deque<int> rightDeque;

    if (deque.size() <= 1)
        return ;
    for (deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
    {
        if (i < deque.size() / 2)
            leftDeque.push_back(*it);
        else
            rightDeque.push_back(*it);
    }
    mergeSortVector(leftDeque);
    mergeSortVector(rightDeque);
    mergeVector(leftDeque, rightDeque, deque);
}

void PmergeMe::mergeVector(std::vector<int> leftVector, std::vector<int> rightVector, std::vector<int> vec) const
{
    int leftSize = vec.size() / 2;
    int rightSize = vec.size() - leftSize;
    vector<int>::iterator it = vec.begin();
    vector<int>::iterator itLeft = leftVector.begin();
    vector<int>::iterator itRight = rightVector.begin();
    int i = 0;
    int iLeft = 0;
    int iRight = 0;
    while (iLeft < leftSize && iRight < rightSize)
    {
        if (*itLeft < *itRight)
        {
            it.push_back(*itLeft);
            i++;
            iLeft++;
            itLeft++;
        }
        else
        {
            it.push_back(*itRight);
            i++;
            iRight++;
            itRight++;
        }
    }
    while (iLeft < leftSize)
    {
        it.push_back(*itLeft);
        i++;
        iLeft++;
        itLeft++;
    }
    while (iRight < rightSize)
    {
        it.push_back(*itRight);
        i++;
        iRight++;
        itRight++;
    }
}

void PmergeMe::mergeDeque(std::deque<int> leftDeque, std::deque<int> rightDeque, std::deque<int> deque) const
{
    int leftSize = deque.size() / 2;
    int rightSize = deque.size() - leftSize;
    deque<int>::iterator it = vec.begin();
    deque<int>::iterator itLeft = leftDeque.begin();
    deque<int>::iterator itRight = rightDeque.begin();
    int i = 0;
    int iLeft = 0;
    int iRight = 0;
    while (iLeft < leftSize && iRight < rightSize)
    {
        if (*itLeft < *itRight)
        {
            it.push_back(*itLeft);
            i++;
            iLeft++;
            itLeft++;
        }
        else
        {
            it.push_back(*itRight);
            i++;
            iRight++;
            itRight++;
        }
    }
    while (iLeft < leftSize)
    {
        it.push_back(*itLeft);
        i++;
        iLeft++;
        itLeft++;
    }
    while (iRight < rightSize)
    {
        it.push_back(*itRight);
        i++;
        iRight++;
        itRight++;
    }
}

/*
        std::string      _input;
        std::vector<int>  _vec_origin;
        std::vector<int>  _vec;
        std::deque<int>  _deque_origin;
        std::deque<int>  _deque;
*/
void PmergeMe::run(const std::string &input) const
{
    for (int i = 1; i < input.size(); i++)
    {
        int num = atoi(input[i]);
        if (isdigit(num) && num >= 0)
        {
            _vec_origin.push_back(num);
            _vec.push_back(num);
            _deque_origin.push_back(num);
            _deque.push_back(num);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
    }
    std::clock_t startMergeVector = std::clock();
    mergeVector(_vec);
    std::clock_t endMergeVector = std::clock();
    double msMergeVector = 1000.0 * (endMergeVector - startMergeVector) / CLOCKS_PER_SEC;

    std::clock_t startMergeDeque = std::clock();
    mergeDeque(_deque);
    std::clock_t endMergeDeque = std::clock();
    double msMergeDeque = 1000.0 * (endMergeDeque - startMergeDeque) / CLOCKS_PER_SEC;

    std::cout << "Before: " << _vec_origin << std::endl;
    std::cout << "After: " << _vec << std::endl;
    std::cout << "Time to process a range of " << input.size() << "elements with std::vector : " << msMergeVector * 1000 << " us" << std::endl;
    std::cout << "Time to process a range of " << input.size() << "elements with std::deque : " << msMergeDeque * 1000 << " us" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PmergeMe &PmergeMe)
{
    os << PmergeMe.getInput();
    return os;
}