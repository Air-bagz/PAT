#include<stdio.h>
const double eps=1e-5;
double f(double x)
{
    return x*x*x;
}
int main()
{
    double x;
    scanf("%lf",&x);
    double left=-20,right=20,mid;
    while ((right-left)>eps)
    {
        mid=(left+right)/2.0;
        if (f(mid)>x)    right=mid;
        else left=mid;
    }
    printf("%.1f",mid);
    return 0;
}
