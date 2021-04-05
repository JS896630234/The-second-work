#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int SElemType;

typedef struct
{
	SElemType* base;  //��ʼ��ַ
	SElemType* top;
	int stacksize;  //�ռ��С  eg,a[100]
}SqStack;

enum BOOL { FALSE, TRUE };

void welcome(SqStack S);
Status InitStack(SqStack& S);       //��ʼ��
Status StackEmpty(SqStack S);		//�ж��Ƿ�Ϊ��
int  StackLength(SqStack S);		//�󳤶�
Status Clear(SqStack& S);			//���
Status DestoryStack(SqStack& S);	//����
Status Push(SqStack& S);			//ѹջ
Status Pop(SqStack& S);				//��ջ
Status GetTop(SqStack S);			//ȡ��Ԫ��