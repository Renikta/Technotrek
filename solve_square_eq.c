#include <stdio.h>
#include <math.h>

int quad_equation(double a, double b, double c, double* x1, double* x2);
int is_equal(double x, double y);

int main() {
    double a, b, c, x1 = 0, x2 = 0;
    printf("Enter the coefficients of the quadratic equation a, b, c \n");
    printf("separeted by a space, respectively: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    quad_equation(a, b, c, &x1, &x2); 
    
    return 0;
}

int quad_equation(double a, double b, double c, double* x1, double* x2) {
    double dis = 0, sq = 0; 
    int n = 0;
    
    if (is_equal(a, 0)) {
        if(is_equal(b, 0)) {
            n = 0;
            printf("There are no roots.\n");
        }
        else if (is_equal(c, 0)) {
            n = 1;
            printf("There is one root: x = %.2f \n", *x1);   
        } 
        else {
            n = 1;
            *x1 = -c / b;
            printf("There is one root: x = %.2f \n", *x1);
        }
    } 
    else {
        if (is_equal(b, 0)) {
            if (is_equal(c, 0)) {
                n = 2;
                printf("There are two identical roots: x1 = x2 = %.2f \n", *x1);
            }
            else {
                n = 2;
                *x1 = sqrt(-c / a);
                *x2 = -*x1;
                printf("There are two roots: x1 = %.2f, x2 = %.2f \n", *x1, *x2);
            }
        } 
        else { 
            n = 2;
            if (is_equal(c, 0)) {
                *x2 = -b / a;
                printf("There are two roots: x1 = %.2f, x2 = %.2f \n", *x1, *x2);
            }
            else {
                dis = b*b - 4.0*a*c;
                if (dis > 0) {
                    sq = sqrt(dis);
                    *x1 = (-b + sq)/(2.0*a);
                    *x2 = (-b - sq)/(2.0*a);
                    printf("There are two roots: x1 = %.2f, x2 = %.2f \n", *x1, *x2);
                } 
                else if (is_equal(dis, 0)) {
                    *x1 = -b / (2*a);
                    printf("There are two indentical roots: x1 = x2 = %.2f \n", *x1);
                }
                else if (dis < 0) {
                    n = 0;
                    printf("There are no roots.");
                }
            }
        }
    }
    return n;
}

int is_equal(double x, double y) {
    return x-y < 0.00005 ;
}
