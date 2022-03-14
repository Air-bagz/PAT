//https://blog.nowcoder.net/n/d7d6762284f34065bdd4253345856053

#include<bits/stdc++.h>
#include<arpa/inet.h>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        struct sockaddr_in sa;
        printf("%s\n",inet_pton(AF_INET, s.c_str(), &(sa.sin_addr))?"YES":"NO");
    }
    return 0;
}
