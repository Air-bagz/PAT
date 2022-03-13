#include<stdio.h>
#include<math.h>
bool isPrime(int n)
{
    for (int i=2; i<=int(sqrt(n)); i++)
        if (n % i==0)    return false;
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=n/2; i>=2; i--)
    {
        if (isPrime(i)&&isPrime(n-i))
        {
            printf("%d\n%d",i,n-i);
            return 0;
        }
    }
    return 0;
}
