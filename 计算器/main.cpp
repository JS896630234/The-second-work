#include"computer.h"
int main()
{
	
	cout << "\t\t\t\tע������������֧��С���㣬�ҽ�����ֵΪ��2147483647��" << endl<<endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	string str4 ;//��������
	cout << "��������ȷ�ı��ʽ��" << endl;
	cin >> str4;
	vector<string> str5 = str2str(str4);		//�ַ����ӿո�
	cout << "�ָ����ʽ=" << endl;
	for (int i = 0; i < str5.size(); i++)
		cout << str5[i] << " ";
	cout << endl;
	cout << "����׺���ʽ��д�ĺ�׺���ʽ=:" << endl;
	vector<string> str6 = infix2suffix(str5);	//��׺to��׺
	for (int i = 0; i < str6.size(); i++)
		cout << str6[i] << " ";
	cout << endl;
	cout << str4 << "=" << computeSuffix(str6) << endl;//������
	return 0;
}
