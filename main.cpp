#include<iostream>
#include<easyx.h>
#include<graphics.h>
#include"bksetting.h"
#include"rulesetting.h"

int main()
{
	//创建窗口
	bkcreate();

	//绘制背景
	bkdrawing();

	//初始化色块
	fill();

	//交互
	interact();

	getchar();
	return 0;
}
