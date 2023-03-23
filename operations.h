#ifndef OPERATIONS_H
#define OPERATIONS_H

#define ERROR 987654e-99

 struct operation {
     double num_1;
     double num_2;
     char* operation;
 };

double calculate(struct operation calculation);

#endif // OPERATIONS_H
