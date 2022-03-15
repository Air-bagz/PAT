//gcd(a,b)=gcd(a,a%b)
//gcd(a,0)=a
#include<stdio.h>
int gcd(int a, int b)
{
    if (b==0)  return a;
    else return gcd(b,a % b);
}
int main()
{
    int A,B;
    scanf("%d %d",&A,&B);
    printf("%d",A/gcd(A,B)*B);		// A*B/gcd(A,B) ¿ÉÄÜÒç³ö 
    return 0;
}
