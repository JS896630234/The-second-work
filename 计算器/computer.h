#pragma once
#include<iostream> 
#include<stack> 
#include<string>
#include<vector>
#include<algorithm> // pow()
using namespace std;
int computeSuffix(vector<string>);						//�����׺���ʽ int�����ɶ���1λ + - * /
bool priority(string a, string b);						//�ж���������������ȼ�
int str2dec(string);									//str_to_int
vector<string> str2str(const string&);					//�޿ո�������ʽ�ָ� 
vector<string> infix2suffix(const vector<string>&);		//�ָ����ַ�����׺ת��׺