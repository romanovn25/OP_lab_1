#include "operations.h"

#include <iostream>
#include <math.h>
double calculate(struct operation calculation)
{
    double res = 0;
    std::string operation = calculation.operation;
    if (operation == "+")
        res = calculation.num_1 + calculation.num_2;
    else if (operation == "-")
        res = calculation.num_1 - calculation.num_2;
    else if (operation == "*")
        res = calculation.num_1 * calculation.num_2;
    else if (operation == "/" && calculation.num_2 != 0)
        res = calculation.num_1 / calculation.num_2;
    else if (operation == "/" && calculation.num_2 == 0)
        res = ERROR; //987654e-99
    else if (operation == "cos")
        res = cos(calculation.num_1);
    else if (operation == "sin")
        res = sin(calculation.num_1);
    else if (operation == "tg" && cos(calculation.num_1) != 0)
        res = tan(calculation.num_1);
    else if (operation == "tg" && cos(calculation.num_1) == 0)
        res = ERROR;
    else if (operation == "ctg" && sin(calculation.num_1) == 0)
        res = ERROR; //987654e-99
    else if (operation == "ctg" && sin(calculation.num_1) != 0)
        res = 1 / (tan(calculation.num_1));
    return res;
}


