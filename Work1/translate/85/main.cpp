#include <iostream>
#include <vector>
#include <cassert>

/**
 * 模型：Chat-GPT3.5
 * prompt:
 * 1. 请解释以上代码
 * 2. 请将上面这段代码按照每一行的语义，完整地转换为C+＋的代码，要求逐行转换，并且保证实现功能不变，
 * 保证C++代码能够正常运行，并且请将判断结果部分换成使用assert函数
 */

/*
 *  Given a non-empty list of integers lst. add the even elements that are at odd indices..


    Examples:
        add([4, 2, 6, 7]) ==> 2
    """
 * */
int add(const std::vector<int>& lst) {
    // Check if lst is not empty
    assert(!lst.empty() && "invalid inputs");

    int s = 0;
    for (int i = 1; i < lst.size(); i += 2) {
        if (lst[i] % 2 == 0) {
            s += lst[i];
        }
    }
    return s;
}

void check(int (*candidate)(const std::vector<int>&)) {
    // Check some simple cases
    assert(candidate({4, 88}) == 88);
    assert(candidate({4, 5, 6, 7, 2, 122}) == 122);
    assert(candidate({4, 0, 6, 7}) == 0);
    assert(candidate({4, 4, 6, 8}) == 12);
}

int main() {
    check(add);
    return 0;
}
