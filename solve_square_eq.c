//! @file solve_square_eq.c
/*! \mainpage Quadratic equation
 *
 * Hello)) This program solves the square equation.
 * - solve_square_eq.c
 */

#include <stdio.h>
#include <math.h>

#define EPS    0.00005
#define RESET  "\033[0m"
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"

enum roots {
    ERROR = -100,
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    INFINIT = 3
};

#ifndef DEBAG
    #define MODE normal_mode();
#else
    #define MODE ghost_mode();
#endif

#define UNITTEST(function, operation, result) \
do {\
    if(!((function) operation (result))) \
        printf("%s Oops :( %s != %s %s\n", RED, #function, #result, RESET); \
    else \
        printf("%s Good job ;) %s \n", GREEN, RESET); \
} while(0);

/*#ifdef UNITTEST(3, '+', 7) {
    printf("Yes");HLH7DHU
}
#else
    printf("No");
#endif */

int quad_equation(double a, double b, double c, double* x1, double* x2);/*решает
 квадратное уравнение*/
int is_equal(double x, double y); //если равно 1, если не равно 0
int moreless(double x, double y); // -1, если x меньше y, 1, если x больше y;
void check_equation(); //проверяет guad_equation
void check_is_equal(); //проверяет is_equal
void check_moreless(); //проверяет moreless
int normal_mode(); //main в обычном режиме
int ghost_mode(); //main в режиме DEBAG

//------------------------------------------------------------------------------
//! Main - Main function. Works in two modes: normal and ghost. In normal mode
//! the quadratic is solved, in ghost the functions quad_equation, is equal and
//! moreless are checked.
//! @return - return exit code
//------------------------------------------------------------------------------

int main() {
    MODE;
    return 0;
}

int normal_mode() {
    int num_root = -1;      //количество корней
    double a, b, c, x1 = 0, x2 = 0;
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

int ghost_mode() {
    check_is_equal();
    check_equation();
    check_moreless();
    return 0;
}

//------------------------------------------------------------------------------
//! quad_equation - solves the square equation
//! @param [in] a - first coefficient
//! @param [in] b - second coefficient
//! @param [in] c - third coefficient
//! @param [out] x1, x2 -roots
//! @return - number of roots: 0, 1, 2 or infinity
//------------------------------------------------------------------------------

int quad_equation(double a, double b, double c, double* x1, double* x2) {
    double dis = 0, sq = 0; //значение дискриминанта и корня из него
    int num_root = 0;

    if ((x1 == x2) || (x1 == NULL) || (x2 == NULL)) { //проверка указателей
            return ERROR;
    }

    if (is_equal(a, 0)) {
        if(is_equal(b, 0)) {
            num_root = 3;               //0  0  ?
        }
        else if (is_equal(c, 0)) {
            num_root = 1;               //0  1  0
        }
        else {
            num_root = 1;               //0  1  1
            *x1 = -c / b;
        }
    }
    else {
        if (is_equal(b, 0)) {
            if (is_equal(c, 0)) {
                num_root = 2;           //1  0  0
                *x1 = 0;
                *x2 = 0;
            }
            else {

                if (moreless(c , 0) == -1) {
                num_root = 2;           //1  0  -1
                *x1 = sqrt(-c / a);
                *x2 = -*x1;
                }
                else
                    num_root = 0;       //1  0  1
            }
        }
        else {
            if (is_equal(c, 0)) {
                num_root = 2;           //1  1  0
                *x1 = 0;
                *x2 = -b / a;

            }
            else {
                dis = b*b - 4*a*c;
                if (moreless(dis, 0) == 1) {
                    num_root = 2;       //1  1  1  Дискриминант > 0
                    sq = sqrt(dis);
                    *x1 = (-b + sq)/(2*a);
                    *x2 = (-b - sq)/(2*a);
                }
                else if (is_equal(dis, 0)) {
                    num_root = 2;       //1  1  1  Дискриминант = 0
                    *x1 = -b / (2*a);
                    *x2 = *x1;
                }
                else if (moreless(dis, 0) == -1) {
                    num_root = 0;       //1  1  1  Дискриминант < 0
                }
            }
        }
    }

    if ((*x1 == NAN)  || (*x2 == NAN))
        return ERROR;
    return num_root;
}

//------------------------------------------------------------------------------
//! is_equal - compares two numbers for equality in some neighborhood
//! @param [in] x, y - nambers to be compared
//! @return - returns 1, if equal, 0, if not equal
//------------------------------------------------------------------------------

int is_equal(double x, double y) {
    if ((x == x) && (y == y)) {
        if (x > y)
            return x - y < EPS;
        else
            return y - x < EPS;
    }
    else {
        return ERROR;
    }
}
//------------------------------------------------------------------------------
//! moreless - compares two numbers to each other
//! @param [in] x, y - numbers to be compared
//! @return - returns 0 if equal, 1 if x is greater than y, -1 if x is less than
//! y.
//------------------------------------------------------------------------------

int moreless(double x, double y) {
    if ((x == x) && (y == y)) {
        if (x > y)
            if (x - y < EPS)
                return 0;
            else
                return 1;
        else
            if (y - x < EPS)
                return 0;
            else
                return -1;
    }
    else {
        return ERROR;
    }
}

void check_equation() {
    printf("Tests to check the function of the quad_equation: \n");
    double x1 = 0, x2 = 0;
    UNITTEST(quad_equation(1, 1, 1, NULL, &x2), ==, ERROR);
    UNITTEST(quad_equation(1, 1, 1, &x1, NULL), ==, ERROR);
    UNITTEST(quad_equation(0, 0, 0, &x1, &x2), ==, INFINIT);
    UNITTEST(quad_equation(0, 0, 1, &x1, &x2), ==, INFINIT);
    UNITTEST(quad_equation(0, 1, 0, &x1, &x2), ==, ONE);
    UNITTEST(x1, ==, 0);
    UNITTEST(quad_equation(0, 1, 1, &x1, &x2), ==, ONE);
    UNITTEST(x1, ==, -1);
    UNITTEST(quad_equation(1, 0, 0, &x1, &x2), ==, TWO);
    UNITTEST(x1, ==, 0);
    UNITTEST(x2, ==, 0);
    UNITTEST(quad_equation(1, 0, 1, &x1, &x2), ==, ZERO);
    UNITTEST(quad_equation(1, 0, -4, &x1, &x2), ==, TWO);
    UNITTEST(x1, ==, 2);
    UNITTEST(x2, ==, -2);
    UNITTEST(quad_equation(1, 1, 0, &x1, &x2), ==, TWO);
    UNITTEST(x1, ==, 0);
    UNITTEST(x2, ==, -1);
    UNITTEST(quad_equation(2, 5, 2, &x1, &x2), ==, TWO);
    UNITTEST(x1, ==, -0.5);
    UNITTEST(x2, ==, -2);
    UNITTEST(quad_equation(2, 4, 2, &x1, &x2), ==, TWO);
    UNITTEST(x1, ==, -1);
    UNITTEST(x2, ==, -1);
    UNITTEST(quad_equation(2, 1, 2, &x1, &x2), ==, ZERO);
}

void check_is_equal() {
    printf("Tests to check the function of the is_equal: \n");
    UNITTEST(is_equal(0, 0), ==, 1);
    UNITTEST(is_equal(1, 2), ==, 0);
    UNITTEST(is_equal(2, 1), ==, 0);
    UNITTEST(is_equal(0.1, 0.2), ==, 0);
    UNITTEST(is_equal(0.2, 0.1), ==, 0);
    UNITTEST(is_equal(EPS, 2*EPS), ==, 0);
    UNITTEST(is_equal(EPS, EPS-0.000001), ==, 1);
}

void check_moreless() {
    printf("Tests to check the function of the moreless: \n");
    UNITTEST(moreless(0, 0), ==, 0);
    UNITTEST(moreless(1, 0), ==, 1);
    UNITTEST(moreless(0, 1), ==, -1);
    UNITTEST(moreless(1.12, 1.11), ==, 1);
    UNITTEST(moreless(1.11, 1.12), ==, -1);
    UNITTEST(moreless(-1, -2), ==, 1);
    UNITTEST(moreless(-2, -1), ==, -1);
    UNITTEST(moreless(1, 0), ==, 1);
    UNITTEST(moreless(1, 0), ==, 1);
    UNITTEST(moreless(EPS, 2*EPS), ==, -1);
    UNITTEST(moreless(2*EPS, EPS), ==, 1);
    UNITTEST(moreless(EPS, EPS - 0.000001), ==, 0);
    UNITTEST(moreless(EPS - 0.000001, EPS), ==, 0);
}
