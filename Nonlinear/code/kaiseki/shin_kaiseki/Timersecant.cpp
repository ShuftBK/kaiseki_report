/*
Secant method
*/

// 時間計測用にchronoを追加(要C++11)
#include <chrono>
#include <stdio.h>
#include <math.h>
// const double としてグローバル変数上にdelta及びepsilonを定義
const double eps = pow(10.0, -15);
const double delta = pow(10.0, -15);

double f(double x)
{
	return (5 + exp((-6)*x) - 3 * x);	// 方程式の定義
}

int main()
{
	int n = 0;
	double x0 = -2.0, x1 = -1.1, x2, f0, f1, diff, delf;
	// 実行時間計測開始
	auto start = std::chrono::system_clock::now();

	do {
		f1 = f(x1); f0 = f(x0);
		x2 = x1 - f1*(x1 - x0) / (f1 - f0);
		diff = fabs(f(x2));								// epsilon法
		delf = fabs(x2 - x1);							// delta法
		x0 = x1; x1 = x2;
		printf("%25.15e   %10.3e  \n", x1, diff);
	} while (diff >= eps || delf >= delta);		// epsilon法とdelta法両方を使用しループを抜ける

	// 実行時間計測終了
	auto end = std::chrono::system_clock::now();
	//処理に要した時間をマイクロ秒に変換
	double answer = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	printf("%25.15e   %10.3e  \n", x1, diff);									// 実行結果
	printf("processing time : %f microsecond\n", answer);		// 処理時間
}
