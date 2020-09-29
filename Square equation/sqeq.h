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

int quad_equation(double a, double b, double c, double* x1, double* x2);/*решает
 квадратное уравнение*/
int is_equal(double x, double y); //если равно 1, если не равно 0
int moreless(double x, double y); // -1, если x меньше y, 1, если x больше y;
void check_equation(); //проверяет guad_equation
void check_is_equal(); //проверяет is_equal
void check_moreless(); //проверяет moreless
int normal_mode(); //main в обычном режиме
int ghost_mode(); //main в режиме DEBAG
