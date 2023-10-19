#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>

/**
 * ģ�ͣ�Bing
 * prompt:
 * 1. ��������
 * 2. �������Լ��������Ϊÿ��Լ�������ɹ���prime_length�����Ĳ������������Ҳ�ȫ��main�����е�for�����
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