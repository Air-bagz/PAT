#include<iostream>
#include<string>
using namespace std;
string s;
bool isIPv4(string IP)
{
	int IPSize=IP.size(),index=0,okStep=0;	//���ڼ�¼�Ϸ��Ķ�
	//ɨ���ַ�������ҪѰ�ҵ�������4���Ϸ��Ķ�
	while(index<IPSize)
	{
		string tempStr="";
		while (index<IPSize && IP[index]!='.')
		{
			//�ж��Ƿ�������
			if (isdigit(IP[index])) 
			{
				tempStr+=IP[index++];
			}
			else 
			{
				return false;
			}
		}
		//�Ƿ�Ϊ�ա����ȴ���1����ʼ�ַ��Ƿ���'0'�����ȴ���3������255
		if (tempStr.size()==0 || (tempStr.size()>1 && tempStr[0]=='0') || tempStr.size()>3 || tempStr>"255") 
		{
			return false;
		}
		okStep+=1;	//�Ϸ��Ķ�����
		index+=1; 
	 } 
	 return IP[index-1]!='.' && okStep==4;		//IPv4���ĸ��� 
}
int main()
{
    cin >> s;
    if (isIPv4(s)) printf("YES");
    else printf("NO");
    return 0;
}
