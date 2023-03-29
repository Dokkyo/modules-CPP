#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <sys/time.h>

class PmergeMe
{
    private:
        int                         _Check_Args(int size, char **tab);
        double                      _time_mset;
        double                      _time_pqueue;
        double                      _get_time(void);
        std::set<unsigned int>         _mset;
        std::priority_queue<unsigned int, std::vector<unsigned int>, std::greater<unsigned int>>   _pqueue;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe & rhs);
        PmergeMe & operator=(const PmergeMe & rhs);
        ~PmergeMe();

        int                         SetContainers(int size, char **tab);
        void                        Display(int ac, char **av);
};

#endif