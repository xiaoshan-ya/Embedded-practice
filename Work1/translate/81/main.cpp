#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

/**
 * 模型：Chat-GPT3.5
 * prompt:
 * 1. 请解释以上代码
 * 2. 请将上面这段代码按照每一行的语义，完整地转换为C+＋的代码，要求逐行转换，并且保证实现功能不变，
 * 保证C++代码能够正常运行，并且请将判断结果部分换成使用assert函数
 */

/*
 *     """It is the last week of the semester and the teacher has to give the grades
    to students. The teacher has been making her own algorithm for grading.
    The only problem is, she has lost the code she used for grading.
    She has given you a list of GPAs for some students and you have to write
    a function that can output a list of letter grades using the following table:
             GPA       |    Letter grade
              4.0                A+
            > 3.7                A
            > 3.3                A-
            > 3.0                B+
            > 2.7                B
            > 2.3                B-
            > 2.0                C+
            > 1.7                C
            > 1.3                C-
            > 1.0                D+
            > 0.7                D
            > 0.0                D-
              0.0                E


    Example:
    grade_equation([4.0, 3, 1.7, 2, 3.5]) ==> ['A+', 'B', 'C-', 'C', 'A-']
    """
 * */

std::vector<std::string> numerical_letter_grade(std::vector<double> grades) {
    assert(std::all_of(grades.begin(), grades.end(), [](double x) { return x >= 0.0 && x <= 4.0; }));

    std::vector<std::string> letter_grades;

    for (double score : grades) {
        if (score == 4.0) {
            letter_grades.push_back("A+");
        } else if (score > 3.7) {
            letter_grades.push_back("A");
        } else if (score > 3.3) {
            letter_grades.push_back("A-");
        } else if (score > 3.0) {
            letter_grades.push_back("B+");
        } else if (score > 2.7) {
            letter_grades.push_back("B");
        } else if (score > 2.3) {
            letter_grades.push_back("B-");
        } else if (score > 2.0) {
            letter_grades.push_back("C+");
        } else if (score > 1.7) {
            letter_grades.push_back("C");
        } else if (score > 1.3) {
            letter_grades.push_back("C-");
        } else if (score > 1.0) {
            letter_grades.push_back("D+");
        } else if (score > 0.7) {
            letter_grades.push_back("D");
        } else if (score > 0.0) {
            letter_grades.push_back("D-");
        } else {
            letter_grades.push_back("E");
        }
    }

    return letter_grades;
}

void check(std::vector<std::string> result, std::vector<std::string> expected_result) {
    assert(result == expected_result);
}

int main() {
    check(numerical_letter_grade({4.0, 3, 1.7, 2, 3.5}), {"A+", "B", "C-", "C", "A-"});
    check(numerical_letter_grade({1.2}), {"D+"});
    check(numerical_letter_grade({0.5}), {"D-"});
    check(numerical_letter_grade({0.0}), {"E"});
    check(numerical_letter_grade({1, 0.3, 1.5, 2.8, 3.3}), {"D", "D-", "C-", "B", "B+"});
    check(numerical_letter_grade({0, 0.7}), {"E", "D-"});

    return 0;
}