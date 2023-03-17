#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <limits>


class   PmergeMe {

    private:
        std::list<int>      _lstOG;
        std::list<int>      _listSorted;
        std::vector<int>    _vecOG;
        std::vector<int>    _vecSorted;
        float               _timerList;
        float               _timerVector;

    public:
        PmergeMe(int argc, char *sequence[]);
		PmergeMe(PmergeMe const & input);
		PmergeMe const & operator=(PmergeMe const & input);
		~PmergeMe(void);

        void                PrintAll();

        void                    CreateList(int argc, char *sequence[]);
        void                    MergeSortList( std::list<int> &lst );
        // const std::list<int>&   getOGList();
        // const std::list<int>&   getSortedList();

        
        void                CreateVector(int argc, char *sequence[]);
        void                MergeSortVector(std::vector<int> &vec);


};

// std::ostream & operator<<(std::ostream & os,  const PmergeMe& p);

#endif
