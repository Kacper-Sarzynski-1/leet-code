#include <iostream>
#include <vector>

/*
    Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
    You may return the answer in any order.
*/

void printVector(const std::vector<std::vector<int>>& vec) {
    for (const auto& row : vec) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

void printVector(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        combine(n, k, 1, combination, result);
        return  result;
    }

private:
    void combine(int n, int k, int start, std::vector<int>& combination, std::vector<std::vector<int>>& result) {
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i <= n; i++) {
            combination.push_back(i);
            combine(n, k, i + 1, combination, result);
            combination.pop_back();
        }
    }
};

int main() {
    printVector(Solution().combine(5, 3));
    return 0;
}

// It was pretty hard to find correct recursion approach