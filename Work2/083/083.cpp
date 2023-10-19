#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <exception>

/**
 * ģ�ͣ�Bing
 * prompt:
 * 1. ��������
 * 2. �������Լ����Լ���е�n��ʾstarts_one_ends�Ĵ������
 * ����Ϊÿ��Լ�������ɹ���starts_one_ends�����Ĳ������������Ҳ�ȫ��main�����е�for�����
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
    for (int i = 0; i < cases.size(); i++) {
        int number = cases[i];
        int result = starts_one_ends(number);
        if (result != -1) { // Check if starts_one_ends returned an error
            try {
                assert(result == expected[i]);
                std::cout << "Test case " << i << " passed." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Test case " << i << " failed: " << e.what() << std::endl;
            }
        }
    }
    return 0;
}
