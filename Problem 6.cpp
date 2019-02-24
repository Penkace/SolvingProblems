#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

//long long 表示19位 
int main(){
	int n;
	long long m = 1;
	scanf("%d",&n);
	queue<long long> q;
	q.push(m);
	while(!q.empty()){
		long long temp = q.front();
		q.pop();
		if(temp%n==0){
			cout<<temp;
			break;
		}
		long long temp1 = temp*10;
		long long temp2 = temp*10+1;
		q.push(temp1);
		q.push(temp2);
		if(temp1<0||temp2<0)
			cout<<"不存在"<<endl; 
	}
	return 0;	
} 
