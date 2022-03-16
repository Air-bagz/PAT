#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int index,value,maxindex=-1;
    map<int,int> mp;
    for (int i=1; i<=n; i++)
    {
        scanf("%d %d",&index,&value);
        mp[index]+=value;
        if (index>maxindex)    maxindex=index;
    }
    /*
    for (int i=0; i<=maxindex; i++)
    {
        if (mp[i]>0)
            printf("%d %d\n",i,mp[i]);    //不可以
    }    
    */
    //for(auto it : mp) cout << it.first << " " << it.second <<endl;    //可以
    for (map<int,int>::iterator it=mp.begin(); it!=mp.end(); it++)
        printf("%d %d\n",it->first,it->second);    //可以
    return 0;
}
