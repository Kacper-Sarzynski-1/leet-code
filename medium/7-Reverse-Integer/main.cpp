#include <iostream>

/*
    Given a signed 32-bit integer x, return x with its digits reversed.
    If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;

        while(abs(x) > 0) {
            const int digit = x % 10;
            x /= 10;

            if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) {
                return 0;
            }

            reversed *= 10;
            reversed += digit;
        }

        return reversed;
    }
};

int main() {

    std::cout << Solution().reverse(15369) << std::endl;
    std::cout << Solution().reverse(-1534269) << std::endl;

    return 0;
}
