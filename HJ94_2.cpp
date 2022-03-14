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
            mp[s] = 0; //��map�м�¼��ѡ�ˣ�����Ʊ��Ϊ0
            name[i] = s; //��¼��ѡ�˵�����
        }
        cin >> n;
        for(int i = 0; i < n; i++){ 
            cin >> s;
            if(mp.find(s) != mp.end()) //ֻ��map���еĺ�ѡ�˼�Ʊ
                mp[s]++;
        }
        int valid = 0; //ͳ�ƺϷ�Ʊ��
        for(int i = 0; i < name.size(); i++){ //������ѡ�˵����֣������Ʊ��
            cout << name[i] << " : " << mp[name[i]] << endl;
            valid += mp[name[i]];
        }
        cout << "Invalid : " << n - valid << endl; //��Ʊ����ȥ�Ϸ�Ʊ�����ǷǷ�Ʊ��
    }
}
/*
ʱ�临�Ӷȣ�O(n+m)������mmmΪ��ѡ��������nnnΪͶƱ����������Ҫ�����������к�ѡ�˺�Ͷ��Ʊ����unordered_map�Ĳ���ÿ�ζ���O(1)O(1)O(1)
�ռ临�Ӷȣ�O(m)����¼��ѡ�˵Ĺ�ϣ���Ϊ��ѡ������
*/
