#pragma once
typedef int ElemType;

typedef struct stack
{
	ElemType data;
	stack* next;
}STACK, * PSTACK;

void welcome(PSTACK S);
int InitStack(PSTACK& S);			//��ʼ��
void Traveser(PSTACK& S);			//����
int Pop(PSTACK& S);					//��ջ
int Push(PSTACK& S);				//��ջ
int GetTop(PSTACK S);				//ȡջ��Ԫ��
void Destory(PSTACK &S);				//����