#include <iostream>
#include <string> //string자료형 사용하기
#include <iomanip>
#include <cstring>
#include <stdlib.h>

using namespace std;

float Grading(string A);

inline void PrintMenu();

inline void InputValue(char* str)
{
	cin >> str;
};

inline void InputValue(int& i)
{
	cin >> i;
	cin.ignore(); //추가사항
};

inline void InputValue(string& A)
{
	getline(cin, A);
};

struct Subject
{
	string SubName;		// 과목이름char[30]에서 string으로 변경
	int Hakjum;				// 과목학점 
	string Grade;			// 과목등급
	float GPA;				// 과목 평점
};

struct Student //학생정보
{
	string StdName;		// 학생 이름, char[30]에서 string으로 변경
	int Hakbun;				// 학번
	struct Subject* Sub;		// 과목
	int SubNum;				// 과목 수, 4월16일 추가
	float AveGPA;			// 교과목 평균 평점
};

float CalcAveGPA(Subject* Sub, int num);

void CalcGPA(Subject& sub);

void PrintOneData(const Student& rSt);

void PrintAllData(const Student* pSt, int studentnum);

Student* StdSearch(Student* pSt, int a);//주소찾기

void PrintAllStdList(const Student* pSt, int StudentNum = 2); //학생이름,학번모두출력

//void Modify(Student* pSt); // pSt는 수정할 학생정보 포인터 매개변수, ModifyStdInfo로 확장

void ModifyStdInfo(Student* pSt, int StdNum); // 함수 추가. 신상정보와 교과목정보수정 재구현

Subject* SubSearch(const Student& pSt); //특정과목 탐색함수. ModifyStdInfo함수에 포함되어있다.

void InputData(Student* pSt, int i) //학생정보입력 모듈화
{

	cout << "이름 : ";
	InputValue(pSt[i].StdName);
	cout << "학번 : ";
	InputValue(pSt[i].Hakbun);


	printf("\n수강한 과목 %d개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n", pSt[i].SubNum);
	pSt[i].AveGPA = 0;
	int j;
	for (j = 0; j < pSt[i].SubNum; j++)
	{
		cout << "교과목명 : ";
		InputValue(pSt[i].Sub[j].SubName);
		cout << "과목학점수 : ";
		InputValue(pSt[i].Sub[j].Hakjum);
		cout << "과목등급(A+ ~ F) : ";
		InputValue(pSt[i].Sub[j].Grade);

		CalcGPA(pSt[i].Sub[j]);

		cout << "\n";
	}

	pSt[i].AveGPA = CalcAveGPA(pSt[i].Sub, pSt[i].SubNum);

	cout << "\n";

};

int main()
{
	int menn = 0;
	int studentnum, i;
	//struct Student stlist[2]; //구형 구조체 stlist. 2명만 받을수있다.

	printf("전체 학생 수를 입력하세요. : "); // studentnum에 학생수입력
	InputValue(studentnum);

	Student* stlist = new Student[studentnum];	//stlist를 동적 선언.

	while (menn != 6)
	{
		PrintMenu();
		InputValue(menn);

		if (menn == 1)
		{	//성적 입력
			for (i = 0; i < studentnum; i++) {

				printf("\n%d 번째 학생이 수강한 과목수를 입력하세요. :", i + 1);
				InputValue(stlist[i].SubNum);

				stlist[i].Sub = new Subject[stlist[i].SubNum];

				printf("\n%d 번째 학생 이름과 학번을 입력하세요.\n", i + 1);

				InputData(stlist, i);
			}
		};
		if (menn == 2)
		{
			PrintAllData(stlist, studentnum);
		};
		if (menn == 3)
		{
			Student* SearchStd;
			SearchStd = StdSearch(stlist,studentnum);
			if (SearchStd != 0)
				PrintOneData(*SearchStd);
			else
				cout << "\n정보가 없습니다.\n";
		};
		if (menn == 4)
		{
			PrintAllStdList(stlist, studentnum);
		};
		if (menn == 5)
		{
			ModifyStdInfo(stlist, studentnum);
		};
	};

	delete[] stlist;	//사용한 메모리 해제
	stlist = NULL;

	cout << ("프로그램을 종료합니다.");

	return 0;
};


inline void PrintMenu()
{
	cout << "\n===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n";
	cout << "5. 학생 정보 수정\n";
	cout << "6. 프로그램 종료\n\n";
	cout << "원하는 기능을 입력하세요. :";
};

float Grading(string A)
{
	float Gradescore = 0;
	if (A.compare("A+") == 0)
		Gradescore = 4.5;
	else if (A.compare("A0") == 0)
		Gradescore = 4.0;
	else if (A.compare("B+") == 0)
		Gradescore = 3.5;
	else if (A.compare("B0") == 0)
		Gradescore = 3.0;
	else if (A.compare("C+") == 0)
		Gradescore = 2.5;
	else if (A.compare("C0") == 0)
		Gradescore = 2.0;
	else if (A.compare("D+") == 0)
		Gradescore = 1.5;
	else if (A.compare("D0") == 0)
		Gradescore = 1.0;
	else
		Gradescore = 0;

	return Gradescore;
};

void CalcGPA(Subject& sub)
{
	float i = 0;
	i = Grading(sub.Grade);
	sub.GPA = i * sub.Hakjum;
};


float CalcAveGPA(Subject* Sub, int num)
{
	int i;
	float score = 0;
	float sol;
	for (i = 0; i < num; i++) {
		score = score + Sub[i].GPA;
	}
	sol = score / 3;
	return sol;
};

