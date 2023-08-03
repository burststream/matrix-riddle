#include<easyx.h>
#include<graphics.h>
#include"bksetting.h"

void bkcreate()
{
	//��ʼ������
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, EW_SHOWCONSOLE);

	//���ñ�����ɫ
	setbkcolor(RGB(218, 184, 242));

	//Ӧ�ñ�����ɫ
	cleardevice();
}
void bkdrawing()
{

	//���ƿ��
	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);
	for (int i = 1; i <= 4; i++)
	{
		line(0, HEIGHT_UNIT * i, WINDOW_WIDTH, HEIGHT_UNIT * i);
		line(WIDTH_UNIT * i, HEIGHT_UNIT, WIDTH_UNIT * i, WINDOW_HEIGHT);
	}
	//���ñ���
	settextstyle(FONT_SIZE, 0, "Consolas");
	settextcolor(BLACK);
	outtextxy(WIDTH_UNIT, FONT_SPACE, "matrix riddle");
}