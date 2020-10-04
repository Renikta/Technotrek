#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define RESET  "\033[0m"
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"

enum roots {
    ROOT_ZERO = 0,
    ROOT_ONE = 1,
    ROOT_TWO = 2,
    ROOT_INFINIT = 3
};

enum comparison {
    MORE = 1,
    EQUAL = 0,
    LESS = -1
};

enum error {
    SS_ERROR_SAME_ROOTS = -101,
    SS_ERROR_NULL_IN = -102,
    SS_ERROR_NAN_OUT = -103,
    C_ERROR_NULL_IN = -104
};


int quad_equation(double a, double b, double c, double* x1, double* x2);

//------------------------------------------------------------------------------
//! quad_equation - solves the square equation
//! @param [in] a - first coefficient
//! @param [in] b - second coefficient
//! @param [in] c - third coefficient
//! @param [out] x1, x2 -roots
//! @return - number of roots: 0, 1, 2 or infinity
//------------------------------------------------------------------------------

int compare(double x, double y);

//------------------------------------------------------------------------------
//! comparison - compares two numbers to each other
//! @param [in] x, y - numbers to be compared
//! @return - returns 0 if equal, 1 if x is greater than y, -1 if x is less than
//! y.
//------------------------------------------------------------------------------

void check_equation(); //проверяет guad_equation
void check_compare(); //проверяет morelessz
