#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <iomanip>


class   PmergeMe {

    private:
        std::list<int>      _lstOG;
        std::list<int>      _listSorted;
        std::vector<int>    _vecOG;
        std::vector<int>    _vecSorted;
        float               _elapsed_seconds;

    public:
        PmergeMe(int argc, char *sequence[]);
		PmergeMe(PmergeMe const & input);
		PmergeMe const & operator=(PmergeMe const & input);
		~PmergeMe(void);

        void                PrintAll();

        void                CreateList(int argc, char *sequence[]);
        void                MergeSortList( std::list<int> &lst );
        
        // void                CreateVector(int argc, char *sequence[]);
        // void                MergeSortVector();

};

#endif