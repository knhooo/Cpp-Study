//문제 1
#include <iostream>
int BoxVolume(int length, int width, int height);
int BoxVolume(int length, int width);
int BoxVolume(int length);


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
int BoxVolume(int length, int width) {
	return length * width * 1;
}
int BoxVolume(int length) {
	return length * 1 * 1;
}

//문제 2
int SimpleFunc(int a = 10) {
	return a + 1;
}
int SimpleFunc(void) {
	return 10;
}

// SimpleFunc()와 같이 인자를 전달하지 않으면서 함수를 호출하는 경우,
// 두 함수 모두 호출 조건을 만족하기 때문에 컴파일 에러가 발생한다.