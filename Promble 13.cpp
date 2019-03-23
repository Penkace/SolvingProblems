#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
int vis[1000];
int start,end;
struct node{
	int x;
	int step;
};
queue<node>q;
int main(){
	cin>>start>>end;
	vis[start] = 1;
	node sn;
	sn.x= start;
	sn.step= 0;
	q.push(sn);
	int res = 0;
	while(!q.empty()){
		node tmp = q.front();q.pop();
		if(tmp.x==end){
			res = tmp.step;
			break;
		}
		for(int i=0;i<3;i++){
			int xx;
			if(i==0){
				xx = tmp.x+1;
			}
			else if(i==1){
				xx = tmp.x-1;
			}else{
				xx = tmp.x*2;
			}
			if(xx<=end&&vis[xx]!=1){
				vis[xx] = 1;
				node now;now.x = xx;now.step = tmp.step+1;
				q.push(now);
				vis[xx] = 0;
			} 
		}
	}
	cout<<res<<endl;
	return 0;
}
