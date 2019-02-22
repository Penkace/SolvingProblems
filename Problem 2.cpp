#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
#define N 99999999
using namespace std;
struct Note{
	int x;
	int s;
	//note(int xx,int ss):x(xx),s(ss){}
}; 
int main(){
	bool vis[51];
	memset(vis,0,sizeof(vis));
	int e[51][51]={0};
	queue<Note>q;
	int n,m,start,end,c,b;
	scanf("%d %d %d %d",&n,&m,&start,&end);
	//初始化邻接矩阵 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				e[i][j]=0;
			}
			else{
				e[i][j]=N;
			}
				
		}
	}
	//为邻接矩阵赋值，无向图，所以通路就为1，不考虑权重的情况找最短路径，m为边数 
	for(int i=1;i<=m;i++){
		scanf("%d %d",&c,&b);
		e[c][b]=1;
		e[b][c]=1;
	}
	struct Note cstart={start,0};
	vis[start]=1;
	q.push(cstart);
	
	while(!q.empty()){
		struct Note a = q.front();
		q.pop();
		//如果达到了终点，就返回这个时候的最短距离 
		if(a.x==end){
			printf("%d",a.s);
			break;
		}
		//如果没有达到最短距离，则开始遍历其他的城市，逐一加入到队列中 
		for(int i=1;i<=n;i++){
			if(e[a.x][i]==1&&vis[i]==0){
				struct Note temp={i,a.s+1};
				q.push(temp);
			}
		} 
	}
	return 0;
}
