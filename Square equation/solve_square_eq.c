//! @file solve_square_eq.c
/*! \mainpage Quadratic equation
 *
 * Hello)) This program solves the square equation.
 * - solve_square_eq.c
 */

#include "sqeq.h"

//------------------------------------------------------------------------------
//! Main - Main function. Works in two modes: normal and ghost. In normal mode
//! the quadratic is solved, in ghost the functions quad_equation, is equal and
//! moreless are checked.
//! @return - return exit code
//------------------------------------------------------------------------------

int main() {
    int num_root = -1;      //количество корней
    int read_char = 0;      //количество считанных символов
    char* read_str = calloc(100, sizeof(char));
    double a = NAN, b = NAN, c = NAN, x1 = 0.0, x2 = 0.0;     //коэффициенты и корни
    printf("Enter the coefficients of the quadratic equation a, b, c \n");
    printf("separeted by a space, respectively: ");

    for (int i = 0; i < 99; i++) {
        read_char = 0;

        scanf("%s", read_str);
        read_char += sscanf(read_str, "%lf", &a);
        scanf("%s", read_str);
        read_char += sscanf(read_str, "%lf", &b);
        scanf("%s", read_str);
        read_char += sscanf(read_str, "%lf", &c);

        if (read_char == 3) {
            num_root = quad_equation(a, b, c, &x1, &x2);
            break;
        }
        else {
            printf("\nTry again.\n");
            printf("Enter the coefficients of the quadratic equation a, b, c \n");
            printf("separeted by a space, respectively: ");
            continue;
        }

        break;
    }

    if (num_root >= 0) {
        switch (num_root) {
            case ROOT_INFINIT:
                printf("There are infinite roots.\n");
                break;
            case ROOT_ZERO:
                printf("There are no roots.\n");
                break;
            case ROOT_ONE:
                printf("There is one root: x = %lg\n", x1);
                break;
            case ROOT_TWO:
                printf("There are two roots: x1 = %lg, x2 = %lg\n", x1, x2);
                break;
            default:
                printf("Unknown error\n");
                break;
        }
    } else {
        switch (num_root) {
            case SS_ERROR_SAME_ROOTS:
                printf("The same addresses of variables x1 and x2 ");
                printf("are sent to the quad_equation function\n");
                break;
            case SS_ERROR_NULL_IN:
                printf("In the 'quad_equation' function NULL is passed to the variable address");
                break;
            case SS_ERROR_NAN_OUT:
                printf("When the 'quad_equation' function is running, the variables x1 and x2 are set to NAN");
                break;
            case C_ERROR_NULL_IN:
                printf("In the 'compare' function NULL is passed to the variable address");
                break;
            default:
                printf("Unknown error\n");
                break;
        }
    }
    return 0;
}
