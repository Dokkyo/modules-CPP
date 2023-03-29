#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    // std::cout << "PmergeMe Default Constructor Called\n";
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
    // std::cout << "PmergeMe Copy Constructor Called\n";
    *this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    // std::cout << "PmergeMe Assignment operator Called\n";
    return *this;
}

PmergeMe::~PmergeMe()
{
    // std::cout << "PmergeMe Destructor Called\n";
}

int PmergeMe::_Check_Args(int size, char **tab)
{
    int i;
    int j;

    i = 0;
    while (++i < size)
    {
        j = 0;
        while (tab[i][j] != '\0')
        {
            if (tab[i][j] < 48 || tab[i][j] > 57)
            {
                return i;
            }
            j++;
        }
    }
    return 0;
}

int PmergeMe::SetContainers(int size, char **tab)
{
    int ret;

    ret = _Check_Args(size, tab);
    if (ret)
        return ret;
    ret = 1;
    _time_mset = _get_time();
    while (ret < size)
    {
        this->_mset.insert(atoi(tab[ret]));
        ret++;
    }
    _time_mset = _get_time() - _time_mset;
    ret = 1;
    _time_pqueue = _get_time();
    while (ret < size)
    {
        this->_pqueue.push(atoi(tab[ret]));
        ret++;
    }
    _time_pqueue = _get_time() - _time_pqueue;
    return 0;
}

double PmergeMe::_get_time()
{
    struct timeval t
    {
    };
    gettimeofday(&t, NULL);
    long int s = t.tv_sec * 1000000;
    long int us = t.tv_usec;
    double time = static_cast<double>(s + us);

    time /= 1000000;

    return time;
}

void    PmergeMe::Display(int ac, char **av)
{
    int i = 0;

    std::cout << "Before: ";
    while (++i < ac)
        std::cout << av[i] << " ";
    std::cout << std::endl;

    std::cout << "Set After: \n";
    std::multiset<unsigned int>::iterator it = _mset.begin();
    while (it != _mset.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    std::cout << "Priority queue After: \n";
    while (_pqueue.size() > 0)
    {
        std::cout << _pqueue.top() << " ";
        _pqueue.pop(); 
    }
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(9);
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::multiset : ";
    std::cout << _time_mset << " us\n";
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::priority_queue : ";
    std::cout << _time_pqueue << " us\n";
}
