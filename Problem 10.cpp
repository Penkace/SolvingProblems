/*
在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。
要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，
请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
八皇后问题，用DFS+回溯法解
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>

using namespace std;
// 建立一个存储无向图的字符数组 
char map[10][10];
int n,m;
int vis[10];
int tot,cnt;

void dfs(int cur){
	// DFS的终止条件 
	if(cur==m){
		tot++;
		return;
	}
	if(cur>=n)
		return;
	// 开始深层遍历，递归 
	for(int j=0;j<n;j++){
		if(!vis[j]&&map[cur][j]=='#')
		{
			// 每次设置了vis标记和步骤之后，当该次操作返回了就要设置为0和减少相应的操作 
			vis[j]=1;
			cnt++;
			dfs(cur+1);
			vis[j]=0;
			cnt--;
		}
	}
	// 对当前位置进行遍历 
	dfs(cur+1);
}
int main(){
	while(~scanf("%d %d",&n,&m)){ //scanf的输入形式是有不一样的 
		if(n==-1&&m==-1) break;
		getchar();
		tot=0;
		cnt = 0;
		memset(vis,0,sizeof(vis));//清除空间，清空一块内存地址空间 
		for(int i=0;i<n;i++){
			gets(map[i]);//输入地图，这里是读取输入缓冲区一行的map 
		}
		dfs(0);
		printf("%d\n",tot);
	}
	return 0;
}
