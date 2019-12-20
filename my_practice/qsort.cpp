/*
	stdlib.h 에서 qsort함수를 지원하는데 이를 사용하는 방법에 대해 적어둠
	qsort함수의 프로토 타입은 
	void qsort( void* base, size_t nelm, size_t width, int(?)compare_func ); 이다

	- void* base   	: 정렬할 배열의 포인터 시작점을 인자로 줌
	- size_t nelm 	: sizeof()함수를 사용하여 sizeof(arr)/sizeof(int)와 같이 인자로 줌이 바람직함
	- size_t width	: 배열의 데이터형의 사이즈를 말하고, sizeof(int) 와 같이 주었다.
	- compare_func	: qsort함수 내에서 함수포인터를 이용하여 비교를 시행하므로 더욱 유연한
					  함수를 만들기 위해 존재하는 것으로 안다.

					  아래 int cmp_int(const void* a, const void* b) 와 같이 이름과 인자를 주면되고
					  *(자료형*)a > *(자료형*)b 과 같이 void포인터에 대하여 이런 자료형을 쓸거다 라고 알려주고
					  a > b  일 때 1
					  a == b 일 때 0
					  a < b  일 때 -1
					  을 return 하게 한다면 오름차순으로 정렬이되고, 반대로 
					  -1 0 1 의 순서대로 return 하게 된다면 내림차순으로 정렬이 된다.
*/

#include<iostream>
#include<cstdlib>
using namespace std;

int cmp_int(const void* a, const void* b) {
	if 		(*(int*)a > *(int*)b)		return 1;
	else if (*(int*)a == *(int*)b)	return 0;
	else						return -1;
}

int main() {
	int arr[27] = {
		8, 17, 0, 1, 2, 1, 2, 33, 2, 0, 1, 6, 6, 16, 15,
		4, 1, 6, 0, 1, 2, 11, 10, 12, 8, 2
	};

	for(int i=0; i<27; ++i) cout << arr[i] << ' '; cout << endl;
	// 8 17 0 1 2 1 2 33 2 0 1 6 6 16 15 4 1 6 0 1 2 11 10 12 8 2

	qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), cmp_int);
	for(int i=0; i<27; ++i) cout << arr[i] << ' '; cout << endl;
	// 0 0 0 0 1 1 1 1 1 2 2 2 2 2 4 6 6 6 8 8 10 11 12 15 16 17 33
		
	return 0;
}
	