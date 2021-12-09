// cpp2_1.cpp
#include <iostream>
#include <cmath>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。
/* --------------------------------------------------------------- */
/*
* is_prime
*
* 与えられた正の整数 xに対して、素数かどうかを判定する
*/
/* -------------------------------------------------------------- */
bool is_prime(unsigned int x) {
	//2からx-1までの数がx割れるかチェックする
	if (x == 1) {
		return true;
	}
	for (int i = 2; i <=sqrt(x); i++) {
		if (x%i == 0) {
			return true;
		}
	}
	return false;//もし割れなかったら即falseを返す
}
/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
	int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
		int num = a;
		int count = 0; //numが素数だったら1インクリメントする
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
					std::cout << h[i]<<" "<<ans<<":〇" << std::endl;
					break;
				}
			}
	}
int main() {
	std::cout << nth_prime(367, 186, 151) << " " << "92809" << std::endl;
	hikaku(nth_prime(367, 186, 151));
	// 以下、同様に、入出力例通りになるか確認せよ。
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
