#include <iostream>
#include <cassert>
#include <cmath>

/**
 * 模型：Chat-GPT3.5
 * prompt:
 * 1. 请解释以上代码
 * 2. 请将上面这段代码按照每一行的语义，完整地转换为C+＋的代码，要求逐行转换，并且保证实现功能不变，
 * 保证C++代码能够正常运行，并且请将判断结果部分换成使用assert函数
 */

int starts_one_ends(int n) {
    assert(n > 0 && "invalid inputs"); // Check if n is a positive integer
    if (n == 1) {
        return 1;
    } else {
        return 18 * static_cast<int>(pow(10, n - 2)); // Calculate the count of n-digit numbers
    }
}

void check(int (*candidate)(int)) {
    assert(candidate(1) == 1);
    assert(candidate(2) == 18);
    assert(candidate(3) == 180);
    assert(candidate(4) == 1800);
    assert(candidate(5) == 18000);
}

int main() {
    check(starts_one_ends);
    return 0;
}
