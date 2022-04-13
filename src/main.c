#include <stdio.h>
#include <stdlib.h>

#include <quadraticFormula.h>
#include <completeTheSquare.h>
#include <factoring.h>
#include <common.h>

#define QF '1'
#define CTS '2'
#define F '3'

int main(void){
    char equation[MAX_BUF] = {};

    printf("Enter the equation you would like to solve (fmt: ax^2 + bx + c)\n");
    fgets(equation, MAX_BUF, stdin);
 
    printf("How would you like to solve this\n"
           "\t1. Quadratic Formula\n"
           "\t2. Completing the Square\n"
           "\t3. Factoring\n");

   switch(getchar()){
       case QF:
        qudratic_formula_solve(equation);
        break;
       case CTS:
        completing_square_solve(equation);
        break;
       case F:
        factoring_sovlve(equation);
        break;
       default:
        printf("That is not a valid option!\n");
        exit(EXIT_FAILURE);
   }

   return 0;
}