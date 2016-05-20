/********************************
이름		: 최 준 형
학번		: 20123425
ID			: Lab0-1
Description : 최댓값, 최솟값
Algoritm	:
varialbes	: atoi() 문자열을 int형으로 변환해주는함수
*********************************/
#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream instream("lab0-1.dat");
	char buffer[30];
	int num = 0;
	int min, max;
	bool isFirst = true; //처음인지 확인하는 변수
	if (!instream.is_open()) {
		cout << "" << endl;
		return 1;
	}
	while (instream >> buffer) { // buffer에 문자열을 입력받아서 문자열 값이 있으면 true 없으면 false
		int temp = atoi(buffer);
		if (isFirst) { // 처음일경우
			min = temp; //최소값 설정
			max = temp; //최댓값 설정
			isFirst = false; // 처음이 지남
		}
		min = min < temp ? min : temp; // 3항연산자
		max = max > temp ? max : temp; // 3항연산자
	}

	cout << "Max : " << max << endl << "Min : " << min<<endl; // 최대, 최소 출력

	return 0;
}
