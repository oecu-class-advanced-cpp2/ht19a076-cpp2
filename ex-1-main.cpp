// cpp2_1.cpp
#include <iostream>
#include <cmath>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B
/* --------------------------------------------------------------- */
/*
* is_prime
*
* �^����ꂽ���̐��� x�ɑ΂��āA�f�����ǂ����𔻒肷��
*/
/* -------------------------------------------------------------- */
bool is_prime(unsigned int x) {
	//2����x-1�܂ł̐���x����邩�`�F�b�N����
	if (x == 1) {
		return true;
	}
	for (int i = 2; i <=sqrt(x); i++) {
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
		for (int i = 0; i < CPP2_PRIME_UPPER_LIMIT; i++) {
			if (is_prime(num)==false) {
				count++;
			}
			if (count == n) {
				break;
			}
			num += d;
		}
		return num;
}
	void hikaku(unsigned int ans) {
		int h[12] = { 92809, 6709, 12037, 103, 93523, 14503, 2, 899429, 5107, 412717, 22699, 25673 };
			for (int i = 0; i <12 ; i++) {
				if (ans == h[i]) {
					std::cout << h[i]<<" "<<ans<<":�Z" << std::endl;
					break;
				}
			}
	}
int main() {
	std::cout << nth_prime(367, 186, 151) << " " << "92809" << std::endl;
	hikaku(nth_prime(367, 186, 151));
	// �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
	std::cout << nth_prime(179, 10, 203) << " " << "6709" << std:: endl;
	hikaku(nth_prime(178, 10, 203));
	std::cout << nth_prime(271, 37, 39) << " " << "12037" << std::endl;
	hikaku(nth_prime(271, 37, 39));
	std::cout << nth_prime(103, 230, 1) << " " << "103" << std::endl;
	std::cout << nth_prime(27, 104, 185) << " " << "93523" << std::endl;
	std::cout << nth_prime(253, 50, 85) << " " << "14503" << std::endl;
	std::cout << nth_prime(1, 1, 1) << " " << "2" << std::endl;
	std::cout << nth_prime(9075, 337, 210) << " " << "899429" << std::endl;
	std::cout << nth_prime(307, 24, 79) << " " << "5107" << std::endl;
	std::cout << nth_prime(331, 221, 177) << " " << "412717" << std::endl;
	std::cout << nth_prime(259, 170, 40) << " " << "22699" << std::endl;
	std::cout << nth_prime(269, 58, 102) << " " << "25673" << std::endl;

	return 0;
}
