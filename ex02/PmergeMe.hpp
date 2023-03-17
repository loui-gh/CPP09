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
        std::list<int>      _lst;
       // std::vector<int>    _vec;
        float               _elapsed_seconds;

    public:
        PmergeMe(int argc, char *sequence[]);
		PmergeMe(PmergeMe const & input);
		PmergeMe const & operator=(PmergeMe const & input);
		~PmergeMe(void);

        void                PrintAll();

        void                CreateList(int argc, char *sequence[]);
        void                MergeSortList( std::list<int> &lst );
        
        // void                CreateVector();
        // void                MergeSortVector();

};

#endif