/**************************************
  >File: int to string
  >Author: PengKai
  >Date: 2018-10-09
**************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void inttostring(int);
int main() {
	int num=-124213;
	inttostring(num);
	system("pause");
	return -1;
}

void inttostring(int num) {
	string s = "";
	int n = abs(num);
	while (n != 0) {
		s += '0' + n % 10;//‘0’作为起始，除10得到个位的值
		n /= 10;
	}
	reverse(s.begin(),s.end());
	if (num < 0)
		s = '-' + s;
	cout << s;	
}
