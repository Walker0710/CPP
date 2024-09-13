#include <stdio.h>
#include <math.h>

//normal approch
double solve(double a[], int n, double x) {
    double result = 0;

    for (int i = 0; i < n; i++) 
    result += a[i] * pow(x, i);  
    
    return result;
}

int main() {
    int n = 4;  
    double a[] = {1, 2, 3, 4};  // value of coeff
    double x = 2;  

    double result = solve(a, n, x);
    printf("ans from normay approch: P(%.2f) = %.2f\n", x, result);

    return 0;
}


//Horners Rule
double horners_rule(double a[], int n, double x) {
    double result = a[n-1];

    for (int i = n - 2; i >= 0; i--)
    result = a[i] + x * result;
    
    return result;
}

int main() {
    int n = 4;  
    double a[] = {1, 2, 3, 4};  
    double x = 2;

    double result = horners_rule(a, n, x);
    printf("ans from Horners Rule: P(%.2f) = %.2f\n", x, result);

    return 0;
}


// gcc Horners_Rule.c -o Horners_Rule -lm
// ./Horners_Rule