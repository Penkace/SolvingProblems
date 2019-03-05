#include<bits/stdc++.h>
using namespace std;
const int N = 50;
const int inf = INT_MAX;
char maze[N][N];
int n,m;// n,m为边的长度
int start,end;// J出发的坐标
int fs,fe;// 起火点坐标
struct node{
	int x,y;
	int sec;
};
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
queue<node>fq;
queue<node>jq;
int vis[N][N];

int bfs(int x1,int y1,int x2,int y2){
	memset(vis,0,sizeof(vis));
	vis[x1][y1] = vis[x2][y2] = 1;
	node snode; snode.x = x1; snode.y = y1;snode.sec = 0;
	jq.push(snode);
	node fnode; fnode.x = x2; fnode.y = y2;fnode.sec = 0;
	fq.push(fnode);
	while(!jq.empty()){
		node jtmp = jq.front();jq.pop();
		node ftmp = fq.front();fq.pop();
		// 如果一开始两个点就重合了，那么就直接退出循环
		if(jtmp.x == ftmp.x && jtmp.y == ftmp.y)
			break;
		// 循环的终止条件是jq队列为空，递归的终止条件是J到达了边界且边界不为火
		if(maze[jtmp.x][jtmp.y]=='.'&&(jtmp.x==n-1|| jtmp.y==m-1||jtmp.x==0||jtmp.y==0)){
			return jtmp.sec;
		}
		// 先判断火的燃烧，考虑到相遇时人就出不去，因此先判断火的状态
		for(int k=0;k<4;k++){
			int xx = ftmp.x + dir[k][0];
			int yy = ftmp.y + dir[k][1];
			if(xx>=0&&yy>=0&&xx<n&&yy<m&&maze[xx][yy]!='#'){
				node fnext;
				fnext.x = xx;
				fnext.y =yy; 
				fnext.sec = ftmp.sec+1;
				vis[xx][yy]==1;
				fq.push(fnext);
			}
		}
		// 下面是人的移动范围的位置进队
		for(int k=0;k<4;k++){
			int xx = jtmp.x+dir[k][0];
			int yy = jtmp.y+dir[k][1];
			if(xx>=0&&yy>=0&&xx<n&&yy<m&&vis[xx][yy]==0&&maze[xx][yy]=='.'){
				node jnext; jnext.x= xx;jnext.y = yy;jnext.sec = jtmp.sec+1;
				jq.push(jnext);
			}
		}
	}
	return inf;
}

int main(){
	int cas;
	int sec = inf;
	scanf("%d",&cas);		
	while(cas--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%s",maze[i]);
			for(int j=0;j<m;j++){
				if(maze[i][j]=='J'){
					start = i;
					end = j;
				}
				if(maze[i][j]=='F'){
					fs = i;
					fe = j;
				}
			}
		}
		int c = bfs(start,end,fs,fe);
		if(c==inf){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else{
			cout<<c<<endl;
		}
	}
	return 0;
}
