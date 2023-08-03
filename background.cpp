#include<easyx.h>
#include<graphics.h>
#include"bksetting.h"

void bkcreate()
{
	//初始化窗口
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, EW_SHOWCONSOLE);

	//设置背景颜色
	setbkcolor(RGB(218, 184, 242));

	//应用背景颜色
	cleardevice();
}
void bkdrawing()
{

	//绘制框架
	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);
	for (int i = 1; i <= 4; i++)
	{
		line(0, HEIGHT_UNIT * i, WINDOW_WIDTH, HEIGHT_UNIT * i);
		line(WIDTH_UNIT * i, HEIGHT_UNIT, WIDTH_UNIT * i, WINDOW_HEIGHT);
	}
	//设置标题
	settextstyle(FONT_SIZE, 0, "Consolas");
	settextcolor(BLACK);
	outtextxy(WIDTH_UNIT, FONT_SPACE, "matrix riddle");
}