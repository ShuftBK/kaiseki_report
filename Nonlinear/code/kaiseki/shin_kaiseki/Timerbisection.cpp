/*
Bisection Method
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
	double a = 1.6, b = 1.7, c, fa, fc, diff, delf, prevc;
	int n = 0;
	// 実行時間計測開始
	auto start = std::chrono::system_clock::now();

	do {
		c = (a + b) / 2; fc = f(c); fa = f(a);
		if (fc*fa < 0) b = c;
		else a = c;
		prevc = c;

		c = (a + b) / 2;
		fc = f(c); fa = f(a);
		diff = fabs(fc);					// epsilon法
		delf = fabs(c - prevc);		// delta法
	} while (diff >= eps || delf >= delta);		// epsilon法とdelta法両方を使用しループを抜ける
	c = (a + b) / 2;
	// 実行時間計測終了
	auto end = std::chrono::system_clock::now();
	//処理に要した時間をマイクロ秒に変換
	double answer = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	printf("a=%f, c=%f, b=%f, diff=%f, delf=%f \n", a, c, b, diff, delf);		// 実行結果
	printf("processing time : %f microsecond\n", answer);						// 処理時間
}
