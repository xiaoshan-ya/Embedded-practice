#include <iostream>
#include <vector>
#include <cassert>
#include <vector>

/**
 * ģ�ͣ�Bing
 * prompt:
 * 1. ��������
 * 2. �������Լ������iԼ���Ƕ���main�����в�������cases[i]��
 * ��sizeΪcases[i]�����鳤�ȣ�x0=cases[i][0],x1=cases[i][1]��
 * ����Ϊÿ��Լ�������ɹ���add�����Ĳ������������Ҳ�ȫ��main�����е�for�����
 */

int add(const std::vector<int>& lst) {
    // Check if lst is empty
    if (lst.empty()) {
        return 0;
    }

    int s = 0;
    for (int i = 1; i < lst.size(); i += 2) {
        if (lst[i] % 2 == 0) {
            s += lst[i];
        }
    }
    return s;
}

int main() {
    std::vector<std::vector<int>> cases = {{}, {2}, {1, 2}, {1, 2, 3, 4}, {1, 2, 3, 4, 5}};
    std::vector<int> expected = {0, 0, 2, 6, 6};
    for (int i = 0; i < cases.size(); i++) {
        auto numbers = cases[i];
        int result = add(numbers);
        try {
            assert(result == expected[i]);
            std::cout << "Test case " << i << " passed." << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Test case " << i << " failed: " << e.what() << std::endl;
        }
    }
    return 0;
}
