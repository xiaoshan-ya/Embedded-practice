#include <iostream>
#include <cassert>
#include <string>
#include <vector>

/**
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
    这是一个程序的功能说明注释
 * 1001, 21, 111, 22, 1111这是五个测试用例输入，请你分别得到他们的输出
 */

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

int main() {
    std::vector<int> cases = {1001, 21, 111, 22, 1111};
    std::vector<std::string> expected = {"10", "11", "11", "100", "100"};

    std::vector<std::string> llm_outs_1 = {"1001", "11", "11", "100", "1001"};
    std::vector<std::string> llm_outs_2 = {"1", "110", "110", "10", "1000"};
    std::vector<std::string> llm_outs_3 = {"10", "110", "110", "10", "100"};

    for (int i = 0; i < cases.size(); i++) {
        int N = cases[i];
        std::string result = solve(N);

        assert(result == expected[i]);
        assert(result == llm_outs_1[i]);
        assert(result == llm_outs_2[i]);
        assert(result == llm_outs_3[i]);
    }
    //正确率33.3%
    //分析：GPT无法正确理解程序
    return 0;
}
