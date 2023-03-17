#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [integer_sequence]" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::string str = argv[i];
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
            if (!isdigit(*it)) {
                std::cerr << "Error\n";
                return 1;
            }
        }
    }
    for (int i = 1; i < argc; ++i) {
        int value = std::atoi(argv[i]);
        if (value <= 0) {
            std::cerr << "Error\n";
            return 1;
        }
    }

    try {
        PmergeMe instance(argc, argv);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what();
        return 1;
    }

    return 0;
}



// void insert(std::vector<int>& vec, int value) {
//     vec.push_back(value);
//     int i = vec.size() - 1;

//     while (i > 0 && vec[i - 1] > vec[i]) {
//         std::swap(vec[i], vec[i - 1]);
//         i--;
//     }
// }

// void merge_insert_sort(std::vector<int>& vec) {
//     for (size_t i = 1; i < vec.size(); ++i) {
//         if (vec[i] < vec[i - 1]) {
//             insert(vec, vec[i]);
//             vec.erase(vec.begin() + i);
//         }
//     }
// }

// int main(int argc, char* argv[]) {
//     if (argc < 2) {
//         std::cerr << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
//         return 1;
//     }

//     std::vector<int> sequence;
//     for (int i = 1; i < argc; ++i) {
//         int number = std::atoi(argv[i]);
//         if (number < 1) {
//             std::cerr << "Error: Only positive integers are allowed." << std::endl;
//             return 1;
//         }
//         sequence.push_back(number);
//     }

//     std::vector<int> original_sequence(sequence);

//     clock_t start_time = clock();
//     merge_insert_sort(sequence);
//     clock_t end_time = clock();

//     float elapsed_time = static_cast<float>(end_time - start_time) / CLOCKS_PER_SEC;

//     std::cout << "Before: ";
//     for (size_t i = 0; i < original_sequence.size(); ++i) {
//         std::cout << original_sequence[i] << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "After: ";
//     for (size_t i = 0; i < sequence.size(); ++i) {
//         std::cout << sequence[i] << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "Time to process a range of " << sequence.size() << " elements with std::vector<> : " << (elapsed_time * 1000) << " us" << std::endl;

//     return 0;
// }
