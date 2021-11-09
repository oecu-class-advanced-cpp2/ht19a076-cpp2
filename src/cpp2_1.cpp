// cpp2_1.cpp
#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B
/* --------------------------------------------------------------- */
/*
* is_prime
*
* �^����ꂽ������ x�ɑ΂��āA�f�����ǂ����𔻒肷��
*/
/* -------------------------------------------------------------- */
bool is_prime(unsigned int x) {
	//2����x-1�܂ł̐���x����邩�`�F�b�N����
	for (int i = 2; i < x-1/ 2; i++) {
		if (x%i == 0) {
			return true;
		}
	}
	return false;//��������Ȃ������瑦false��Ԃ�
}
/* --------------------------------------------------------------- */
/*
* nth_prime
*
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
*/
/* -------------------------------------------------------------- */
	int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
		int num = a;
		int count = 0; //num���f����������1�C���N�������g����
		for (int i = 0; i < 1000000; i++) {
			if (is_prime(num) == false){
				count++;
		}
		if (count == n) {
			std::cout << num << std::endl;
			break;
		}
		num += d;
	}
	return 0;
}
int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;
	// �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
	std::cout << nth_prime(179, 10, 203) << std::endl;
	std::cout << nth_prime(271, 37, 39) << std::endl;
	std::cout << nth_prime(103, 230, 1) << std::endl;
	std::cout << nth_prime(27, 104, 185) << std::endl;
	std::cout << nth_prime(253, 50, 85) << std::endl;
	std::cout << nth_prime(1, 1, 1) << std::endl;
	std::cout << nth_prime(9075, 337, 210) << std::endl;
	std::cout << nth_prime(307, 24, 79) << std::endl;
	std::cout << nth_prime(331, 221, 177) << std::endl;
	std::cout << nth_prime(259, 170, 40) << std::endl;
	std::cout << nth_prime(269, 58, 102) << std::endl;
	return 0;
}
