#include <iostream>
#include <vector>
#include <cassert>
#include <vector>

/**
 * Given a non-empty list of integers lst. add the even elements that are at odd indices..


    Examples:
        add([4, 2, 6, 7]) ==> 2
  这是一个程序的功能说明注释
 * {2}, {1, 2}, {1, 2, 3, 4}, {1, 2, 3, 4, 5}这是四个测试用例，请你给出他们的结果
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
    std::vector<std::vector<int>> cases = {{2}, {1, 2}, {1, 2, 3, 4}, {1, 2, 3, 4, 5}};
    std::vector<int> expected = {0, 2, 6, 6};

    std::vector<int> llm_outs_1 = {2, 2, 6, 6};
    std::vector<int> llm_outs_2 = {2, 2, 6, 6};
    std::vector<int> llm_outs_3 = {0, 2, 6, 6};
    std::vector<int> llm_outs_4 = {2, 2, 6, 6};


    for (int i = 0; i < cases.size(); i++) {
        auto numbers = cases[i];
        int result = add(numbers);

        assert(result == expected[i]);
        assert(result == llm_outs_1[i]);
        assert(result == llm_outs_2[i]);
        assert(result == llm_outs_3[i]);
    }
    //正确率：81.25%
    //分析：GPT的逻辑将第一个位置理解为数组0号下标，所以将第一个元素算入偶数
    return 0;
}
