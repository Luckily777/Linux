//string�Ľӿں���

#include <string>
#include <iostream>
using namespace std;

void test()
{
	string s;
	s.push_back('a');  // a
	s.append(2, 'b');  //abb
	s.append("cde");  //abbcde
	string s2;
	s2.append(s);

	string s3;
	s3.append(s, 3, 2); //cd

	char strArr[] = "1234";
	s3.append(strArr, strArr + 2);  //cd12

	s3.append(s2.begin(), s2.end()); // cd12abbcde

	string s4;
	//operator+=ʹ�õ����
	s4 += '1';    // 1
	s4 += "234";  // 1234
	s4 += s;   //1234abbcde

	/*string(1)
		string& insert(size_t pos, const string& str);
	substring(2)
		string& insert(size_t pos, const string& str, size_t subpos, size_t sublen);
	c - string(3)
		string& insert(size_t pos, const char* s);
	buffer(4)
		string& insert(size_t pos, const char* s, size_t n);
	fill(5)
		string& insert(size_t pos, size_t n, char c);
	void insert(iterator p, size_t n, char c);
	single character(6)
		iterator insert(iterator p, char c);
	range(7)
		template <class InputIterator>
	void insert(iterator p, InputIterator first, InputIterator last);*/

	s4.insert(0, s3);
	s4.insert(0, s3, 7, 3);
	s4.insert(s4.end(), 3, '1');
	s4.insert(s4.end(), strArr + 1, strArr + 3);

	s4.assign("11111");  // 11111
	s4 = "11111";

	s4.erase(0, 2); // 111
	s4.erase(s4.begin()); //11
	s4.erase(s4.end());
	s4.erase(s4.begin(), s4.end());
}

void test2()
{
	string s = "0123456789";
	s.replace(3, 5, "aa");  //012aa89
	s.replace(s.begin() + 1, s.end() - 1, "0");  //009

	string s2 = "abc";
	s2.swap(s);   // s2: 009   s: abc
	swap(s2, s);  //ȫ��string���͵�swap������ �ڲ�����string�ĳ�Ա����swap��ɽ���

	int a = 1;
	int b = 2;
	swap(a, b);  //ȫ���κ����͵�swap����

	//data, c_str����һ�£����Ƿ���c�����ַ����������ַ������׵�ַ
	const char* ptr = s.c_str();
	const char* ptr2 = s.data();
}

void test3()
{
	string str = "aaaaaaaaa";
	//find����Ҳ���������npos��static const size_t nops = -1  --> string�ľ�̬��Ա
	size_t pos = str.find('b');  //������ң��ҵ���һ��ƥ���λ�þͽ���
	size_t pos2 = str.rfind('a');//������ң��ҵ���һ��ƥ���λ�þͽ���

	string file1 = "test.tar.gz.zip";
	pos = file1.rfind('.');
	//substr(pos, len):  ���len���ڴ�pos������λ�õ��ַ������ȣ����ʣ���ַ���ȫ����ȡ����
	string str2 = file1.substr(pos + 1, file1.size() - pos - 1);
	string str3 = file1.substr(pos + 1);
	pos = string::npos;
}

void test4()
{
	string s = "9";
	string s2 = "123";
	string s3 = "1234";
	bool ret = s > s2;
	ret = s2 > s3;
	ret = s > s3;
}

void test5()
{
	string s;
	//cin >> s;

	getline(cin, s);
	cout << s;
	getline(cin, s, ',');
	getline(cin, s, ',');
	getline(cin, s, ',');

}
int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}