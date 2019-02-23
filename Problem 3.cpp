/*********************************
	>File Name: Application of Dijkstra Algorithm
	>Author: PengKai
	>Date: 2019-02-23 Saturday 20:44 
*********************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#define inf 666
using namespace std;

int main(){
	int e[10][10],dis[10];
	bool vis[10];
	memset(vis,0,sizeof(vis));
	int n,m;
	scanf("%d %d",&n,&m);
	
	// initialize the adjacency matrix
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				e[i][j]=0;
			}
			else
				e[i][j]=inf;
		}
	}
	
	// initialize the edge of adjacency matrix
	int start,end,distance;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&start,&end,&distance);
		e[start][end] = distance;
	}
	// Select the point number 1 as the starting point
	for(int i=1;i<=n;i++){
		dis[i]=e[1][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",e[i][j]);
		}
		printf("\n");
	}
	vis[1]=1;
	int index;
	
	// the core code of Dijkstra Algorithm
	// Perform n-1 relaxtion operations 
	for(int i=1;i<n;i++){
		int min = inf;
		// Select the minimum distance and its index in matrix dis
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&dis[j]<min){
				min=dis[j];
				index = j;
			}
		}
		
		vis[index]=1;
		// relax other points 
		for(int k=1;k<=n;k++){
			if(e[index][k]<inf){
				if(dis[k]>dis[index]+e[index][k])
					dis[k] = dis[index]+e[index][k];
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		printf("%d ",dis[i]);
	}
	return 0;
}
