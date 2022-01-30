#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi

	mcxi 記法を解析するクラスです。
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

		指定された文字列を解析して、オブジェクトを初期化します。
		以下の場合には例外が創出されます。

		1. [2-9,m,c,x,i] 以外の文字が出現した場合
		2. 2 文字続けて数字 (2-9) が出現した場合
		3. m, c, x, i がこの順序で出現しなかった場合
		ただし、例えば mx のように、特定の文字をスキップする事は許容
		されます。
		*/
		/* ----------------------------------------------------------------- */
		mcxi(const std::string& s) : value_(0) {
			int num = 0;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				//*pos は、char ! char ってことが分かってたら、もっと簡単にできるのでは？？
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

		2 つのオブジェクトの加算結果を取得します。
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

		現在の値を mcxi 記法に変換します。
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
			std::cout << "正解" << std::endl;
		}
		else {
			std::cout << "不正解" << std::endl;
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
