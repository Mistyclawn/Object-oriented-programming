#include <iostream>
#include <string>

#include "Subject.h"

using namespace std;

void Subject::InputValue(int& i) {
	cin >> i;
	cin.ignore();
}
void Subject::InputValue(string& A) {
	getline(cin, A);
}

void Subject::Initialize() {
	SubName = "����";
	Hakjum = 3;
	Grade = "A";
}

void Subject::Initialize(string A, int B, string C) {
	SubName = A;
	Hakjum = B;
	Grade = C;
}

void Subject::InputData() {
	cout << "������� : ";
	InputValue(SubName);
	cout << "���������� : ";
	InputValue(Hakjum);
	cout << "������(A+ ~ F) : ";
	InputValue(Grade);
	cout << "\n";
}
void Subject::PrintData() const {

	cout.width(18);
	cout << SubName;
	cout.width(10);
	cout << Hakjum;
	cout.width(10);
	cout << Grade;
	cout.width(10);
	cout << fixed;
	cout.precision(2);
	cout << GPA;
	cout << "\n";
}				// ������� �� ���

void Subject::CalcGPA() {
	float Gradescore = 0;
	if (Grade.compare("A+") == 0)
		Gradescore = 4.5;
	else if (Grade.compare("A0") == 0)
		Gradescore = 4.0;
	else if (Grade.compare("B+") == 0)
		Gradescore = 3.5;
	else if (Grade.compare("B0") == 0)
		Gradescore = 3.0;
	else if (Grade.compare("C+") == 0)
		Gradescore = 2.5;
	else if (Grade.compare("C0") == 0)
		Gradescore = 2.0;
	else if (Grade.compare("D+") == 0)
		Gradescore = 1.5;
	else if (Grade.compare("D0") == 0)
		Gradescore = 1.0;
	else
		Gradescore = 0;

	GPA = Gradescore * Hakjum;
}						// ���� ���, ���� �ǽ������� CalcGPA �Լ��� Grading �Լ��� ��

float Subject::GetGPA() {
	return GPA;
}						// ���� ��ȯ

