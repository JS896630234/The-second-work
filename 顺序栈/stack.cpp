
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

//顺序栈初始化
Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE];  //申请空间

	if (!S.base)  //申请失败
	{
		printf("内容申请失败\n"); return ERROR;
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;

	return OK;
}


//判断顺序栈是否为空
Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return OK;
	else
		return ERROR;
}

//求顺序栈的长度
int  StackLength(SqStack S)
{
	return S.top - S.base;   //实际元素
}

//清空顺序栈  --回到初始状态
Status Clear(SqStack& S)
{
	if (S.base)
		S.top = S.base;   //强制修改top，因为base始终指向底端
	printf("清空成功！\n");
	return OK;
}

//销毁顺序栈
Status DestoryStack(SqStack& S)
{
	if (S.base)
	{
		delete  S.base;			//释放空间
		S.stacksize = 0;
		S.base = S.top = NULL;  //重新指向空指针
	}
	printf("销毁成功！\n");
	return OK;
}
//顺序栈进栈
Status Push(SqStack& S)
{
	SElemType e;
	printf("请输入进栈的值：");
	scanf_s("%d", &e);

	if (S.top - S.base == S.stacksize)  //顶-低=距离
		return ERROR;
	*S.top = e;     //*S.top++=e;  元素e压入栈顶
	S.top++;  //栈顶指针加1
	return OK;
}

//顺序栈出栈
Status Pop(SqStack& S)
{
	SElemType e;
	if (S.top == S.base) //栈空
		return ERROR;
	S.top--;
	e = *S.top;  //e=*--S.top;
	printf("出栈的元素为；%d\n", e);
	return OK;
}

//取顺序栈栈顶元素
Status GetTop(SqStack S)
{
	SElemType e;
	if (S.top == S.base)
		return ERROR;  //栈空
	e = *(S.top - 1);   //e=*--S.top;
	printf("栈顶的元素为；%d\n", e);
	return OK;
}



void welcome(SqStack S)
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
	printf("             5---清空栈                     6--取顶元素\n");
	printf("\n");
	printf("                        0---退出菜单 \n");
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