#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findTwoNumbers(const std::vector<int>& elements, int targetSum) {
    std::unordered_map<int, int> elementMap;

    for (int i = 0; i < elements.size(); ++i) {
        int complement = targetSum - elements[i];

        auto it = elementMap.find(complement);
        if (it != elementMap.end()) {
            return {it->second, i};
        }

        elementMap[elements[i]] = i;
    }

    return {};
}

int main() {
    int numElements;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> numElements;

    std::vector<int> elements;
    std::cout << "Enter the elements of the array, separated by space: ";
    for (int i = 0; i < numElements; ++i) {
        int element;
        std::cin >> element;
        elements.push_back(element);
    }

    int targetSum;
    std::cout << "Enter the target sum: ";
    std::cin >> targetSum;

    std::vector<int> resultIndices = findTwoNumbers(elements, targetSum);

    if (!resultIndices.empty()) {
        std::cout << "Result Indices: [" << resultIndices[0] << ", " << resultIndices[1] << "]" << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}
