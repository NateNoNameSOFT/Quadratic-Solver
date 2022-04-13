#include <quadraticFormula.h>

#define DISPLAY_STEP(str)\
    printf(BLU"\n");\
    printf("\t---\n");\
    printf(str);\
    printf("\t---\n");\
    printf("\n"RESET);

void qudratic_formula_solve(char *equation){
    DISPLAY_STEP("Put in quadratic formula\n");

    struct{
        float a;
        float b;
        float nb;
        float c;
    } parsed_qf;

    sscanf(equation, "%fx^2 %fx %f", &parsed_qf.a, &parsed_qf.b, &parsed_qf.c);

    parsed_qf.nb = parsed_qf.b * -1;

    DEBUG("a = %f\n"
           "b = %f\n"
           "c = %f\n", parsed_qf.a, parsed_qf.b, parsed_qf.c);

    printf("         _________\n"
           "     -b±√b^2 - 4ac\n"
           "x =  -------------\n"
           "            2a    \n");

    printf("                __________________________________\n"
           "     %f±√%f^2 - 4*%f*%f\n"
           "x =  ---------------------------------------------\n"
           "                      2*%f    \n", parsed_qf.nb, parsed_qf.b, parsed_qf.a, parsed_qf.c, parsed_qf.a);

    struct {
        float topSolvePlus;
        float answerPlus;
        float topSolveMinus;
        float answerMinus;
        float sqrtDiscrim;
        float discrim;
        float powb;
        float s4ac;
        float s2a;
    } solved_qf;

    DISPLAY_STEP("Get the power of b\n");

    solved_qf.powb = pow(parsed_qf.b, 2);

    printf("                __________________________________\n"
           "     %f±√%f - 4*%f*%f\n"
           "x =  ---------------------------------------------\n"
           "                      2*%f    \n", parsed_qf.nb, solved_qf.powb, parsed_qf.a, parsed_qf.c, parsed_qf.a);

    DISPLAY_STEP("Solve 4 * a * c\n");

    solved_qf.s4ac = 4 * parsed_qf.a * parsed_qf.c;

    printf("                __________________________________\n"
           "     %f±√%f - %f\n"
           "x =  ---------------------------------------------\n"
           "                      2*%f    \n", parsed_qf.nb, solved_qf.powb, solved_qf.s4ac, parsed_qf.a);

    DISPLAY_STEP("Solve 2 * a\n");

    solved_qf.s2a = 2 * parsed_qf.a;

    printf("                __________________________________\n"
           "     %f±√%f - %f\n"
           "x =  ---------------------------------------------\n"
           "                      %f    \n", parsed_qf.nb, solved_qf.powb, solved_qf.s4ac, solved_qf.s2a);

    DISPLAY_STEP("Finish Solving Discriminant\n");

    solved_qf.discrim = solved_qf.powb - solved_qf.s4ac;

    printf("                __________________________________\n"
           "     %f±√%f\n"
           "x =  ---------------------------------------------\n"
           "                      %f    \n", parsed_qf.nb, solved_qf.discrim, solved_qf.s2a);

    if(solved_qf.discrim < 0){
        printf("The discriminant is imaginary, answer shown above\n");
        exit(EXIT_SUCCESS);
    }

    DISPLAY_STEP("Get the squareroot of the discriminant\n");

    solved_qf.sqrtDiscrim = sqrt(solved_qf.discrim);

    printf("     %f±%f\n"
           "x =  ---------------------------------------------\n"
           "                 %f    \n", parsed_qf.nb, solved_qf.sqrtDiscrim, solved_qf.s2a);

    DISPLAY_STEP("Solve For X-intercept (Plus)\n");

    solved_qf.topSolvePlus = parsed_qf.nb + solved_qf.sqrtDiscrim;

    printf("               %f\n"
           "x =  -----------------------\n"
           "               %f    \n", solved_qf.topSolvePlus, solved_qf.s2a);

    solved_qf.answerPlus = solved_qf.topSolvePlus/solved_qf.s2a;

    printf("X = %f\n", solved_qf.answerPlus);

    DISPLAY_STEP("Solve For X-intercept (Minus)\n");

    solved_qf.topSolveMinus = parsed_qf.nb - solved_qf.sqrtDiscrim;

    printf("               %f\n"
           "x =  -----------------------\n"
           "               %f    \n", solved_qf.topSolveMinus, solved_qf.s2a);

    solved_qf.answerMinus = solved_qf.topSolveMinus/solved_qf.s2a;

    printf("X = %f\n", solved_qf.answerMinus);

    printf(RED"Answer: X = %f, X = %f\n", solved_qf.answerPlus, solved_qf.answerMinus);
}