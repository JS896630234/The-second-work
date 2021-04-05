#include"computer.h"
int main()
{
	
	cout << "\t\t\t\t注：本计算器不支持小数点，且结果最大值为：2147483647！" << endl<<endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	string str4 ;//测试用例
	cout << "请输入正确的表达式：" << endl;
	cin >> str4;
	vector<string> str5 = str2str(str4);		//字符串加空格
	cout << "分割后表达式=" << endl;
	for (int i = 0; i < str5.size(); i++)
		cout << str5[i] << " ";
	cout << endl;
	cout << "由中缀表达式改写的后缀表达式=:" << endl;
	vector<string> str6 = infix2suffix(str5);	//中缀to后缀
	for (int i = 0; i < str6.size(); i++)
		cout << str6[i] << " ";
	cout << endl;
	cout << str4 << "=" << computeSuffix(str6) << endl;//计算结果
	return 0;
}
