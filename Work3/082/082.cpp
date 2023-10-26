#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>

/**
 *
Write a function that takes a string and returns True if the string
    length is a prime number or False otherwise
    Examples
    prime_length('Hello') == True
    prime_length('abcdcba') == True
    prime_length('kittens') == True
    prime_length('orange') == False
    这是一个程序的功能说明注释
 * "a", "ab", "abc"这是三个输入，请你得到他们的输出
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
    std::vector<std::string> cases = {"a", "ab", "abc"};
    std::vector<bool> expected_outs = {false, true, true};

    std::vector<bool> llm_outs_1 = {false, true, true};
    std::vector<bool> llm_outs_2 = {false, false, true};
    std::vector<bool> llm_outs_3 = {false, true, true};

    for (int i = 0; i < cases.size(); ++i) {
        bool result = prime_length(cases[i]);
        assert(result == expected_outs[i]);
        assert(result == llm_outs_1[i]);
        assert(result == llm_outs_2[i]);
        assert(result == llm_outs_3[i]);
    }

    // 正确率：88.9%
    //分析：偶尔出错一个
    return 0;
}