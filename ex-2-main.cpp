#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi

	mcxi �L�@����͂���N���X�ł��B
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	private:
		int value_;
		int unit(char c) {
			switch (c) {
			case 'm': return 1000;
			case 'c': return  100;
			case 'x': return   10;
			case 'i': return    1;
			}
			return -1;
		}
	public:
		/* ----------------------------------------------------------------- */
		/*
		mcxi

		�w�肳�ꂽ���������͂��āA�I�u�W�F�N�g�����������܂��B
		�ȉ��̏ꍇ�ɂ͗�O���n�o����܂��B

		1. [2-9,m,c,x,i] �ȊO�̕������o�������ꍇ
		2. 2 ���������Đ��� (2-9) ���o�������ꍇ
		3. m, c, x, i �����̏����ŏo�����Ȃ������ꍇ
		�������A�Ⴆ�� mx �̂悤�ɁA����̕������X�L�b�v���鎖�͋��e
		����܂��B
		*/
		/* ----------------------------------------------------------------- */
		mcxi(const std::string& s) : value_(0) {
			int num = 0;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				//*pos �́Achar ! char ���Ă��Ƃ��������Ă���A�����ƊȒP�ɂł���̂ł́H�H
				if (*pos >= '2' && *pos <= '9') {
					num = *pos - '0';
				}
				else {
					int u = unit(*pos);
					value_ += std::max(num, 1) * u;
					num = 0;
				}
			}
		}

		/* ----------------------------------------------------------------- */
		/*
		operator+

		2 �̃I�u�W�F�N�g�̉��Z���ʂ��擾���܂��B
		*/
		/* ----------------------------------------------------------------- */
		mcxi operator+(const mcxi& rhs){
			mcxi new_(rhs);
			new_.value_=value_ + rhs.value_;
			return new_;
		}

		/* ----------------------------------------------------------------- */
		/*
		to_string

		���݂̒l�� mcxi �L�@�ɕϊ����܂��B
		*/
		/* ----------------------------------------------------------------- */
		std::string to_string() const {
			string str;
			int num = value_;
			if (num / 1000 >=1) {
				if (num / 1000 == 1) {
					str += "m";
					num -= 1000;
				}
				else {
					str += std::to_string(num / 1000) + "m";
					num -= (num / 1000) * 1000;
				}
			}
			if(num / 100 >= 1) {
				if (num / 100 == 1) {
					str += "c";
					num -= 100;
				}
				else {
					str += std::to_string(num / 100) + "c";
					num -= (num / 100) * 100;
				}
			}
			if(num / 10 >= 1) {
				if (num / 10 == 1) {
					str += "x";
					num -= 10;
				}
				else {
					str += std::to_string(num / 10) + "x";
					num -= (num / 10) * 10;
				}
			}
			if(num / 1 >= 1) {
				if (num / 1 == 1) {
					str += "i";
					num -= 1;
				}
				else {
					str += std::to_string(num / 1) + "i";
					num -= (num / 1) * 1;
				}
			}
			return str;
		}
	};
	void debug(std::string a, std::string b, std::string ans) {
		cpp2::mcxi mcxi_a(a);
		cpp2::mcxi mcxi_b(b);
		cpp2::mcxi result = mcxi_a + mcxi_b;
		if (result.to_string() == ans) {
			std::cout << "����" << std::endl;
		}
		else {
			std::cout << "�s����" << std::endl;
		}
	}
}

int main() {
	cpp2::mcxi a0("x9i");
	cpp2::mcxi b0("xi");
	auto result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;
	cpp2::debug("x9i", "xi", "3x");

	
	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;
	cpp2::debug("i", "9i", "x");

	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	auto result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;
	cpp2::debug("c2x2i", "4c8x8i", "6cx");

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;
	cpp2::debug("m2ci", "4m7c9x8i", "5m9c9x9i");

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;
	cpp2::debug("9c9x9i", "i", "m");

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;
	cpp2::debug("i", "9m9c9x8i", "9m9c9x9i");

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;
	cpp2::debug("m", "i", "mi");

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;
	cpp2::debug("i", "m", "mi");

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;
	cpp2::debug("m9i", "i", "mx");

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
	cpp2::debug("9m8c7xi", "c2x8i", "9m9c9x9i");
}
