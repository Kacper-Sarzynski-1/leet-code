#include <iostream>
#include <unordered_map>
#include <vector>

/*
     Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
     Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.
     Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
*/

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::vector<int> result;
        std::unordered_map<int, int> hashMap;

        for(int i : arr2) {
            hashMap[i] = 0;
        }

        for(int i : arr1) {
            if (hashMap.find(i) != hashMap.end()) {
                hashMap[i]++;
            } else {
                auto pos = std::lower_bound(result.begin(), result.end(), i);
                result.insert(pos, i);
            }
        }

        for(int i = arr2.size() - 1; i >= 0; i--) {
            for(int j = 0; j < hashMap[arr2[i]]; j++) {
                result.insert(result.begin(), arr2[i]);
            }
        }

        return result;
    }
};

int main() {
    std::vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    std::vector<int> arr2 = {2,1,4,3,9,6};

    auto result = Solution().relativeSortArray(arr1, arr2);

    for (int & it : result) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}
