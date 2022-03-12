#include<iostream>
#include<string>
using namespace std;
string s;
bool isIPv4(string IP)
{
	int IPSize=IP.size(),index=0,okStep=0;	//用于记录合法的段
	//扫描字符串，需要寻找到连续的4个合法的段
	while(index<IPSize)
	{
		string tempStr="";
		while (index<IPSize && IP[index]!='.')
		{
			//判断是否是数字
			if (isdigit(IP[index])) 
			{
				tempStr+=IP[index++];
			}
			else 
			{
				return false;
			}
		}
		//是否为空、长度大于1且起始字符是否是'0'、长度大于3、超过255
		if (tempStr.size()==0 || (tempStr.size()>1 && tempStr[0]=='0') || tempStr.size()>3 || tempStr>"255") 
		{
			return false;
		}
		okStep+=1;	//合法的段自增
		index+=1; 
	 } 
	 return IP[index-1]!='.' && okStep==4;		//IPv4有四个段 
}
int main()
{
    cin >> s;
    if (isIPv4(s)) printf("YES");
    else printf("NO");
    return 0;
}
