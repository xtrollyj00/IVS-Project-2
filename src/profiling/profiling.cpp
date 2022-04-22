#include "../calculator/math/wmath.h"
#include <stdio.h>

int main(int argc, char* argv[]){

    Math math;

    double x_i = 0.0;
    double x_i_sqr = 0.0;
    int N = 0;
    double sum_x_i = 0.0;
    double sum_of_sqrs = 0.0;

    while(scanf("%lf", &x_i) == 1){
        N ++;
        sum_x_i = math.Add(sum_x_i, x_i);
        x_i_sqr = math.Power(x_i, 2);
        sum_of_sqrs = math.Add(sum_of_sqrs, x_i_sqr);
    }

    double x_ = math.Divide(sum_x_i, N);
    double x_sqr = math.Power(x_, 2);
    double Nx_sqr = math.Multiply(N, x_sqr);

    double in_brac = math.Subtract(sum_of_sqrs, Nx_sqr);
    double N_dec = math.Subtract(N, 1);
    double under_sqrt = math.Divide(in_brac, N_dec);

    double s = math.Root(under_sqrt, 2);

    printf("%lf\n",s);

    return 0;
}
