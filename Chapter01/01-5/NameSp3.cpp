#include <iostream>
//�Լ��� ������ �ݵ�� �̸� ���� ���ο�
namespace BestComImpl {
	void SimpleFunc(void);
}
//����� �̸������� �̸��� �����ϴٸ�
//������ �̸��������� �����Ѵ�.
namespace BestComImpl {
	void PrettyFunc(void);
}

namespace ProgComImpl {
	void SimpleFunc(void);
}

int main(void) {
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}

//���Ǹ� ������ �� ������ �̸� ���� ��� �ʿ�
void BestComImpl::SimpleFunc(void) {
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
	PrettyFunc();
	//�̸������� ������� ���� ���¿��� ȣ�� ����
	ProgComImpl::SimpleFunc(); //�ٸ� �̸������� �Լ� ȣ��
}

void BestComImpl::PrettyFunc(void) {
	std::cout << "So Pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc(void) {
	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}