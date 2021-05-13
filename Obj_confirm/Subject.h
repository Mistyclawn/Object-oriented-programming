#include <iostream>
#include <string>

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject{
protected:
	std::string SubName;			// 과목이름
	int Hakjum;				// 과목학점 
	std::string Grade;			// 과목등급
	float GPA;				// 과목 평점

private:
	void InputValue(int& i);
	void InputValue(std::string& A);

public:
	void Initialize();						// 멤버변수 초기화(국어, 3, A)
	void Initialize(std::string, int, std::string);	// 인자값으로 멤버변수 초기화
	void InputData();						// 멤버변수 값 입력
	void PrintData() const;					// 멤버변수 값 출력
	void CalcGPA();							// 평점 계산
	float GetGPA();							// 평점 반환
}; 

#endif