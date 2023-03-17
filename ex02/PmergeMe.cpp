#include "PmergeMe.hpp"

/*default constructor*/
PmergeMe::PmergeMe(int argc, char *sequence[]) {

    CreateList(argc, sequence);

   // MergeSortList(getList());
   // PrintAll();
}

/*copy constructor*/
PmergeMe::PmergeMe(PmergeMe const & input) {

    *this = input;
}

/*Assigment operator*/
PmergeMe const & PmergeMe::operator=(PmergeMe const & input){

    this->~PmergeMe();
    new (this) PmergeMe(input);
    return(*this);
}

PmergeMe::~PmergeMe( void ) {}


void    PmergeMe::CreateList(int argc, char *sequence[]) {

    //check for non-digits:
    for (int i = 1; i < argc; ++i) {
        int value = std::atoi(sequence[i]);
        _lstOG.push_back(value);
    }
    clock_t start = clock();
    _listSorted = _lstOG;
    MergeSortList(_listSorted);
    clock_t end = clock();
    _elapsed_seconds = float(end - start) / CLOCKS_PER_SEC;
    PrintAll();


}

void    PmergeMe::PrintAll( ) {

    std::cout << "Before: ";
    int counter = 0;
    std::list<int>::iterator it = _lstOG.begin();
    while (counter != 5 && it != _lstOG.end()) {
        std::cout << *it << " ";
        ++it; 
        ++counter;
    }
    if (it != _lstOG.end())
        std::cout << " [...]\n";
    else
        std::cout << std::endl;

    std::cout << "After: ";
    int scounter = 0;
    std::list<int>::iterator sit = _listSorted.begin();
    while (scounter != 5 && sit != _listSorted.end()) {
        std::cout << *sit << " ";
        ++sit; 
        ++scounter;
    }
    if (sit != _listSorted.end())
        std::cout << " [...]\n";
    else
        std::cout << std::endl;

    std::cout << "Time to process a range of " << _listSorted.size() << " elements with std::list<>: ";
    std::cout << std::fixed << std::setprecision(5) << _elapsed_seconds * 1000000 << " us" << std::endl;
}


void PmergeMe::MergeSortList(std::list<int> &lst ) {
    
    if (lst.size() <= 1) return;

    std::list<int> left, right;

    typename std::list<int>::iterator mid = lst.begin();
    std::advance(mid, lst.size() / 2);

    left.splice(left.begin(), lst, lst.begin(), mid);
    right.splice(right.begin(), lst, mid, lst.end());

    MergeSortList(left);
    MergeSortList(right);

    typename std::list<int>::iterator it_left = left.begin();
    typename std::list<int>::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left < *it_right) {
            lst.push_back(*it_left++);
        } else {
            lst.push_back(*it_right++);
        }
    }

    lst.splice(lst.end(), left, it_left, left.end());
    lst.splice(lst.end(), right, it_right, right.end());
}

// void                PmergeMe::CreateVector(int argc, char *sequence[]) {

//     std::vector<int> sequence;
//     for (int i = 1; i < argc; ++i) {
//         int number = std::atoi(sequence[i]);
//         if (number < 1) {
//             throw std::runtime_error << "Error: Only positive integers are allowed." << std::endl;
//         }
//         sequence.push_back(number);
//     }

//     std::vector<int> original_sequence(sequence);
// }
// void                PmergeMe::MergeSortVector() {


// }