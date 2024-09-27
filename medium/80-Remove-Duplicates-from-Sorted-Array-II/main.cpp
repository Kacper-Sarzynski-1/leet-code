#include <iostream>
#include <vector>

/*
    Given an integer array nums sorted in non-decreasing order,
    remove some duplicates in-place such that each unique element appears at most twice.
    The relative order of the elements should be kept the same.
    Since it is impossible to change the length of the array in some languages,
    you must instead have the result be placed in the first part of the array nums.
    More formally, if there are k elements after removing the duplicates,
    then the first k elements of nums should hold the final result.
    It does not matter what you leave beyond the first k elements.
    Return k after placing the final result in the first k slots of nums.
    Do not allocate extra space for another array.
    You must do this by modifying the input array in-place with O(1) extra memory.
*/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int maxCount = 2;

        int k = 0;
        int currentNumberValue = -1;
        int currentNumberCount = 0;
        int removedNumbersCount = 0;

        for (int i = 0; i < nums.size() - removedNumbersCount;) {
            if (nums[i] != currentNumberValue) {
                currentNumberValue = nums[i];
                currentNumberCount = 1;
                k++;
                i++;
            } else {
                if (currentNumberCount < maxCount) {
                    currentNumberCount++;
                    k++;
                    i++;
                } else {
                    removedNumbersCount++;
                    nums.push_back(nums[i]);
                    nums.erase(nums.begin() + i);
                }
            }
        }

        return k;
    }
};

int main() {
    std::vector nums = {1,1,1,2,2,3};
    std::cout << Solution().removeDuplicates(nums) << std::endl;
    return 0;
}
