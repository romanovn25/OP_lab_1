#include "operations.h"

#include <iostream>
#include <math.h>
double calculate(struct operation calculation)
{
    double res = 0;
    std::string operation = calculation.operation;
    if (operation == "+")
        res = calculation.num_1 + calculation.num_2;
    if (operation == "-")
        res = calculation.num_1 - calculation.num_2;
    if (operation == "*")
        res = calculation.num_1 * calculation.num_2;
    if (operation == "/" && calculation.num_2 != 0)
        res = calculation.num_1 / calculation.num_2;
    if (operation == "/" && calculation.num_2 == 0)
        res = ERROR; //987654e-99
    if (operation == "cos")
        res = cos(calculation.num_1);
    if (operation == "sin")
        res = sin(calculation.num_1);
    if (operation == "tg")
        res = tan(calculation.num_1);
    if (operation == "ctg" && calculation.num_1 == 0)
        res = ERROR; //987654e-99
    if (operation == "ctg" && calculation.num_1 != 0)
        res = 1 / (tan(calculation.num_1));
    return res;
}


