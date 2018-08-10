/*********************************
	>File Name: Avoid The Bomb
	>Author: PengKai
	>Date: 2018-08-11 Saturday 2:29 
*********************************/

#include<iostream>
using namespace std;

struct note {
	int x;
	int y;
};//定义一个用于存放坐标的结点


int main() {
	struct note que[2501];//假设地图的边长不超过50*50
	int head, tail;
	int a[51][51];//存放地图的数组
	int book[51][51] = { 0 };//存放地图上各店的标记
	int next[4][2] = { (0,1),(1,0),(0,-1),(-1,0) };//方向数组，用于点的上下左右的移动
	int startx, starty, n, m;
	cin >> n >> m >> startx >> starty;

	//初始化地图
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	//初始化队列
	head = 1;
	tail = 1;

	//tail为队列的尾部，startx，starty赋值
	que[tail].x = startx;
	que[tail].y = starty;

	//tail开始移动，并且把起点的标记数组置位1
	tail++;
	book[startx][starty] = 1;

	int sum = 1;//现在起点有一个，路径总长为1

	//下面是开始遍历，根据右、下、左、上的顺序逐一遍历，如果符合条件则进入队列
	int tx, ty;
	while (head < tail) {//当队列不为空的时候循环
		for (int k = 0; k <= 3; k++)//上下左右四个方向遍历4次
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];//计算下一步的坐标

			if (tx<1 || tx>n || ty<1 || ty>m)//判断是否越界
				continue;

			if (a[tx][ty] > 0 && book[tx][ty] == 0) {//判断是否遇到障碍并且该点还未被访问
				sum++;
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;//符合条件的就放入队列，tail往后移动到下一个空的结点处
			}
		}
		head++;//当第一层遍历结束，移动到下一个结点，直到所有结点都遍历结束
	}
	cout<< sum;
	system("pause");
	return 0;
}
