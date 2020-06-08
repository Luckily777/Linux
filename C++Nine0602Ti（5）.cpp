//�ַ������
#include <string>

string addString(string num1, string num2) {
	int begin1 = num1.size() - 1;
	int begin2 = num2.size() - 1;

	//��λ
	int step = 0;
	string sum;

	//Ҳ������ǰ���ÿռ�
	sum.reserve(begin1 > begin2 ? begin1+1 : begin2+1);

	//�ӵ�λ��ʼ���
	while (begin1 >= 0 || begin2 >= 0) {
		//cursum������λ�ĺͣ���������Ϊ��һ���Ľ�λ
		int curSum = step;
		if (begin1 >= 0)
			curSum += num1[begin1--] - '0';
		if (begin2 >= 0)
			curSum += num2[begin2--] - '0';

		//�Ƿ���Ҫ��λ
		if (curSum > 9) {
			step = 1;
			curSum -= 10;
		}
		else {
			step = 0;
			//���浱ǰ�ĺ�
		}
		//1. β��Ч�ʽϵ�
		sum.insert(0, 1, curSum + '0');
		//2. ������
		sum += curSum + '0';
	}
	//���һ�����Ƿ��н�λ
	if (step == 1)
		sum.insert(0, 1, '1');
	//���� reverse(sum.begin(), sum.end());
	return sum;
}