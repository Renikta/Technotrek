#include <stdio.h>
#include <math.h>

#define EPS 0.00005

enum roots {
    ERROR = -1,
    ZERO,
    ONE,
    TWO
};

int quad_equation(double a, double b, double c, double* x1, double* x2); //решает квадратное уравнение и возращает количество корней
int is_equal(double x, double y); //сравнивает на равенство два числа и возращает резкльтат 0 или 1

int main() {
    int root = -1;      //количество корней
    double a, b, c, x1 = 0, x2 = 0;
    printf("Enter the coefficients of the quadratic equation a, b, c \n");
    printf("separeted by a space, respectively: ");

    if (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        root = quad_equation(a, b, c, &x1, &x2);
    }
    else {root = quad_equation(a, b, c, &x1, &x2);
        root = ERROR;
    }

    switch (root) {
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

int quad_equation(double a, double b, double c, double* x1, double* x2) {
    double dis = 0, sq = 0; //значение дискриминанта и корня из него
    int root = 0;

    if ((x1 == x2) || (x1 == NULL) || (x2 == NULL)) { //проверка указателей
            return ERROR;
    }

    if (is_equal(a, 0)) {
        if(is_equal(b, 0)) {
            root = 0;               //0  0  ?
        }
        else if (is_equal(c, 0)) {
            root = 1;               //0  1  0
        }
        else {
            root = 1;               //0  1  1
            *x1 = -c / b;
        }
    }
    else {
        if (is_equal(b, 0)) {
            if (is_equal(c, 0)) {
                root = 2;           //1  0  0
            }
            else {
                root = 2;           //1  0  1
                *x1 = sqrt(-c / a);
                *x2 = -*x1;
            }
        }
        else {
            if (is_equal(c, 0)) {
                root = 2;           //1  1  0
                *x2 = -b / a;
            }
            else {
                dis = b*b - 4*a*c;
                if (dis > 0) {
                    root = 2;       //1  1  1  Дискриминант > 0
                    sq = sqrt(dis);
                    *x1 = (-b + sq)/(2*a);
                    *x2 = (-b - sq)/(2*a);
                }
                else if (is_equal(dis, 0)) {
                    root = 2;       //1  1  1  Дискриминант = 0
                    *x1 = -b / (2*a);
                    *x2 = *x1;
                }
                else if (dis < 0) {
                    root = 0;       //1  1  1  Дискриминант < 0
                }
            }
        }
    }
    return root;
}

int is_equal(double x, double y) {
    if ((x == x) && (y == y)) {
        return x - y < EPS;
    }
    else {
        return ERROR;
    }
}
