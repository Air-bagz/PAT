#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    {
        int pos1=s.find(s[i]);
        int pos2=s.find(s[i],pos1+1);
        if (pos1!=-1 && pos2==-1)
        {
            cout<<s[i];
            return 0;
        }
    }
    printf("-1");
    return 0;
}
