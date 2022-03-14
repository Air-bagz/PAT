#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        unordered_map<string, int> mp;
        vector<string> name(n);
        string s;
        for(int i = 0; i < n; i++){ 
            cin >> s;
            mp[s] = 0; //在map中记录候选人，设置票数为0
            name[i] = s; //记录候选人的名字
        }
        cin >> n;
        for(int i = 0; i < n; i++){ 
            cin >> s;
            //if(mp.find(s) != mp.end()) //只对map中有的候选人计票
                mp[s]++;
        }
        int valid = 0; //统计合法票数
        for(int i = 0; i < name.size(); i++){ //遍历候选人的名字，输出其票数
            cout << name[i] << " : " << mp[name[i]] << endl;
            valid += mp[name[i]];
        }
        cout << "Invalid : " << n - valid << endl; //总票数减去合法票数就是非法票数
    }
}
