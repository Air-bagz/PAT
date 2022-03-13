//应该用哈希,练习STL
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    char s1[200],t1[200];
    while (scanf("%s\n%s\n",s1,t1)!=EOF)		//把\n都去掉也可以 
    {
        string s,t,tmp;
        s=s1;    t=t1;
        bool flag=true;
        for (int i=0; i<s.size(); i++)
            if (t.find(tmp=s[i])==-1)    
            {
                printf("false\n");
                flag=false;
                break;
            }
        if (flag) printf("true\n");
    }
    return 0;
}
