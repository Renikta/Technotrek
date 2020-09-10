//! @file solve_square_eq.c
/*! \mainpage Quadratic equation
 *
 * This program solves the square equation.
 * - solve_square_eq.c
 */

#include <stdio.h>
#include <math.h>

#define EPS 0.00005

#define UNITTEST(number_one, operation, number_two) \
{\
    if(!((number_one) operation (number_two))) \
        printf("Fail"); \
    else \
        printf("True"); \
}

/*#ifdef UNITTEST(3, '+', 7) {
    printf("Yes");
}
#else
    printf("No");
#endif */

enum roots {
    ERROR = -1,
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    INFINIT = 3
};

int quad_equation(double a, double b, double c, double* x1, double* x2); //решает квадратное уравнение и возращает количество корней
int is_equal(double x, double y); //сравнивает на равенство два числа и возращает результат 0 или 1


//------------------------------------------------------------------------------
//! Main - user wrapper of solve square equation function
//! @return - return exit code
//------------------------------------------------------------------------------

int main() {
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
//------------------------------------------------------------------------------
//! quad_equation - solves the square equation
//! @param [in] a - first coefficient
//! @param [in] b - second coefficient
//! @param [in] c - third coefficient
//! @param [out] x1 -root
//! @param [out] x2 - root
//! @return - number of roots or error
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
            }
            else {
                num_root = 2;           //1  0  1
                *x1 = sqrt(-c / a);
                *x2 = -*x1;
            }
        }
        else {
            if (is_equal(c, 0)) {
                num_root = 2;           //1  1  0
                *x2 = -b / a;
            }
            else {
                dis = b*b - 4*a*c;
                if (dis > 0) {
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
                else if (dis < 0) {
                    num_root = 0;       //1  1  1  Дискриминант < 0
                }
            }
        }
    }
    return num_root;
}

//------------------------------------------------------------------------------
//! is_equal - compares two numbers for equality in some neighborhood
//! @param [in] x - first number
//! @param [in] y - second number
//! @return - returns 0 or 1 depending on the result, or an error if the number is bad.
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
