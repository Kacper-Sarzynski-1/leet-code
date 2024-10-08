#include <iostream>
#include <vector>

/*
    You are given an integer array height of length n.
    There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.
    Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int area = 0;

        while(start != end) {
            int newArea = std::min(height[start], height[end]) * abs(start - end);

            if (newArea > area) {
                area = newArea;
            }

            if (height[start] >= height[end]) {
                end--;
            } else {
                start++;
            }
        }

        return area;
    }
};

int main() {
    std::vector height = {1,8,6,2,5,4,8,3,7};

    std::cout << Solution().maxArea(height) << std::endl;

    return 0;
}
