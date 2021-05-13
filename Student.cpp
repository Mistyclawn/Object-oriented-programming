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
	_StdName = "ȫ�浿"; // �̸�
	_Hakbun = 2019000000; // �й�
	_SubNum = 1; // �����
}
void Student::Initialize(string A, int B, int C) {
	_StdName = A; // �̸�
	_Hakbun = B; // �й�
	_SubNum = C; // �����
}
void Student::Remove() {
	delete _Sub;
}
void Student::InputData() {
	cout << "�̸� : ";
	InputValue(_StdName);
	cout << "�й� : ";
	InputValue(_Hakbun);
	cout << "����� : ";
	InputValue(_SubNum);
	_Sub = new Subject[_SubNum];
	cout << "������ ���� " << _SubNum << "���� �� �������, ������������ �������� �Է��ϼ���.\n";
	int i;
	for (i = 0; i < _SubNum; i++) {
		_Sub[i].InputData();
		_Sub[i].CalcGPA();
	}
}
void Student::PrintData() const {
	cout << "\n�̸� : " << _StdName << "  �й� : " << _Hakbun<<"\n";// << "  ����� :" << _SubNum << //������
	cout << "\n==================================================\n      �����        ��������   ������   ��������\n==================================================\n";
	int i;
	for (i = 0; i < _SubNum; i++)
	{
		_Sub[i].PrintData();
	}
	cout << "==================================================\n";
	cout.precision(2);
	cout.width(45);
	cout << "������� : " << _AveGPA << "\n\n";
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
