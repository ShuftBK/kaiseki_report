#include <chrono>
#include <stdio.h>

int main() {
	auto start = std::chrono::system_clock::now(); // 計測開始時間
	for (int i = 0; i <= 10000000l; i++)
		printf("");	// 処理
	auto end = std::chrono::system_clock::now();  // 計測終了時間
	double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //処理に要した時間をミリ秒に変換
	
	//std::cout << elapsed<< " milli sec \n";
	printf("%f", elapsed);
}