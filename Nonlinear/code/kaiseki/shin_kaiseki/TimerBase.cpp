#include <chrono>
#include <stdio.h>

int main() {
	auto start = std::chrono::system_clock::now(); // �v���J�n����
	for (int i = 0; i <= 10000000l; i++)
		printf("");	// ����
	auto end = std::chrono::system_clock::now();  // �v���I������
	double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
	
	//std::cout << elapsed<< " milli sec \n";
	printf("%f", elapsed);
}