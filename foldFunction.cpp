// foldFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector> 
#include <functional>
#include<stdexcept>

int fold(const std::vector<int>& vec, std::function<int(int, int)> func) {
    if (vec.empty()) {
        throw std::invalid_argument("Vector can't be empty.");

    }
    int result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = func(result, vec[i]);
    }
    return result;
}

int main()
{
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    int sum = fold(numbers, [](int a, int b) {return a * b; });
    std::cout << "Sum: " << sum << "\n";

    return 0;
    
}

