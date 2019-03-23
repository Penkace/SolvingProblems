/* 过样例是没问题的，就是输出的结果没有完善，只写了基本的思想*/
#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int c,h,l; 
const int N = 100;
char m[N][N][N];
struct node{
	int x,y,z;
	int step;
};
node start,end;
queue<node>q;
int dir[6][3] = {{0,1,0},{0,0,-1},{0,-1,0},{0,0,1},{1,0,0},{-1,0,0}};
int main(){
	cin>>c>>h>>l;
	for(int i=0;i<c;i++){
		for(int j=0;j<h;j++){
			for(int k=0;k<l;k++){
				cin>>m[i][j][k];
				if(m[i][j][k]=='S'){
					start.x = i;
					start.y = j;
					start.z = k;
					q.push(start);
				}
				if(m[i][j][k]=='E'){
					end.x = i;
					end.y = j;
					end.z = k;
				}
			} 
		}
	}
	int res = 0;
	while(!q.empty()){
		node tmp = q.front();
		q.pop();
		if(tmp.x ==end.x&&tmp.y ==end.y&&tmp.z == end.z){
			res = tmp.step;
			break;
		}
		for(int k=0;k<6;k++){
			int cc = tmp.x+dir[k][0];
			int hh = tmp.y+dir[k][1];
			int ll = tmp.z + dir[k][2];
			if(cc>=0&&cc<c&&hh>=0&&hh<h&&ll>=0&&ll<l&&m[cc][hh][ll]!='#'){
				node now;now.x = cc;now.y = hh;now.z = ll;now.step = tmp.step+1;
				q.push(now);
				m[cc][hh][ll] = '#';
			}
		}
	}
	cout<<res<<endl;
	return 0;
}
