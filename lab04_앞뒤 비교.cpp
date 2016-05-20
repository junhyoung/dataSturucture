/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : Lab04
* Description: 앞에서 부터 읽은것과 뒤에서부터 읽은것이 같은지 비교
* Algorithm : 스택에 스트링의 반을 넣고 팝을하면서 나머지의 스트링과 같은지 비교
* Variables:
* x:
**********************************************************/
#include<iostream>
#include<fstream>
#include"Stack.h"
using namespace std;

void main() {
	ifstream instream("lab04.dat");

	char arr[100]; //String 저장용 변수

	while (instream >> arr) {
		int index = 0; //인덱스 관리용 변수
		int size = 100; //임의의 사이즈 100설정
		Stack S(size); //Stack class 변수 생성
		bool isTrue = true;//참 거짓 판별 변수
		int len = strlen(arr);//String의 길이

		if (len % 2 == 0) { //string의 길이가 짜굿이면
			while (index < (len / 2))  //반을 Stack에 입력
				S.push(arr[index++]);
		}
		else { //String의 길이가 홀수이면
			while (index < (len / 2)) //반을 Stack에 입력 
				S.push(arr[index++]);
			index++; //가운데 String을 통과
		}

		while (arr[index]) { //나머지 String을 스택에들어있는 순서대로 비교
			if (arr[index] == S.pop()) //같으면 다음 비교
				index++;
			else {  //다르면 isTrue가 거짓
				isTrue = false;
				break;
			}
		}
		if (isTrue)
			cout << arr << " a palindrome" << endl;
		else
			cout << arr << " not a palindrome" << endl;
	}
}
