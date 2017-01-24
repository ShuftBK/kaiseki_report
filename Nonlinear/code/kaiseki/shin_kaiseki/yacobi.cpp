/*
Yacobi  method
*/

#include <stdio.h>
#include <math.h>
#define n 3
#define n1 4
#define EPS 1.0e-15
#define KMAX 10000
int main()
{
	int i, j, k = 0;
	double a[n1][n1], b[n1], x[n1], xn[n1], eps_sum;

	a[1][1] = 40;  a[1][2] = -20;  a[1][3] = 0;
	a[2][1] = 20;  a[2][2] = -10;  a[2][3] = 30;
	a[3][1] = 20;  a[3][2] = 20;   a[3][3] = -10;
	b[1] = 22, b[2] = 22, b[3] = 22;
	x[1] = 0, x[2] =0, x[3] = 0;

	do {
		eps_sum = 0.0;
		for (i = 1; i <= n; i++) {
			xn[i] = b[i];										// ��������ۑ�
			for (j = 1; j <= n; j++) {					// ���߂���ȊO�̕����𑫂��Ă���
				if (j != i) xn[i] -= a[i][j] * x[j];		// ���߂���ȊO�̕����𑫂����킹�Ă���
			}
			xn[i] /= a[i][i];									//���߂�ϐ��ɂ������Ă���萔������
		}													
		for (i = 1; i <= n; i++) {						
			eps_sum += fabs(xn[i] - x[i]);
			x[i] = xn[i];
		}
		k++;			//���s�񐔂̃C���N�������g
	} while (eps_sum>EPS && k< KMAX);
	if (k == KMAX) {
		printf("Error!! The answers is not found.\n");
	}
	else {
		printf(" Iteration K = %d \n", k);
		for (i = 1; i <= n; i++) {
			printf("x[%d] = %f ", i, x[i]);
		}
		printf(" \n");
	}
}