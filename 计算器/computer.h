#pragma once
#include<iostream> 
#include<stack> 
#include<string>
#include<vector>
#include<algorithm> // pow()
using namespace std;
int computeSuffix(vector<string>);						//计算后缀表达式 int整数可多于1位 + - * /
bool priority(string a, string b);						//判断两个运算符的优先级
int str2dec(string);									//str_to_int
vector<string> str2str(const string&);					//无空格运算表达式分割 
vector<string> infix2suffix(const vector<string>&);		//分割后的字符串中缀转后缀