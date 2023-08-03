#include<iostream>
#include<easyx.h>
#include<graphics.h>
#include"bksetting.h"

int pos[4] = { 0,0,0,1 };
int model[4][4] = { 1,-1,0,0,-1,1,-1,0,0,-1,1,-1,0,0,-1,1 };//矩阵变换向量

void fill()
{
	setfillcolor(RGB(24, 31, 242));
	for (int i = 0; i < 4; i++)
	{
		//涂色区域左上角坐标
		int x = pos[i] * WIDTH_UNIT;
		int y = HEIGHT_UNIT * (i + 1);
		fillrectangle(x, y, x + WIDTH_UNIT, y + HEIGHT_UNIT);
	}
}

void transform(int j)
{
	//矩阵变换
	for (int i = 0; i < 4; i++)
	{
		if (!model[i][j])
			continue;
		else if (model[i][j] == 1)
			pos[i] = (pos[i] + 1) % 4;
		else
			pos[i] = (pos[i] - 1 + 4) % 4;
	}
}

void mousepress(ExMessage* mes)
{
	for (int i = 0; i < 4; i++)
	{
		int x1 = pos[i] * WIDTH_UNIT, y1 = HEIGHT_UNIT * (i + 1);
		int x2 = x1 + WIDTH_UNIT, y2 = y1 + HEIGHT_UNIT;
		if (mes->x>x1&&mes->x<x2&&mes->y>y1&&mes->y<y2)
		{
			//将色块矩阵进行变换
			transform(i);
			break;
		}
	}
}

bool success()
{
	//判断游戏是否结束
	if (pos[0] == pos[1] && pos[1] == pos[2] && pos[2] == pos[3])
		return true;
	else
		return false;
}

void interact()
{
	//交互部分
	ExMessage mes = { 0 };
	bool flag = true;

	while (flag)
	{
		if (success())
		{
			std::cout << "SUCCESS" << std::endl;
			break;
		}
		if (peekmessage(&mes))
		{
			switch (mes.message)
			{
				//按键为ESCAPE退出
				case WM_KEYDOWN:
					if (mes.vkcode == VK_ESCAPE)
						flag = false;
					break;

				//按键为鼠标左键时进行碰撞检测
				case WM_LBUTTONDOWN:
					mousepress(&mes);
					break;

				default:
					break;
			}
		}
		//重置窗口
		BeginBatchDraw();
		cleardevice();
		bkdrawing();
		fill();
		EndBatchDraw();
	}
}
