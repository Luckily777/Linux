//387 �ַ����еĵ�һ��Ψһ�ַ�

int firstUniqChar(string s) {
	int count[26] = { 0 };
	//��Χfor
	for (const auto& ch : s) {
		count[ch - 'a']++;
	}

	for (int i = 0; i < s.size(); i++) {
		if (count[s[i] - 'a'] == 1)
			return i;
	}
	return -1;
}