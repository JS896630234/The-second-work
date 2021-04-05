#include<iostream>
#include "stack.h"
using namespace std;

int InitStack(PSTACK &S)
{
	S = NULL;  //��ջ��ָ���ÿ�
	
	return 1;
}
int Push(PSTACK &S)
{
    //Ԫ��e��ջ
    ElemType e;
	printf("������Ҫ��ջ��ֵ��");
	scanf_s("%d", &e);
    PSTACK p;
    p = new STACK;        // �����½ڵ�
    p->data = e;        // ���½ڵ���������Ϊe
    p->next = S;        // ���½ڵ����ջ��
    S = p;              // �޸�ջ��ָ��
    return 1;        //��ջҪע��ָ��ķ����Ǵ�ջ��ָ��ջ�׵� 
}

void Traveser(PSTACK &S)
{
	PSTACK p;
	p = S;
	printf("ջ��Ԫ��Ϊ��\n");
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
		printf("ջ�գ�\n");
		return 0;    
	}

	e = S->data;      //��ջ��Ԫ�ظ�ֵ��e
	PSTACK p;
	p = S;              // ��ʱ����ջ��Ԫ�ؿռ䣬׼���ͷ�
	S = S->next;     // �޸�ջ��ָ��
	delete p;     // �ͷ�ԭջ��Ԫ�ؿռ�
	printf("��ջ��Ԫ��Ϊ��%d\n",e);
	return 1;
}
int GetTop(PSTACK S)
{
	//����S��ջ��Ԫ��,���޸�ջ��ָ��,ע�����ջ������
	if (S != NULL)  // ջ�ǿ�
	{
		printf("ջ��Ԫ��Ϊ��%d\n", S->data);
		return 1;
	} 
	else {
		printf("ջ�գ�\n");
		return 0;
	}
}
void Destory(PSTACK &S)
{
	if (S == NULL)
	{
		printf("ջ�գ�\n");
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
	printf("�����٣�\n");
}


void welcome(PSTACK S)
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
	printf("             5---ȡ��Ԫ��                   6--����ջ\n");
	printf("\n");
	printf("                        0--�˳�����\n");
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
