#include<iostream>
#include<easyx.h>
#include<graphics.h>
#include"bksetting.h"

int pos[4] = { 0,0,0,1 };
int model[4][4] = { 1,-1,0,0,-1,1,-1,0,0,-1,1,-1,0,0,-1,1 };//����任����

void fill()
{
	setfillcolor(RGB(24, 31, 242));
	for (int i = 0; i < 4; i++)
	{
		//Ϳɫ�������Ͻ�����
		int x = pos[i] * WIDTH_UNIT;
		int y = HEIGHT_UNIT * (i + 1);
		fillrectangle(x, y, x + WIDTH_UNIT, y + HEIGHT_UNIT);
	}
}

void transform(int j)
{
	//����任
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
			//��ɫ�������б任
			transform(i);
			break;
		}
	}
}

bool success()
{
	//�ж���Ϸ�Ƿ����
	if (pos[0] == pos[1] && pos[1] == pos[2] && pos[2] == pos[3])
		return true;
	else
		return false;
}

void interact()
{
	//��������
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
				//����ΪESCAPE�˳�
				case WM_KEYDOWN:
					if (mes.vkcode == VK_ESCAPE)
						flag = false;
					break;

				//����Ϊ������ʱ������ײ���
				case WM_LBUTTONDOWN:
					mousepress(&mes);
					break;

				default:
					break;
			}
		}
		//���ô���
		BeginBatchDraw();
		cleardevice();
		bkdrawing();
		fill();
		EndBatchDraw();
	}
}
