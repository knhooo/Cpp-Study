//���� 1
#include <iostream>
int BoxVolume(int length, int width, int height);
int BoxVolume(int length, int width);
int BoxVolume(int length);


int main(void) {
	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	// std::cout << "[D, D, D] : " << BoxVolume() << std::endl; // ������ ����
	// ��� �Ű������� ����Ʈ ���� �����Ǿ����� ������, 
	// �� ���� ���ڵ� �������� �ʴ� ������ ȣ���� �ϱ� �����̴�. 
}

int BoxVolume(int length, int width, int height) {
	return length * width * height;
}
int BoxVolume(int length, int width) {
	return length * width * 1;
}
int BoxVolume(int length) {
	return length * 1 * 1;
}

//���� 2
int SimpleFunc(int a = 10) {
	return a + 1;
}
int SimpleFunc(void) {
	return 10;
}

// SimpleFunc()�� ���� ���ڸ� �������� �����鼭 �Լ��� ȣ���ϴ� ���,
// �� �Լ� ��� ȣ�� ������ �����ϱ� ������ ������ ������ �߻��Ѵ�.