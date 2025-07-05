/*
Arithmetic Operators
Problem Statement:
Write a program that computes a complex arithmetic expression provided by the user. The expression can include addition, subtraction, multiplication, and division, and must be evaluated following the correct order of operations (PEMDAS/BODMAS).

Description:
The program should take a string input representing the arithmetic expression. It should parse the expression and compute the result accurately. The expression can have nested parentheses, and the program must handle them correctly.

Input Format:

A single string representing the arithmetic expression.
Output Format:

A single number which is the result of the evaluated expression.
Sample Input:
(2+3) * (5-2)
Sample Output:
15
*/

#include <iostream>
#include <string>
#include "exprtk.hpp"  

int main() {
    std::string expression;
    std::cout<<"Input : ";
    std::getline(std::cin, expression);

    typedef exprtk::expression<double> expression_t;
    typedef exprtk::parser<double> parser_t;

    expression_t expr;
    parser_t parser;

    if (parser.compile(expression, expr)) {
        std::cout << expr.value() << std::endl;
    } else {
        std::cout << "Invalid expression." << std::endl;
    }

    return 0;
}