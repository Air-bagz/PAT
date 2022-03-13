#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int k;
    cin >> s >> k;
    string ans;
    ans=s.substr(0,k);
    cout << ans;
    return 0;
}
