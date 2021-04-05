#include<iostream>
#include "stack.h"
using namespace std;

int InitStack(PSTACK &S)
{
	S = NULL;  //将栈顶指针置空
	
	return 1;
}
int Push(PSTACK &S)
{
    //元素e入栈
    ElemType e;
	printf("请输入要入栈的值：");
	scanf_s("%d", &e);
    PSTACK p;
    p = new STACK;        // 生成新节点
    p->data = e;        // 将新节点数据域置为e
    p->next = S;        // 将新节点插入栈顶
    S = p;              // 修改栈顶指针
    return 1;        //链栈要注意指针的方向是从栈顶指向栈底的 
}

void Traveser(PSTACK &S)
{
	PSTACK p;
	p = S;
	printf("栈的元素为：\n");
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int Pop(PSTACK &S)
{
	int e;

	if (S == NULL)
	{
		printf("栈空！\n");
		return 0;    
	}

	e = S->data;      //将栈顶元素赋值给e
	PSTACK p;
	p = S;              // 临时保存栈顶元素空间，准备释放
	S = S->next;     // 修改栈顶指针
	delete p;     // 释放原栈顶元素空间
	printf("出栈的元素为：%d\n",e);
	return 1;
}
int GetTop(PSTACK S)
{
	//返回S的栈顶元素,不修改栈顶指针,注意与出栈的区别
	if (S != NULL)  // 栈非空
	{
		printf("栈顶元素为：%d\n", S->data);
		return 1;
	} 
	else {
		printf("栈空！\n");
		return 0;
	}
}
void Destory(PSTACK &S)
{
	if (S == NULL)
	{
		printf("栈空！\n");
		return ;   
	}
	PSTACK p = S;
	PSTACK q=NULL;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	S = NULL;
	printf("已销毁！\n");
}


void welcome(PSTACK S)
{
	int choice;

A:	printf("                              主菜单\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("                      请输入你要进行的操作（0-6）：\n");
	printf("\n");
	printf("             1---初始化栈                   2---销毁栈\n");
	printf("\n");
	printf("             3---压栈                       4---出栈 \n");
	printf("\n");
	printf("             5---取顶元素                   6--遍历栈\n");
	printf("\n");
	printf("                        0--退出程序\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("请输入序号（0-6）：\n");
	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//清空缓存区
		printf("你输入的数据有误，请再输一遍！\n");	//温馨提醒一下
	}
	if (choice)
		system("cls");
	fflush(stdin);
	switch (choice)
	{
	case 1:InitStack(S); printf("初始化栈成功!\n"); goto A;
	case 2:Destory(S); goto A;
	case 3:Push(S); goto A;
	case 4:Pop(S); goto A;
	case 5:GetTop(S); goto A;
	case 6:Traveser(S); goto A;
	case 0:break;
	
	default:printf("ERROR\n"); goto A;
	};
	return;
}
