#include<iostream>
#include<fstream>
using namespace std;

int main() {
	std::istream in("ex.exel.ods");
	std::string s;

	if(in.is_open()) {
		in >> s;
		std::cout << "입력 받은 문자열: " << s; 
	}

	return 0;
}