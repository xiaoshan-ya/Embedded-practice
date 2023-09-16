#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

/**
 * 模型：Chat-GPT3.5
 * prompt:
 * 1. 请解释以上代码
 * 2. 请将上面这段代码按照每一行的语义，完整地转换为C+＋的代码，要求逐行转换，并且保证实现功能不变，
 * 保证C++代码能够正常运行，并且请将判断结果部分换成使用assert函数
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

/**
 *  Write a function that takes a string and returns True if the string
    length is a prime number or False otherwise
    Examples
    prime_length('Hello') == True
    prime_length('abcdcba') == True
    prime_length('kittens') == True
    prime_length('orange') == False
 * @param str
 * @return
 */
bool prime_length(const std::string& str) {
    int length = str.length();
    return is_prime(length);
}

void check(bool (*candidate)(const std::string&)) {
    assert(candidate("Hello") == true);
    assert(candidate("abcdcba") == true);
    assert(candidate("kittens") == true);
    assert(candidate("orange") == false);
    assert(candidate("wow") == true);
    assert(candidate("world") == true);
    assert(candidate("MadaM") == true);
    assert(candidate("Wow") == true);
    assert(candidate("") == false);
    assert(candidate("HI") == true);
    assert(candidate("go") == true);
    assert(candidate("gogo") == false);
    assert(candidate("aaaaaaaaaaaaaaa") == false);

    assert(candidate("Madam") == true);
    assert(candidate("M") == false);
    assert(candidate("0") == false);
}

int main() {
    check(prime_length);
    return 0;
}
