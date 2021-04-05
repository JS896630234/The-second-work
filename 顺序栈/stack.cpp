
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

//˳��ջ��ʼ��
Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE];  //����ռ�

	if (!S.base)  //����ʧ��
	{
		printf("��������ʧ��\n"); return ERROR;
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;

	return OK;
}


//�ж�˳��ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return OK;
	else
		return ERROR;
}

//��˳��ջ�ĳ���
int  StackLength(SqStack S)
{
	return S.top - S.base;   //ʵ��Ԫ��
}

//���˳��ջ  --�ص���ʼ״̬
Status Clear(SqStack& S)
{
	if (S.base)
		S.top = S.base;   //ǿ���޸�top����Ϊbaseʼ��ָ��׶�
	printf("��ճɹ���\n");
	return OK;
}

//����˳��ջ
Status DestoryStack(SqStack& S)
{
	if (S.base)
	{
		delete  S.base;			//�ͷſռ�
		S.stacksize = 0;
		S.base = S.top = NULL;  //����ָ���ָ��
	}
	printf("���ٳɹ���\n");
	return OK;
}
//˳��ջ��ջ
Status Push(SqStack& S)
{
	SElemType e;
	printf("�������ջ��ֵ��");
	scanf_s("%d", &e);

	if (S.top - S.base == S.stacksize)  //��-��=����
		return ERROR;
	*S.top = e;     //*S.top++=e;  Ԫ��eѹ��ջ��
	S.top++;  //ջ��ָ���1
	return OK;
}

//˳��ջ��ջ
Status Pop(SqStack& S)
{
	SElemType e;
	if (S.top == S.base) //ջ��
		return ERROR;
	S.top--;
	e = *S.top;  //e=*--S.top;
	printf("��ջ��Ԫ��Ϊ��%d\n", e);
	return OK;
}

//ȡ˳��ջջ��Ԫ��
Status GetTop(SqStack S)
{
	SElemType e;
	if (S.top == S.base)
		return ERROR;  //ջ��
	e = *(S.top - 1);   //e=*--S.top;
	printf("ջ����Ԫ��Ϊ��%d\n", e);
	return OK;
}



void welcome(SqStack S)
{
	int choice;

A:	printf("                              ���˵�\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("                      ��������Ҫ���еĲ�����0-6����\n");
	printf("\n");
	printf("             1---��ʼ��ջ                   2---����ջ\n");
	printf("\n");
	printf("             3---ѹջ                       4---��ջ \n");
	printf("\n");
	printf("             5---���ջ                     6--ȡ��Ԫ��\n");
	printf("\n");
	printf("                        0---�˳��˵� \n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("��������ţ�0-6����\n");
	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//��ջ�����
		printf("���������������������һ�飡\n");	//��ܰ����һ��
	}
	if (choice)
		system("cls");
	fflush(stdin);
	switch (choice)
	{
	case 1:InitStack(S); printf("��ʼ��ջ�ɹ�!\n"); goto A;
	case 2:DestoryStack(S); goto A;
	case 3:Push(S); goto A;
	case 4:Pop(S); goto A;
	case 5:Clear(S); goto A;
	case 6:GetTop(S); goto A;
	case 0:break;
	default:printf("ERROR\n"); goto A;
	};
	return;
}