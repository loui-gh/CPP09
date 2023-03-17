#include "PmergeMe.hpp"

/*default constructor*/
PmergeMe::PmergeMe(int argc, char *sequence[]) {

    CreateList(argc, sequence);
    CreateVector(argc, sequence);
    PrintAll();
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

    //create the list
    for (int i = 1; i < argc; ++i) {
        int value = std::atoi(sequence[i]);
        _lstOG.push_back(value);
    }
    //start the timer; merge; stop the clock;
    clock_t start = clock();
    _listSorted = _lstOG;
    MergeSortList(_listSorted);
    clock_t end = clock();
    _timerList = float(end - start) / CLOCKS_PER_SEC;


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
    std::cout << std::fixed << std::setprecision(5) << _timerList * 1000000 << " us" << std::endl;

    std::cout << "Time to process a range of " << _vecOG.size() << " elements with std::vector<>: ";
    std::cout << std::fixed << std::setprecision(5) << _timerVector* 1000000 << " us" << std::endl;
}

// std::list<int>&     PmergeMe::getOGList() {

//     return _lstOG;
// }

// std::list<int>&     PmergeMe::getSortedList() {

//    return _listSorted;
// }

// std::ostream& operator<<(std::ostream& os, const PmergeMe& p) {
//     os << "Before: ";
//     int counter = 0;
//     std::list<int>::const_iterator it = p.getOGList().begin();
//     while (counter != 5 && it != p.getSortedList().end()) {
//         os << *it << " ";
//         ++it;
//         ++counter;
//     }
//     if (it != p.getOGList().end())
//         os << " [...]\n";
//     else
//         os << std::endl;

//     os << "After: ";
//     int scounter = 0;
//     std::list<int>::const_iterator sit = p.getSortedList().begin();
//     while (scounter != 5 && sit != p.getSorted().end()) {
//         os << *sit << " ";
//         ++sit;
//         ++scounter;
//     }
//     if (sit != p.getSorted().end())
//         os << " [...]\n";
//     else
//         os << std::endl;

//     os << "Time to process a range of " << p.getSorted().size() << " elements with std::list<>: ";
//     os << std::fixed << std::setprecision(5) << p._timerList * 1000000 << " us" << std::endl;

//     os << "Time to process a range of " << p.getOGList().size() << " elements with std::vector<>: ";
//     os << std::fixed << std::setprecision(5) << p._timerVector * 1000000 << " us" << std::endl;

//     return os;
// }


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

void    PmergeMe::CreateVector(int argc, char *sequence[]) {

    //create the vector;
    for (int i = 1; i < argc; ++i) {
        int number = std::atoi(sequence[i]);
        _vecOG.push_back(number);
    }
    //start the timer; merge; stop the clock;
     clock_t start = clock();
    _vecSorted = _vecOG;
    MergeSortVector(_vecSorted);
    clock_t end = clock();
    _timerVector = float(end - start) / CLOCKS_PER_SEC;

}

void                PmergeMe::MergeSortVector( std::vector<int> &vec ) {

     for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            // Insert the out-of-order element in the sorted sequence
            vec.push_back(vec[i]);
            size_t j = vec.size() - 1;

            while (j > 0 && vec[j - 1] > vec[j]) {
                std::swap(vec[j], vec[j - 1]);
                j--;
            }

            // Remove the original out-of-order element
            vec.erase(vec.begin() + i);
        }
    }
}
