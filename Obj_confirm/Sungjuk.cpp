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
			printf("\n�л� �� �Է� : "); // studentnum�� �л����Է�
			InputValue(studentnum);
			stlist = new Student[studentnum];	//stlist�� if�� �ȿ��� �����ϸ� �ȵȴ�. �����.
			// Studen* stlist = ...���� �����ع����� if�� �ȿ��� ���� �����ѰͰ� ���������̹Ƿ� if���� ����������
			// �޸𸮰� �����Ǿ� ������. ��, ������ if�� �ۿ��� �ϰ� ���빰�� ���ʿ��� �Է½��Ѿ� �Ѵ�. ��������
			for (i = 0; i < studentnum; i++)
				stlist[i].Initialize();

			for (i = 0; i < studentnum; i++) {
				cout << i + 1 << "��° �л� �̸��� �й��� ������� �Է��ϼ���.\n";
				stlist[i].InputData();
				cout << "\n";
				stlist[i].CalcAveGPA();
			}
		}

		//stlist->PrintData(); //if�� �ۿ��� ����Ʈ �׽�Ʈ
		if (menn == 2)
		{
			cout << "\n\n               ��ü �л� ���� ����\n--------------------------------------------------\n";
			int i;
			for (i = 0; i < studentnum; i++) {
				stlist[i].PrintData();
			}
		}
	};

	cout << ("���α׷��� �����մϴ�.");
	return 0;
};

int menu_select(){
	int menn;
	cout << "\n===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ���. :";
	InputValue(menn);
	return menn;
};