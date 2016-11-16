/*
Newton method
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

double fd(double x)
{
	return (-6 * exp(-6 * x) - 3);			 // 計算に用いる微分済み方程式
}

int main()
{
	int k = 0;
	double x0, x1, f0, fd0, diff, delf;
	x0 = 1.5;
	// 実行時間計測開始
	auto start = std::chrono::system_clock::now();

	do {
		f0 = f(x0); fd0 = fd(x0);		// 現在のxの時のfとfdを導出
		x1 = x0 - f0 / fd0;				// 次のxを導出
		diff = fabs(f(x1));				// epsilon法
		delf = fabs(x1 - x0);			// delta法
		x0 = x1;								// xを置き換え
	} while (diff >= eps || delf >= delta);		// epsilon法とdelta法両方を使用しループを抜ける

	// 実行時間計測終了
	auto end = std::chrono::system_clock::now(); 
	//処理に要した時間をマイクロ秒に変換
	double answer = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	printf("%f  %f %f \n", x0, diff, delta);										// 実行結果
	printf("processing time : %f microsecond\n", answer);		// 処理時間
}
