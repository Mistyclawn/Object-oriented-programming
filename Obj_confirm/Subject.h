#include <iostream>
#include <string>

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject{
protected:
	std::string SubName;			// �����̸�
	int Hakjum;				// �������� 
	std::string Grade;			// ������
	float GPA;				// ���� ����

private:
	void InputValue(int& i);
	void InputValue(std::string& A);

public:
	void Initialize();						// ������� �ʱ�ȭ(����, 3, A)
	void Initialize(std::string, int, std::string);	// ���ڰ����� ������� �ʱ�ȭ
	void InputData();						// ������� �� �Է�
	void PrintData() const;					// ������� �� ���
	void CalcGPA();							// ���� ���
	float GetGPA();							// ���� ��ȯ
}; 

#endif