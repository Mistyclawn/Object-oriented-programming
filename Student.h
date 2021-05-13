#include <string>
#include <iostream>
#include "Subject.h"

#ifndef STUDENT_H
#define STUDENT_H

class Subject;

class Student{
protected:
	std::string _StdName; // 이름
	int _Hakbun; // 학번
	int _SubNum; // 과목수
	Subject* _Sub; // 과목 클래스
	float _AveGPA;// 평균 평점

private:
	void InputValue(int& i);
	void InputValue(std::string& A);

public:
	void Initialize(); // (홍길동, 2019000000, 1)
	void Initialize(std::string, int, int); // 이름, 학번, 과목수 초기화
	void Remove(); // 동적메모리 해제 (_Sub)
	void InputData(); // 멤버변수 값 입력
	void PrintData() const; // 멤버변수 값 출력
	void CalcAveGPA(); // 평균 평점 계산
};


#endif