#include <iostream>
#include <string>

#include "Student.h"

using namespace std;

void Student::InputValue(int& i) {
	cin >> i;
	cin.ignore();
}
void Student::InputValue(string& A) {
	getline(cin, A);
}

void Student::Initialize() {
	_StdName = "홍길동"; // 이름
	_Hakbun = 2019000000; // 학번
	_SubNum = 1; // 과목수
}
void Student::Initialize(string A, int B, int C) {
	_StdName = A; // 이름
	_Hakbun = B; // 학번
	_SubNum = C; // 과목수
}
void Student::Remove() {
	delete _Sub;
}
void Student::InputData() {
	cout << "이름 : ";
	InputValue(_StdName);
	cout << "학번 : ";
	InputValue(_Hakbun);
	cout << "과목수 : ";
	InputValue(_SubNum);
	_Sub = new Subject[_SubNum];
	cout << "수강한 과목 " << _SubNum << "개의 각 교과목명, 과목학점수와 과목등급을 입력하세요.\n";
	int i;
	for (i = 0; i < _SubNum; i++) {
		_Sub[i].InputData();
		_Sub[i].CalcGPA();
	}
}
void Student::PrintData() const {
	cout << "\n이름 : " << _StdName << "  학번 : " << _Hakbun<<"\n";// << "  과목수 :" << _SubNum << //빼놓자
	cout << "\n==================================================\n      과목명        과목학점   과목등급   과목평점\n==================================================\n";
	int i;
	for (i = 0; i < _SubNum; i++)
	{
		_Sub[i].PrintData();
	}
	cout << "==================================================\n";
	cout.precision(2);
	cout.width(45);
	cout << "평균평점 : " << _AveGPA << "\n\n";
}
void Student::CalcAveGPA() {
	int i;
	float temp;
	float score = 0;
	for (i = 0; i < _SubNum; i++) {
		temp = _Sub[i].GetGPA();
		score = score + temp;
	}
	_AveGPA = score / 3;
}
