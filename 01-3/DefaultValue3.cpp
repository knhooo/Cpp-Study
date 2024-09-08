#include <iostream>
int BoxVolume(int length, int width = 1, int height = 1);

int main(void) {
	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	// std::cout << "[D, D, D] : " << BoxVolume() << std::endl; // 컴파일 에러
	// 모든 매개변수에 디폴트 값이 지정되어있지 않은데, 
	// 한 개의 인자도 전달하지 않는 형태의 호출을 하기 때문이다. 
}

int BoxVolume(int length, int width, int height) {
	return length * width * height;
}