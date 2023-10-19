#include <iostream>
#include <cassert>
#include <string>
#include <vector>

/**
 * 模型：Bing
 * prompt:
 * 1. 请理解代码
 * 2. 这是五个约束，约束中的n表示solves的传入参数
 * 请你为每个约束都生成关于solve函数的测试用例，并且补全在main函数中的for语句中
 */

std::string solve(int N) {
    // Check if N is a positive integer within constraints
    assert(N > 0 && N <= 10000 && "invalid inputs");

    int sum = 0;
    int tempN = N;

    while (tempN > 0) {
        sum += tempN % 10; // Extract the last digit and add it to the sum
        tempN /= 10; // Remove the last digit
    }

    // Convert the sum to its binary representation
    std::string binarySum;
    while (sum > 0) {
        binarySum = (sum % 2 == 0 ? '0' : '1') + binarySum; // Append binary digit
        sum /= 2;
    }

    return binarySum;
}

int main() {
    std::vector<int> cases = {1001, 21, 111, 22, 1111};
    std::vector<std::string> expected = {"10", "11", "11", "100", "100"};
    for (int i = 0; i < cases.size(); i++) {
        int N = cases[i];
        std::string result = solve(N);
        try {
            assert(result == expected[i]);
            std::cout << "Test case " << i << " passed." << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Test case " << i << " failed: " << e.what() << std::endl;
        }
    }
    return 0;
}
