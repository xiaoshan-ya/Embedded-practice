#include <iostream>
#include <cassert>
#include <string>

/**
 * 模型：Chat-GPT3.5
 * prompt:
 * 1. 请解释以上代码
 * 2. 请将上面这段代码按照每一行的语义，完整地转换为C+＋的代码，要求逐行转换，并且保证实现功能不变，
 * 保证C++代码能够正常运行，并且请将判断结果部分换成使用assert函数
 */

/*
 * Given a positive integer N, return the total sum of its digits in binary.

    Example
        For N = 1000, the sum of digits will be 1 the output should be "1".
        For N = 150, the sum of digits will be 6 the output should be "110".
        For N = 147, the sum of digits will be 12 the output should be "1100".

    Variables:
        @N integer
             Constraints: 0 ≤ N ≤ 10000.
    Output:
         a string of binary number
    """
 * */

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

void check(std::string (*candidate)(int)) {
    // Check some simple cases
    assert(candidate(1000) == "1");
    assert(candidate(150) == "110");
    assert(candidate(147) == "1100");

    // Check some edge cases that are easy to work out by hand
    assert(candidate(333) == "1001");
    assert(candidate(963) == "10010");
}

int main() {
    check(solve);
    return 0;
}
