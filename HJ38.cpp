//1    �����߶�0.5(��һ��)    0.25    0.125    0.0625    0.3125
//��ؾ���1(��һ��)    1+0.5*2    1+0.5*2+0.25*2    2.5+0.125*2    2.75+0.0625*2    
#include<stdio.h>
int main()
{
    double n,h[6],total[6];
    scanf("%lf",&n);
    h[0]=n;
    for (int i=1; i<=5; i++)    //�����
        h[i]=h[i-1]/2;
    total[1]=n;
    for (int i=2; i<=5; i++)
        total[i]=total[i-1]+h[i-1]*2;
    printf("%f\n%f",total[5],h[5]);
    return 0;
}
