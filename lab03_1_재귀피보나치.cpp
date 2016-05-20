/********************************
이름		: 최 준 형
학번		: 20123425
ID			: Lab03-1
Description : 피보나치 수열
Algoritm	:
varialbes	: 
*********************************/
#include<iostream>
#include<fstream>

using namespace std;
int Fibo(int n);

int main() {
	int num = 0;
	cout << "숫자 입력";
	cin >> num;
	cout << Fibo(num) << endl;

	return 0;
}

int Fibo(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (Fibo(n - 1) + Fibo(n - 2));

}
