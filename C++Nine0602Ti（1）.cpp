//917 ������ת��ĸ
bool isChar(const char& ch) {
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

string reverseOnlyLetters(string S) {
	int begin = 0;
	int end = S.size() - 1;
	while (begin < end) {
		//�ҵ��ַ�
		while (begin < end && !isChar(S[begin]))
			++begin;
		while (begin < end && !isChar(S[end]))
			--end;
		if (begin < end) {
			swap(S[begin], S[end]);
			++begin;
			--end;
		}
	}
	return S;
}