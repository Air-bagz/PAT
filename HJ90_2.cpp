#include<iostream>
using namespace std;
int main()
{
    int a1,a2,a3,a4;
    char c1,c2,c3;
    while(cin>>a1>>c1>>a2>>c2>>a3>>c3>>a4) {
        bool flag=((c1=='.')&&(c2=='.')&&(c3=='.'));
        if((a1>=0&&a1<=255) && (a2>=0&&a2<=255) &&(a3>=0&&a3<=255)&& (a4>=0&&a4<=255)&& flag) {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
