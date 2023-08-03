#include<iostream>
#include<easyx.h>
#include<graphics.h>
#include"bksetting.h"
#include"rulesetting.h"

int main()
{
	//界面创建
	bkcreate();

	//设置框架
	bkdrawing();

	//初始化色块矩阵
	fill();

	//交互
	interact();

	getchar();
	return 0;
}