void PrintOneData(const Student& rSt)
{
	cout << "\n이름 :" << rSt.StdName << "  학번 :" << rSt.Hakbun;
	cout << "\n--------------------------------------------------\n";
	cout << "      과목명   과목학점   과목등급   과목평점\n";
	cout << "\n--------------------------------------------------\n";
	int i;
	for (i = 0; i < rSt.SubNum; i++)
	{
		cout.width(10);
		cout << rSt.Sub[i].SubName;
		cout.width(10);
		cout << rSt.Sub[i].Hakjum;
		cout.width(10);
		cout << rSt.Sub[i].Grade;
		cout.width(10);
		cout << fixed;
		cout.precision(2);
		cout << rSt.Sub[i].GPA;
		cout << "\n";
	}
	cout << "\n--------------------------------------------------";
	cout << "\n";
	cout.precision(2);
	cout << "                      평균평점 : " << rSt.AveGPA;
	cout << "\n\n";
};

void PrintAllData(const Student* pSt, int studentnum)
{
	cout << "\n\n               전체 학생 성적 보기\n--------------------------------------------------\n";
	int i;
	for (i = 0; i < studentnum; i++) {
		PrintOneData(pSt[i]);
	}
};

Student* StdSearch(Student* pSt, int a)
{
	string targetStd; //char[30]에서 string으로 변경
	Student* SearchStd;
	cout << "\n검색할 학생의 이름 : ";
	InputValue(targetStd);
	int i;
	for (i = 0; i < a; i++)
	{
		if(pSt[i].StdName.compare(targetStd)==0)
			return &pSt[i];
	}

	/*if (strcmp(pSt[0].StdName, targetStd) == 0)
		return &pSt[0];
	if (strcmp(pSt[1].StdName, targetStd) == 0)
		return &pSt[1];
	*/
	//자료 두개만있던시절 검색기능
	return NULL;
};


void PrintAllStdList(const Student* pSt, int StudentNum) //디폴트값 2 매개변수
{
	cout << "\n--------------------------------------------------";
	cout << "\n        학번          이름";
	cout << "\n--------------------------------------------------";
	int k;
	for (k = 0; k < StudentNum; k++)
	{
		cout.width(10);
		cout << "\n    " << pSt[k].Hakbun;
		cout.width(10);
		cout << "  " << pSt[k].StdName;
	};
	cout << "\n--------------------------------------------------\n";
};
/* 이전 Modify 함수 백업
void Modify(Student* pSt)
{
	int i;
	Student* SearchStd;
	cout << "\n현재 학생 수를 입력해 주세요.:";
	InputValue(i);
	SearchStd = StdSearch(pSt,i);
	if (SearchStd != 0)// 0이아니면 이름학번 수정
	{
		cout << "\n학생 이름과 학번을 입력하세요.\n"; //안내문
		cout << "이름 : ";
		InputValue(SearchStd->StdName);
		cout << "학번 : ";
		InputValue(SearchStd->Hakbun);
	}
	else
		cout << "\n정보가 없습니다.\n";
};
*/
void ModifyStdInfo(Student* pSt, int StdNum)
{
	Student* SearchStd;
	SearchStd = StdSearch(pSt, StdNum);

	if (SearchStd != 0) //0이아니면 이름학번 수정
	{
		string Type;
		cout << "\n수정(학생정보/과목정보) :";
		InputValue(Type);

		if (Type == "학생정보")
		{
			cout << "\n학생 이름과 학번을 입력하세요.\n"; //안내문
			cout << "이름 : ";
			InputValue(SearchStd->StdName);
			cout << "학번 : ";
			InputValue(SearchStd->Hakbun);
		}
		else if (Type == "과목정보")
		{
			Subject* SearchSub = SubSearch(SearchStd[0]);   // 교과목 탐색
			// 과목 탐색하고 수정하는 부분
			// 과목의 등급과 학점수가 바뀌면 평점도 바뀐다. 
			if(SearchSub == NULL)
				cout << "\n과목이 존재하지 않습니다.";
			else
			{
				cout << "\n교과목명 : ";
				InputValue(SearchSub->SubName);
				cout << "과목학점수 : ";
				InputValue(SearchSub->Hakjum);
				cout << "과목등급(A+ ~ F) : ";
				InputValue(SearchSub->Grade);

				CalcGPA(*SearchSub);

				cout << "\n";


				SearchStd->AveGPA = CalcAveGPA(SearchStd->Sub, SearchStd->SubNum);
			}


		}
	}
	else
		cout << "\n정보가 없습니다.\n";

};

Subject* SubSearch(const Student& pSt) {
	string tempSubName; 
	Student SearchStd = pSt;
	cout << "\n검색할 과목 이름:";
	InputValue(tempSubName);
	int i = 0;
	int cnt = -1;
	for(i=0;i<SearchStd.SubNum;i++)
	{
		if (SearchStd.Sub[i].SubName.compare(tempSubName)==0) {
			cnt = i;
			break;
		}
	}
	if (cnt == -1)
	{
		return NULL;
	}
	else
	{
		cout << "\n*(" << SearchStd.Sub[cnt].SubName << ", 학점 :" << SearchStd.Sub[cnt].Hakjum << ", 등급 :" << SearchStd.Sub[cnt].Grade << ")의 정보를 수정하세요.";
		return &pSt.Sub[cnt];
	}
};
