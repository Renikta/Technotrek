//! @file solve_square_eq.c
/*! \mainpage Quadratic equation
 *
 * Hello)) This program solves the square equation.
 * - solve_square_eq.c
 */

#include "sqeq.h" /*HLH7DHU*/

//------------------------------------------------------------------------------
//! Main - Main function. Works in two modes: normal and ghost. In normal mode
//! the quadratic is solved, in ghost the functions quad_equation, is equal and
//! moreless are checked.
//! @return - return exit code
//------------------------------------------------------------------------------

int main() {
    int num_root = -1;      //количество корней
    double a, b, c, x1 = 0, x2 = 0;     //коэффициенты и корни
    printf("Enter the coefficients of the quadratic equation a, b, c \n");
    printf("separeted by a space, respectively: ");

    if (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        num_root = quad_equation(a, b, c, &x1, &x2);
    }
    else {num_root = quad_equation(a, b, c, &x1, &x2);
        num_root = ERROR;
    }

    switch (num_root) {
        case INFINIT:
            printf("There are infinite roots.\n");
            break;
        case ZERO:
            printf("There are no roots.\n");
            break;
        case ONE:
            printf("There is one root: x = %lg\n", x1);
            break;
        case TWO:
            printf("There are two roots: x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case ERROR:
            printf("Error\n");
            break;
        default:
            printf("Error\n");
    }
    return 0;
}
