/*
Bisection Method
*/

// ���Ԍv���p��chrono��ǉ�(�vC++11)
#include <chrono>
#include <stdio.h>
#include <math.h>
// const double �Ƃ��ăO���[�o���ϐ����delta�y��epsilon���`
const double eps = pow(10.0, -15);
const double delta = pow(10.0, -15);

double f(double x)
{
	return (5 + exp((-6)*x) - 3 * x);	// �������̒�`
}

int main()
{
	double a =1.666681, b = 1.666683, c, fa, fc, diff, delf, prevc;
	int n = 0;
	printf("a=%f, b=%f \n", a,b);
	// ���s���Ԍv���J�n
	auto start = std::chrono::system_clock::now();

	do {
		c = (a + b) / 2; fc = f(c); fa = f(a);
		if (fc*fa < 0) b = c;
		else a = c;
		prevc = c;

		c = (a + b) / 2;
		fc = f(c); fa = f(a);
		diff = fabs(fc);					// epsilon�@
		delf = fabs(c - prevc);		// delta�@
	} while (diff >= eps || delf >= delta);		// epsilon�@��delta�@�������g�p�����[�v�𔲂���
	c = (a + b) / 2;
	// ���s���Ԍv���I��
	auto end = std::chrono::system_clock::now();
	//�����ɗv�������Ԃ��}�C�N���b�ɕϊ�
	double answer = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	printf("a=%f, c=%f, b=%f, diff=%f, delf=%f \n", a, c, b, diff, delf);		// ���s����
	printf("processing time : %f microsecond\n", answer);						// ��������
}
