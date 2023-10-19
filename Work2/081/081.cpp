#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

/**
 * 模型：Bing
 * prompt:
 * 1. 请理解代码
 * 2. 这是五个约束，第i约束是对于main函数中测试数组cases[i]，
 * 即size为cases[i]的数组长度，x0=cases[i][0],x1=cases[i][1]，
 * 请你为每个约束都生成关于numerical_letter_grade函数的测试用例，并且补全在main函数中的for语句中
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

int main() {
    std::vector<std::vector<double>> cases = {

            //对于X0=0的情况，模型无法正确识别约束，进行手动修改

            {1.0, 0.0},  // Constraints1
            {0.0, 0.0},  // Constraints2
            {0.0, 4.0},  // Constraints3
            {1.0, 0.0},  // Constraints4
            {1.0, 0.0}   // Constraints5
    };

    std::vector<std::vector<std::string>> expected_results = {
            {"D", "E"},         // Constraints1
            {"E", "E"},        // Constraints2
            {"E", "A+"},        // Constraints3
            {"D", "E"},        // Constraints4
            {"D", "E"}         // Constraints5
    };

    for (int i = 0; i < cases.size(); ++i) {
        std::vector<double> test_case = cases[i];
        std::vector<std::string> expected_result = expected_results[i];

        // Call the function and get the result
        std::vector<std::string> result = numerical_letter_grade(test_case);

        // Check the result
        assert(result == expected_result);
    }

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

