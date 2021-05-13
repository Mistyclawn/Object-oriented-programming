#include <iostream>
#include <string>

#include "Student.h"
#include "Subject.h"

using namespace std;

inline void InputValue(int& i){
	cin >> i;
	cin.ignore();
};
inline void InputValue(string& A){
	getline(cin, A);
};

int menu_select();

int main() {

	int menn = 0;
	int studentnum = 1, i;
	Student* stlist = new Student[studentnum];
	while (menn != 3)
	{
		menn = menu_select();
		if (menn == 1)
		{
			printf("\n학생 수 입력 : "); // studentnum에 학생수입력
			InputValue(studentnum);
			stlist = new Student[studentnum];	//stlist를 if문 안에서 선언하면 안된다. 절대로.
			// Studen* stlist = ...으로 선언해버리면 if문 안에서 새로 선언한것과 마찬가지이므로 if문을 빠져나갈때
			// 메모리가 해제되어 버린다. 즉, 선언은 if문 밖에서 하고 내용물을 안쪽에서 입력시켜야 한다. 잊지말자
			for (i = 0; i < studentnum; i++)
				stlist[i].Initialize();

			for (i = 0; i < studentnum; i++) {
				cout << i + 1 << "번째 학생 이름과 학번과 과목수를 입력하세요.\n";
				stlist[i].InputData();
				cout << "\n";
				stlist[i].CalcAveGPA();
			}
		}

		//stlist->PrintData(); //if문 밖에서 프린트 테스트
		if (menn == 2)
		{
			cout << "\n\n               전체 학생 성적 보기\n--------------------------------------------------\n";
			int i;
			for (i = 0; i < studentnum; i++) {
				stlist[i].PrintData();
			}
		}
	};

	cout << ("프로그램을 종료합니다.");
	return 0;
};

int menu_select(){
	int menn;
	cout << "\n===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 프로그램 종료\n\n";
	cout << "원하는 기능을 입력하세요. :";
	InputValue(menn);
	return menn;
};