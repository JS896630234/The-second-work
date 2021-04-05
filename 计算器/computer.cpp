#include"computer.h"
vector<string> str2str(const string& str)
{
	int size = str.size();
	vector<string> res;
	string temp;
	for (int i = 0; i < size; i++)
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '(' && str[i] != ')')
			temp += str[i]; //����������򱣴�
		if (str[i] == '+')//�������������
		{
			if (!temp.empty())//������ַǿ�
			{
				res.push_back(temp);//��������
				temp.clear();//�������
			}
			res.push_back("+");//���������
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
		if (i == size - 1 && !temp.empty())//�����������һ���ַ�ʱ
			res.push_back(temp);//���������ֵı����ǿ� ��ҲҪ��������
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
			res.push_back(s[i]);//����ֱ�ӷ����������ʽ
		if (s[i] == "(")
			st.push(s[i]);//'('������ֱ����ջ
		if (s[i] == "+" || s[i] == "*" || s[i] == "-" || s[i] == "/")//+ -*/
		{
			if (st.empty())
				st.push(s[i]);//ջ�� ����������ջ
			else//������������������ȼ���ջ
				while (1)
				{
					string temp = st.top();//ջ����������
					if (priority(s[i], temp))//ջ�������������ȼ����ڵ�ǰ��������
					{
						st.push(s[i]);//��ջ
						break;//��ѭ��
					}
					else
					{
						res.push_back(temp);//����ջ���������ŷ����������ʽ
						st.pop();//ֱ����ǰ�����������ȼ�С��ջ����������
						if (st.empty())//���ջ�� ��ô��ǰ����������ջ
						{
							st.push(s[i]);
							break;//��ѭ��
						}
					}
				}
		}
		if (s[i] == ")")//����������� 
		{
			while (st.top() != "(")//�������ų�ջ ֱ��ջ��Ϊ������
			{
				res.push_back(st.top());
				st.pop();
			}
			st.pop();//'('��ջ �Ҳ������������ʽ
		}
	}
	while (!st.empty())//ջ��ʣ���������ŷ����������ʽ
	{
		res.push_back(st.top());
		st.pop();
	}
	return res;//ת������������ʽ
}
bool priority(string a, string b)
{
	//�������ȼ�a>b ����true ����ע��(���ȼ��������е������ 
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
	return false;//�﷨Ҫ����з���ֵ
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