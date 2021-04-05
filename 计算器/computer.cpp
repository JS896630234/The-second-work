#include"computer.h"
vector<string> str2str(const string& str)
{
	int size = str.size();
	vector<string> res;
	string temp;
	for (int i = 0; i < size; i++)
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '(' && str[i] != ')')
			temp += str[i]; //如果是数字则保存
		if (str[i] == '+')//遇到任意运算符
		{
			if (!temp.empty())//检测数字非空
			{
				res.push_back(temp);//返回数字
				temp.clear();//数字清空
			}
			res.push_back("+");//返回运算符
		}
		if (str[i] == '-')
		{
			if (!temp.empty())
			{
				res.push_back(temp);
				temp.clear();
			}
			res.push_back("-");
		}
		if (str[i] == '*')
		{
			if (!temp.empty())
			{
				res.push_back(temp);
				temp.clear();
			}
			res.push_back("*");
		}
		if (str[i] == '/')
		{
			if (!temp.empty())
			{
				res.push_back(temp);
				temp.clear();
			}
			res.push_back("/");
		}
		if (str[i] == '(')
		{
			if (!temp.empty())
			{
				res.push_back(temp);
				temp.clear();
			}
			res.push_back("(");
		}
		if (str[i] == ')')
		{
			if (!temp.empty())
			{
				res.push_back(temp);
				temp.clear();
			}
			res.push_back(")");
		}
		if (i == size - 1 && !temp.empty())//当遍历到最后一个字符时
			res.push_back(temp);//若保存数字的变量非空 则也要返回数字
	}
	return res;
}
vector<string> infix2suffix(const vector<string>& s)
{
	vector<string> res;
	stack<string> st;
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		if (s[i] != "(" && s[i] != ")" && s[i] != "+" && s[i] != "*" && s[i] != "-" && s[i] != "/")
			res.push_back(s[i]);//数字直接放入算术表达式
		if (s[i] == "(")
			st.push(s[i]);//'('左括号直接入栈
		if (s[i] == "+" || s[i] == "*" || s[i] == "-" || s[i] == "/")//+ -*/
		{
			if (st.empty())
				st.push(s[i]);//栈空 算术符号入栈
			else//否则根据算术符号优先级出栈
				while (1)
				{
					string temp = st.top();//栈顶算术符号
					if (priority(s[i], temp))//栈顶算术符号优先级高于当前算术符号
					{
						st.push(s[i]);//入栈
						break;//出循环
					}
					else
					{
						res.push_back(temp);//否则栈顶算术符号放入算术表达式
						st.pop();//直到当前算术符号优先级小于栈顶算术符号
						if (st.empty())//如果栈空 那么当前算术符号入栈
						{
							st.push(s[i]);
							break;//出循环
						}
					}
				}
		}
		if (s[i] == ")")//如果是右括号 
		{
			while (st.top() != "(")//算术符号出栈 直到栈顶为左括号
			{
				res.push_back(st.top());
				st.pop();
			}
			st.pop();//'('出栈 且不放入算术表达式
		}
	}
	while (!st.empty())//栈中剩余算术符号放入算术表达式
	{
		res.push_back(st.top());
		st.pop();
	}
	return res;//转换后的算术表达式
}
bool priority(string a, string b)
{
	//算术优先级a>b 返回true 这里注意(优先级低于所有的运算符 
	if (a == "+")
	{
		if (b == "(")
			return true;
		else
			return false;
	}
	if (a == "-")
	{
		if (b == "(")
			return true;
		else
			return false;
	}
	if (a == "*")
	{
		if (b == "+" || b == "-" || b == "(")
			return true;
		else
			return false;
	}
	if (a == "/")
	{
		if (b == "+" || b == "-" || b == "(")
			return true;
		else
			return false;
	}
	return false;//语法要求必有返回值
}
int computeSuffix(vector<string> str)
{
	int size = str.size();
	stack<int> st;
	for (int i = 0; i < size; i++)
	{
		if (str[i] != "+" && str[i] != "-" && str[i] != "*" && str[i] != "/")
			st.push(str2dec(str[i]));
		if (str[i] == "+")
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			st.push(a + b);
		}
		if (str[i] == "-")
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			st.push(b - a);
		}
		if (str[i] == "*")
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			st.push(a * b);
		}
		if (str[i] == "/")
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			st.push(b / a);
		}
	}
	return st.top();
}
int str2dec(string str)
{
	int size = str.size();
	int res = 0;
	for (int i = 0; i < size; i++)
		res += (str[i] - '0') * pow(10, size - i - 1);
	return res;
}