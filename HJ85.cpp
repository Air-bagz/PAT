//O(n^3)
#include<iostream>
#include<string>
using namespace std;
bool huiwen(string s)
{
    for (int i=0; i<(s.size()/2); i++)
        if (s[i]!=s[s.size()-1-i])    return false;
    return true;
}
int main()
{
    string s;
    cin >> s;
    int ans=-1;
    for (int i=0; i<s.size(); i++)    //起始位置[i]
    {
        for (int j=1; j<=(s.size()-i); j++)    //长度j
            if (huiwen(s.substr(i,j))) 
            {
                int len=j;
                if (len>ans)    ans=len;
            }
    }
    printf("%d",ans);
    return 0;
}
