#include "sqeq.h"

const double EPSIL = 0.00005;

#define UNITTEST(function, operation, result) \
do {\
    if(!((function) operation (result))) \
        printf("%s Oops :( %s != %s %s\n", RED, #function, #result, RESET); \
    else \
        printf("%s Good job ;) %s \n", GREEN, RESET); \
} while(0);

int quad_equation(double a, double b, double c, double* x1, double* x2) {
    double dis = 0, sq = 0; //значение дискриминанта и корня из него
    int num_root = 0;

    if (x1 == x2) { //проверка указателей
        return SS_ERROR_SAME_ROOTS;
    } else if ((x1 == NULL) || (x2 == NULL)) {
        return SS_ERROR_NULL_IN;
    }

    if (compare(a, 0) == EQUAL) {
        if(!compare(b, 0)) {
            num_root = ROOT_INFINIT;               //0  0  ?
        }
        else if (compare(c, 0) == EQUAL) {
            num_root = ROOT_ONE;               //0  1  0
        }
        else {
            num_root = ROOT_ONE;               //0  1  1
            *x1 = -c / b;
        }
    }
    else {
        if (compare(b, 0) == EQUAL) {
            if (compare(c, 0) == EQUAL) {
                num_root = ROOT_TWO;           //1  0  0
                *x1 = 0;
                *x2 = 0;
            }
        else {
            if (compare(c , 0) == LESS) {
                num_root = ROOT_TWO;           //1  0  -1
                *x1 = sqrt(-c / a);
                *x2 = -*x1;
            }
            else
                num_root = ROOT_ZERO;           //1  0  1
            }
        }
        else {
            if (compare(c, 0) == EQUAL) {
                num_root = ROOT_TWO;           //1  1  0
                *x1 = 0;
                *x2 = -b / a;

            }
            else {
                dis = b*b - 4*a*c;
                if (compare(dis, 0) == MORE) {
                    num_root = ROOT_TWO;       //1  1  1  Дискриминант > 0
                    sq = sqrt(dis);
                    *x1 = (-b + sq) / (2*a);
                    *x2 = (-b - sq) / (2*a);
                }
                else if (compare(dis, 0) == EQUAL) {
                    num_root = ROOT_TWO;       //1  1  1  Дискриминант = 0
                    *x1 = -b / (2*a);
                    *x2 = *x1;
                }
                else if (compare(dis, 0) == LESS) {
                    num_root = ROOT_ZERO;       //1  1  1  Дискриминант < 0
                }
            }
        }
    }

    if (!(*x1 == *x1) || !(*x2 == *x2)) {
        return SS_ERROR_NAN_OUT;
    }
    return num_root;
}

int compare(double x, double y) {
    if ((x == x) && (y == y)) {
        if (x > y)
            if (x - y < EPSIL)
                return EQUAL;
            else
                return MORE;
        else
            if (y - x < EPSIL)
                return EQUAL;
            else
                return LESS;
    }
    else {
        return C_ERROR_NULL_IN;
    }
}

void check_equation() {
    printf("Tests to check the function of the quad_equation: \n");
    double x1 = 0, x2 = 0;
    UNITTEST(quad_equation(1, 1, 1, NULL, &x2), ==, SS_ERROR_NULL_IN);
    UNITTEST(quad_equation(1, 1, 1, &x1, NULL), ==, SS_ERROR_NULL_IN);
    UNITTEST(quad_equation(1, 1, 1, &x1, &x1), ==, SS_ERROR_SAME_ROOTS);
    UNITTEST(quad_equation(0, 0, 0, &x1, &x2), ==, ROOT_INFINIT);
    UNITTEST(quad_equation(0, 0, 1, &x1, &x2), ==, ROOT_INFINIT);
    UNITTEST(quad_equation(0, 1, 0, &x1, &x2), ==, ROOT_ONE);
    UNITTEST(x1, ==, 0);
    UNITTEST(quad_equation(0, 1, 1, &x1, &x2), ==, ROOT_ONE);
    UNITTEST(x1, ==, -1);
    UNITTEST(quad_equation(1, 0, 0, &x1, &x2), ==, ROOT_TWO);
    UNITTEST(x1, ==, 0);
    UNITTEST(x2, ==, 0);
    UNITTEST(quad_equation(1, 0, 1, &x1, &x2), ==, ROOT_ZERO);
    UNITTEST(quad_equation(1, 0, -4, &x1, &x2), ==, ROOT_TWO);
    UNITTEST(x1, ==, 2);
    UNITTEST(x2, ==, -2);
    UNITTEST(quad_equation(1, 1, 0, &x1, &x2), ==, ROOT_TWO);
    UNITTEST(x1, ==, 0);
    UNITTEST(x2, ==, -1);
    UNITTEST(quad_equation(2, 5, 2, &x1, &x2), ==, ROOT_TWO);
    UNITTEST(x1, ==, -0.5);
    UNITTEST(x2, ==, -2);
    UNITTEST(quad_equation(2, 4, 2, &x1, &x2), ==, ROOT_TWO);
    UNITTEST(x1, ==, -1);
    UNITTEST(x2, ==, -1);
    UNITTEST(quad_equation(2, 1, 2, &x1, &x2), ==, ROOT_ZERO);
}

void check_compare() {
    printf("Tests to check the function of the comparison: \n");
    UNITTEST(compare(NAN, NAN), ==, C_ERROR_NULL_IN);
    UNITTEST(compare(0, 0), ==, EQUAL);
    UNITTEST(compare(1, 0), ==, MORE);
    UNITTEST(compare(0, 1), ==, LESS);
    UNITTEST(compare(1.12, 1.11), ==, MORE);
    UNITTEST(compare(1.11, 1.12), ==, LESS);
    UNITTEST(compare(-1, -2), ==, MORE);
    UNITTEST(compare(-2, -1), ==, LESS);
    UNITTEST(compare(1, 0), ==, MORE);
    UNITTEST(compare(1, 0), ==, MORE);
    UNITTEST(compare(EPSIL, 2.0*EPSIL), ==, LESS);
    UNITTEST(compare(2.0*EPSIL, EPSIL), ==, MORE);
    UNITTEST(compare(EPSIL, EPSIL - 0.000001), ==, EQUAL);
    UNITTEST(compare(EPSIL - 0.000001, EPSIL), ==, EQUAL);
}
