#include <string>
#include <iostream>
#include "Subject.h"

#ifndef STUDENT_H
#define STUDENT_H

class Subject;

class Student{
protected:
	std::string _StdName; // �̸�
	int _Hakbun; // �й�
	int _SubNum; // �����
	Subject* _Sub; // ���� Ŭ����
	float _AveGPA;// ��� ����

private:
	void InputValue(int& i);
	void InputValue(std::string& A);

public:
	void Initialize(); // (ȫ�浿, 2019000000, 1)
	void Initialize(std::string, int, int); // �̸�, �й�, ����� �ʱ�ȭ
	void Remove(); // �����޸� ���� (_Sub)
	void InputData(); // ������� �� �Է�
	void PrintData() const; // ������� �� ���
	void CalcAveGPA(); // ��� ���� ���
};


#endif