#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <exception>

/**
 *
 *  Given a positive integer n, return the count of the numbers of n-digit
    positive integers that start or end with 1.
 *
这是一个程序的功能说明注释
 *0, 1, 3这是三个测试用例输入，请你得到他们的输出
 */
int starts_one_ends(int n) {
    if (n <= 0) {
        std::cout << "Error in starts_one_ends: invalid inputs" << std::endl;
        return -1; // Return a special value to indicate an error
    }
    if (n == 1) {
        return 1;
    } else {
        return 18 * static_cast<int>(pow(10, n - 2)); // Calculate the count of n-digit numbers
    }
}

int main() {
    std::vector<int> cases = {0, 1, 3};
    std::vector<int> expected = {-1, 1, 180};

    std::vector<int> llm_outs_1 = {-1, 1, 180};
    std::vector<int> llm_outs_2 = {-1, 1, 180};
    std::vector<int> llm_outs_3 = {-1, 1, 180};

    for (int i = 0; i < cases.size(); ++i) {
        int number = cases[i];
        int result = starts_one_ends(number);
        assert(result == expected[i]);
        assert(result == llm_outs_1[i]);
        assert(result == llm_outs_2[i]);
        assert(result == llm_outs_3[i]);
    }

    // 正确率100%
    return 0;
}
