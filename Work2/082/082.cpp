#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>

/**
 * 模型：Bing
 * prompt:
 * 1. 请理解代码
 * 2. 这是五个约束，请你为每个约束都生成关于prime_length函数的测试用例，并且补全在main函数中的for语句中
 */

bool is_prime(int a) {
    if (a < 2) {
        return false;
    }

    for (int x = 2; x <= sqrt(a); ++x) {
        if (a % x == 0) {
            return false;
        }
    }

    return true;
}
bool prime_length(const std::string& str) {
    int length = str.length();
    return is_prime(length);
}

int main() {
    std::vector<std::string> cases = {"", "a", "ab", "abc", "abcd"};
    std::vector<bool> expected = {false, false, true, true, false};
    for (int i = 0; i < cases.size(); ++i) {
        bool result = prime_length(cases[i]);
        assert(result == expected[i]);
    }
    std::cout << "All test cases passed." << std::endl;
    return 0;
}