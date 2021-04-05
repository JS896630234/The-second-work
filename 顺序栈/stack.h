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
	SElemType* base;  //起始地址
	SElemType* top;
	int stacksize;  //空间大小  eg,a[100]
}SqStack;

enum BOOL { FALSE, TRUE };

void welcome(SqStack S);
Status InitStack(SqStack& S);       //初始化
Status StackEmpty(SqStack S);		//判断是否为空
int  StackLength(SqStack S);		//求长度
Status Clear(SqStack& S);			//清空
Status DestoryStack(SqStack& S);	//销毁
Status Push(SqStack& S);			//压栈
Status Pop(SqStack& S);				//出栈
Status GetTop(SqStack S);			//取顶元素