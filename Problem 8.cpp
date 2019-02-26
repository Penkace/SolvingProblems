/******************************
  References: http://www.acmsearch.com/article/show/21021
  Date: 2018-2-26 10:55
******************************/
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int maze[5][5]={0,1,0,0,0,
0,1,0,1,0,
0,0,0,0,0,
0,1,1,1,0,
0,0,0,1,0};

// Create an array of directions, in the order of right, down, left, up
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct note{
	int x,y;
	int pre;
};
// Because we need to output the point instead of the shortest path length, we can't use the queue in STL library 
note q[200];
int head=0,tail =1;
// Reverse the output point by recursively
void print(int i)
{
	if(q[i].pre!=-1){
		print(q[i].pre);
		cout<<"("<<q[i].x<<", "<<q[i].y<<")"<<endl;
	}
}
void bfs(int x1,int y1){
	q[head].x = x1;
	q[head].y = y1;
	q[head].pre = -1;
	while(head<tail){
		for(int k=0;k<4;k++){
			int xx = q[head].x+dir[k][0];
			int yy = q[head].y+dir[k][1];
			if(xx>=0&&yy>=0&&xx<5&&yy<5&&maze[xx][yy]==0){
				// For obstacle map, we can set the passing points as obstacle 
				maze[xx][yy]=1;
				q[tail].x=xx;
				q[tail].y=yy;
				q[tail].pre = head;
				tail++;
			}
			if(xx==4&&yy==4){
				print(head);
			}
		}
		head++;
	}
}

int main(){
	cout<<(0,0)<<endl;
	bfs(0,0);
	cout<<(4,4)<<endl;
	return 0;
}
