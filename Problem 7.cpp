#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
#include<math.h>
using namespace std;

struct note{
	int num;
	int step;
};
queue<note> q;

bool is_Prime(int num){
	for(int i=2;i<=sqrt(num);i++){
		if(num%i==0)
			return false;
	}
	return true;
}

int bfs(int num1,int num2){
	note a = {num1,0};
	q.push(a);
	bool vis[10000];
	memset(vis,0,sizeof(vis));
	vis[num1]=1;
	while(!q.empty()){
		note temp = q.front();
		q.pop();
		if(temp.num == num2) return temp.step;
		int t1,t2,t3,t4;
		t4 = temp.num%10;
		t3 = (temp.num/10)%10;
		t2 = (temp.num/100)%10;
		t1 = temp.num/1000;
		// different treament accroding to bits
		int num3 = 0;
		note res = {0,0};
		for(int i=1;i<=9;){
			num3 = t1*1000+t2*100+t3*10+t4+i;
			if(is_Prime(num3)&&vis[num3]==0){
				res ={num3,temp.step+1};
				q.push(res);
				vis[num3]==1;
			}
			i+=2;
		}
		for(int i=0;i<=9;i++){
			num3 = t1*1000+t2*100+i*10+t4;
			if(is_Prime(num3)&&vis[num3]==0){
				res = {num3,temp.step+1};
				q.push(res);
				vis[num3]==1;
			}
		}
		for(int i=0;i<=9;i++){
			num3 = t1*1000+i*100+t3*10+t4;
			if(is_Prime(num3)&&vis[num3]==0){
				res = {num3,temp.step+1};
				q.push(res);
				vis[num3]==1;
			}
		}
		for(int i=1;i<=9;i++){
			num3 = i*1000+t2*100+t3*10+t4;
			if(is_Prime(num3)&&vis[num3]==0){
				res = {num3,temp.step+1};
				q.push(res);
				vis[num3]==1;
			}
		}
	}
	return -1;
}

int main(){
	int n,e[100][2]={0};
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&e[i][0],&e[i][1]);
	}
	
	for(int i=0;i<n;i++){
		int pround = bfs(e[i][0],e[i][1]);
		if(pround!=-1){
			cout<<pround<<endl;
		}
		else{
			cout<<"Impossible"<<endl; 
		}
	}
	return 0;
} 
