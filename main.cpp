#include<iostream>
#include<easyx.h>
#include<graphics.h>
#include"bksetting.h"
#include"rulesetting.h"

int main()
{
	//���洴��
	bkcreate();

	//���ÿ��
	bkdrawing();

	//��ʼ��ɫ�����
	fill();

	//����
	interact();

	getchar();
	return 0;
}