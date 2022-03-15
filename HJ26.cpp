#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct alpha
{
    char ch;
    char actual;    //按大写存    0xDF    -32
    int order;
}alpha;
bool cmp_sort(alpha a,alpha b)
{
    if (a.actual==b.actual)    return a.order<b.order;
    else return a.actual<b.actual;
}
bool cmp_stable_sort(alpha a,alpha b)
{
    return a.actual<b.actual;
}
int main()
{
    char in[1010];
    scanf("%[^\n]",in);
    alpha s[1010];
    int len=0;
    for (int i=0; i<strlen(in); i++)
    {
        if ( (in[i]>='a'&&in[i]<='z')||(in[i]>='A'&&in[i]<='Z') )
        {
            s[len].ch=in[i];
            s[len].actual=in[i]&0xDF;
            s[len].order=i;
            len++;
        }
    }
    s[len].ch='\0';
    sort(s,s+len,cmp_sort);        //sort+多关键字判断
    //stable_sort(s,s+len,cmp_stable_sort);    //stable_sort+单关键字判断3
    //sort(s,s+len,cmp_stable_sort);        //sort+多关键字判断    则不行
    int k=0;
    
    for (int i=0; i<strlen(in); i++)
    {
        if ((in[i]>='a'&&in[i]<='z')||(in[i]>='A'&&in[i]<='Z'))
        {
            printf("%c",s[k].ch);
            k++;
        }
        else  printf("%c",in[i]);
    }
    
    return 0;
}
