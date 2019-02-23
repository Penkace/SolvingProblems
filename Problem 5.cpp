#include<iostream>
#include<stdio.h>
#include<cstring>
#define inf 99999999
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int start[10],end[10],w[10];
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&start[i],&end[i],&w[i]);
	}
	int dis[10];
	memset(dis,inf,sizeof(dis));
	dis[1]=0;
	
	for(int i=1;i<n-1;i++){
		bool flag = 0;
		for(int j=1;j<=m;j++){
			if(dis[end[j]]>dis[start[j]]+w[j])
				dis[end[j]] = dis[start[j]]+w[j];
				flag = 1;
		}
		if(flag==0) break;
	}
	bool test=0;
	for(int i=1;i<=m;i++){
		if(dis[end[i]]>dis[start[i]]+w[i])
			test=1;
	}
	if(test==1) cout<<"此图有负环回路";
	else{
		for(int i=1;i<=n;i++)
			cout<<dis[i]<<" "; 
	}
	return 0;
}
