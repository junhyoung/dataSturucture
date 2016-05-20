/********************************
    이름		: 최 준 형
	학번		: 20123425
	ID			: Lab0
	Description : 문장을 입력받아 글자수를 세고 단어별로 출력
	Algoritm	: 
	varialbes	: num 단어의 갯수
				  buffer 단어저장용 스트링
*********************************/
#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream instream("lab0.dat");
	char buffer[30];
	int num = 0;
	if (!instream.is_open()) {
		cout << "" << endl;
		return 1;
	}

	while (instream >> buffer) { // buffer에 문자열을 입력받아서 문자열 값이 있으면 true 없으면 false
		cout << buffer << endl; 

		num++;
	}

	cout << "words count = " << num << endl;
	
	return 0;
}
