#pragma once
typedef int ElemType;

typedef struct stack
{
	ElemType data;
	stack* next;
}STACK, * PSTACK;

void welcome(PSTACK S);
int InitStack(PSTACK& S);			//初始化
void Traveser(PSTACK& S);			//遍历
int Pop(PSTACK& S);					//出栈
int Push(PSTACK& S);				//入栈
int GetTop(PSTACK S);				//取栈顶元素
void Destory(PSTACK &S);				//销毁