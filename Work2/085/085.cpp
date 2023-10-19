#include <iostream>
#include <vector>
#include <cassert>
#include <vector>

/**
 * 模型：Bing
 * prompt:
 * 1. 请理解代码
 * 2. 这是五个约束，第i约束是对于main函数中测试数组cases[i]，
 * 即size为cases[i]的数组长度，x0=cases[i][0],x1=cases[i][1]，
 * 请你为每个约束都生成关于add函数的测试用例，并且补全在main函数中的for语句中
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
