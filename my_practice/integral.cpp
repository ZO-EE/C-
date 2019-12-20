// integrate power functions
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

#define MAX_POW		10
#define VEC_MAX		10

////////////////////////////////////////////////////////////////
class Pow_func {
private	:
	int degree;
	int constant[MAX_POW];
public	:
	Pow_func();
	void integrate();
};

//vector<Pow_func> func_arr;
//////////////////////////////////////////////////////////////////////
Pow_func::Pow_func() {
	bool flag = false;

	memset(constant, 0, sizeof(int)*10);

	while(!flag) {
		cout << "최고 차항의 차수를 입력하세여: " << endl;
		cin  >> degree;
		cout << "해당하는 함수의 계수를 최고 차항부터 차근 차근 공백을 기준으로 입력하세요: " << endl;
		for(int i=degree; i>=0; --i) cin >> constant[i];

		cout << "입력하신 함수가 아래가 맞나요?" << endl;
		for(int i=degree; i>=0; --i)	cout << ' ' << constant[i] << "x^" << i << " +";
		cout << endl;

		cout << "맞다면 아무키나, 다시입력하시려면 0을 입력하세요. : ";
		cin  >> flag; 
	}
}

void Pow_func::integrate() {
	int start, end, tmp;
	int sum = 0;

	cout << "아래 끝과 위 끝을 입력해주세요 (정수) : ";
	cin >> start >> end;

	cout << "결과: ";
	for(int i=degree; i>=0; --i) {
		tmp = constant[i]*( pow(end, i+1) - pow(start, i+1) );
		if( (tmp&(i+1)) != 0 )	cout << "(1/" << i+1 << ")*(" << tmp << ") + ";
		else						sum += tmp / (i+1); 
	}
	cout << sum << endl;

	cout << "계산이 완료됐습니다." << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*
void user_interface() {
	int sw;

	cout << "---------------- 적분 계산기 ------------------------------" << endl;
	cout << " 1. 함수 입력" << endl;
	cout << " 2. 함수 출력" << endl;
	cout << " 3. 함수 적분" << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	cout << " 원하시는 기능의 버튼을 입력하세요. : ";
	cin  >> sw;

	switch(sw) {
		case 1: func_arr.push();
		case 2: 
	}
}
*/

int main() {
	Pow_func func1;

	func1.integrate();
	return 0;
}
