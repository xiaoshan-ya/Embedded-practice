#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

/**
 *  prompt by ChatGPT3.5
 *  It is the last week of the semester and the teacher has to give the grades
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
    这是一个程序的功能说明注释

 *{1.0, 0.0},
  {0.0, 0.0},
  {0.0, 4.0},
  这是三个测试用例输入，请你给出他们的输出
 */

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
    std::vector<std::vector<double>> cases = {
            {1.0, 0.0},  // Constraints1
            {0.0, 0.0},  // Constraints2
            {0.0, 4.0},  // Constraints3
    };
    std::vector<std::string> result;

    std::vector<std::vector<std::string>> llm_outs_1 = {{"D+", "D-"}, {"D-", "D-"}, {"D-", "A+"}};
    std::vector<std::vector<std::string>> llm_outs_2 = {{"D+", "E"}, {"E", "E"}, {"E", "A+"}};
    std::vector<std::vector<std::string>> llm_outs_3 = {{"D+", "D-"},{"E", "E"},{"E", "A+"}};

    std::vector<std::vector<std::string>> expected_results = {
            {"D", "E"},
            {"E", "E"},
            {"E", "A+"},
    };
    for (auto i = 0; i < cases.size(); i++) {
        std::vector<double> test_case = cases[i];
        std::vector<std::string> result = numerical_letter_grade(test_case);
        std::cout << i << std::endl;
        assert(result == expected_results[i]);
        assert(result == llm_outs_1[i]);
        assert(result == llm_outs_2[i]);
        assert(result == llm_outs_3[i]);
    }

    // 正确率为44.4%
    // 原因：无法正确判断>的条件，如将1.0 > 1.0判断成true，但实际上是false,LLM无法判断边界条件

    return 0;
}
