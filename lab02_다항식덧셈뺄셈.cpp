/********************************
이름		: 최 준 형
학번		: 20123425
ID			: Lab02
Description : 다항식의 덧셈 뺄셈
Algoritm	:
*********************************/
#include <iostream>
#include <fstream>

using namespace std;

#define MAX_TERMS 100

typedef struct {
	float coef;
	int expon;
} Poly;

Poly poly[MAX_TERMS];
int startA, finishA, startB, finishB, startD, finishD, avail;

void padd(int starta, int finisha, int startb, int finishb, int * startd, int * finishd);
void psub(int starta, int finisha, int startb, int finishb, int * startd, int * finishd);
int COMPARE(int x, int y);
void attach(float coefficient, int exponent);

int main()
{
	avail = startA = 0;

	float x;
	int y;
	int as;

	cout << "더하기 1, 빼기 2";
	cin >> as;

	while (1) {
		cin >> x >> y;

		poly[avail].coef = x;
		poly[avail].expon = y;

		avail++;

		if (y == 0) {
			finishA = avail - 1;
			startB = avail;
			break;
		}
	}

	while (1) {
		cin >> x >> y;

		poly[avail].coef = x;
		poly[avail].expon = y;

		avail++;

		if (y == 0) {
			finishB = avail - 1;
			break;
		}
	}

	if (as == 1)
		padd(startA, finishA, startB, finishB, &startD, &finishD);
	else
		psub(startA, finishA, startB, finishB, &startD, &finishD);

	for (int i = startD; i <= finishD; i++) {

		if (poly[i].expon == 0)
		{
			cout << poly[i].coef << " ";
			continue;
		}

		cout << poly[i].expon << " ";
	}

	return 0;
}

void padd(int starta, int finisha, int startb, int finishb, int * startd, int * finishd) {
	float coefficient;
	*startd = avail;

	while (starta <= finisha && startb <= finishb) {

		switch (COMPARE(poly[starta].expon, poly[startb].expon))
		{
		case -1:
			attach(poly[startb].coef, poly[startb].expon);
			startb++;
			break;
		case 0:
			coefficient = poly[starta].coef + poly[startb].coef;
			if (coefficient)
				attach(coefficient, poly[starta].expon);
			starta++;
			startb++;
			break;
		case 1:
			attach(poly[starta].coef, poly[starta].expon);
			starta++;
		}
	}

	for (; starta <= finisha; starta++)
		attach(poly[starta].coef, poly[starta].expon);

	for (; startb <= finishb; startb++)
		attach(poly[startb].coef, poly[startb].expon);

	*finishd = avail - 1;
}

void psub(int starta, int finisha, int startb, int finishb, int * startd, int * finishd) {
	float coefficient;
	*startd = avail;

	while (starta <= finisha && startb <= finishb) {

		switch (COMPARE(poly[starta].expon, poly[startb].expon))
		{
		case -1:
			attach(poly[startb].coef, poly[startb].expon);
			startb++;
			break;
		case 0:
			coefficient = poly[starta].coef - poly[startb].coef;
			if (coefficient || poly[starta].expon == 0 || poly[startb].expon == 0)
				attach(coefficient, poly[starta].expon);
			starta++;
			startb++;
			break;
		case 1:
			attach(poly[starta].coef, poly[starta].expon);
			starta++;
		}
	}

	for (; starta <= finisha; starta++)
		attach(poly[starta].coef, poly[starta].expon);

	for (; startb <= finishb; startb++)
		attach(poly[startb].coef, poly[startb].expon);

	*finishd = avail - 1;
}

int COMPARE(int x, int y)
{
	if (x > y) return 1;
	else if (x < y) return -1;
	else return 0;
}

void attach(float coefficient, int exponent) {
	if (avail >= MAX_TERMS) {
		cout << "항이 너무 많다." << endl;
		exit(1);
	}
	poly[avail++].coef = coefficient;
	poly[avail++].expon = exponent;
}
