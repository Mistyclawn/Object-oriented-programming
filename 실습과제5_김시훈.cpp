#include <iostream>
#include <string> //string�ڷ��� ����ϱ�
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
	cin.ignore(); //�߰�����
};

inline void InputValue(string& A)
{
	getline(cin, A);
};

struct Subject
{
	string SubName;		// �����̸�char[30]���� string���� ����
	int Hakjum;				// �������� 
	string Grade;			// ������
	float GPA;				// ���� ����
};

struct Student //�л�����
{
	string StdName;		// �л� �̸�, char[30]���� string���� ����
	int Hakbun;				// �й�
	struct Subject* Sub;		// ����
	int SubNum;				// ���� ��, 4��16�� �߰�
	float AveGPA;			// ������ ��� ����
};

float CalcAveGPA(Subject* Sub, int num);

void CalcGPA(Subject& sub);

void PrintOneData(const Student& rSt);

void PrintAllData(const Student* pSt, int studentnum);

Student* StdSearch(Student* pSt, int a);//�ּ�ã��

void PrintAllStdList(const Student* pSt, int StudentNum = 2); //�л��̸�,�й�������

//void Modify(Student* pSt); // pSt�� ������ �л����� ������ �Ű�����, ModifyStdInfo�� Ȯ��

void ModifyStdInfo(Student* pSt, int StdNum); // �Լ� �߰�. �Ż������� �������������� �籸��

Subject* SubSearch(const Student& pSt); //Ư������ Ž���Լ�. ModifyStdInfo�Լ��� ���ԵǾ��ִ�.

void InputData(Student* pSt, int i) //�л������Է� ���ȭ
{

	cout << "�̸� : ";
	InputValue(pSt[i].StdName);
	cout << "�й� : ";
	InputValue(pSt[i].Hakbun);


	printf("\n������ ���� %d���� �� �������, ��������, �������� �Է��ϼ���.\n", pSt[i].SubNum);
	pSt[i].AveGPA = 0;
	int j;
	for (j = 0; j < pSt[i].SubNum; j++)
	{
		cout << "������� : ";
		InputValue(pSt[i].Sub[j].SubName);
		cout << "���������� : ";
		InputValue(pSt[i].Sub[j].Hakjum);
		cout << "������(A+ ~ F) : ";
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
	//struct Student stlist[2]; //���� ����ü stlist. 2�� �������ִ�.

	printf("��ü �л� ���� �Է��ϼ���. : "); // studentnum�� �л����Է�
	InputValue(studentnum);

	Student* stlist = new Student[studentnum];	//stlist�� ���� ����.

	while (menn != 6)
	{
		PrintMenu();
		InputValue(menn);

		if (menn == 1)
		{	//���� �Է�
			for (i = 0; i < studentnum; i++) {

				printf("\n%d ��° �л��� ������ ������� �Է��ϼ���. :", i + 1);
				InputValue(stlist[i].SubNum);

				stlist[i].Sub = new Subject[stlist[i].SubNum];

				printf("\n%d ��° �л� �̸��� �й��� �Է��ϼ���.\n", i + 1);

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
				cout << "\n������ �����ϴ�.\n";
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

	delete[] stlist;	//����� �޸� ����
	stlist = NULL;

	cout << ("���α׷��� �����մϴ�.");

	return 0;
};


inline void PrintMenu()
{
	cout << "\n===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ��ü �л� ��� ����\n";
	cout << "5. �л� ���� ����\n";
	cout << "6. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ���. :";
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
	cout << "\n�̸� :" << rSt.StdName << "  �й� :" << rSt.Hakbun;
	cout << "\n--------------------------------------------------\n";
	cout << "      �����   ��������   ������   ��������\n";
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
	cout << "                      ������� : " << rSt.AveGPA;
	cout << "\n\n";
};

void PrintAllData(const Student* pSt, int studentnum)
{
	cout << "\n\n               ��ü �л� ���� ����\n--------------------------------------------------\n";
	int i;
	for (i = 0; i < studentnum; i++) {
		PrintOneData(pSt[i]);
	}
};

Student* StdSearch(Student* pSt, int a)
{
	string targetStd; //char[30]���� string���� ����
	Student* SearchStd;
	cout << "\n�˻��� �л��� �̸� : ";
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
	//�ڷ� �ΰ����ִ����� �˻����
	return NULL;
};


void PrintAllStdList(const Student* pSt, int StudentNum) //����Ʈ�� 2 �Ű�����
{
	cout << "\n--------------------------------------------------";
	cout << "\n        �й�          �̸�";
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
/* ���� Modify �Լ� ���
void Modify(Student* pSt)
{
	int i;
	Student* SearchStd;
	cout << "\n���� �л� ���� �Է��� �ּ���.:";
	InputValue(i);
	SearchStd = StdSearch(pSt,i);
	if (SearchStd != 0)// 0�̾ƴϸ� �̸��й� ����
	{
		cout << "\n�л� �̸��� �й��� �Է��ϼ���.\n"; //�ȳ���
		cout << "�̸� : ";
		InputValue(SearchStd->StdName);
		cout << "�й� : ";
		InputValue(SearchStd->Hakbun);
	}
	else
		cout << "\n������ �����ϴ�.\n";
};
*/
void ModifyStdInfo(Student* pSt, int StdNum)
{
	Student* SearchStd;
	SearchStd = StdSearch(pSt, StdNum);

	if (SearchStd != 0) //0�̾ƴϸ� �̸��й� ����
	{
		string Type;
		cout << "\n����(�л�����/��������) :";
		InputValue(Type);

		if (Type == "�л�����")
		{
			cout << "\n�л� �̸��� �й��� �Է��ϼ���.\n"; //�ȳ���
			cout << "�̸� : ";
			InputValue(SearchStd->StdName);
			cout << "�й� : ";
			InputValue(SearchStd->Hakbun);
		}
		else if (Type == "��������")
		{
			Subject* SearchSub = SubSearch(SearchStd[0]);   // ������ Ž��
			// ���� Ž���ϰ� �����ϴ� �κ�
			// ������ ��ް� �������� �ٲ�� ������ �ٲ��. 
			if(SearchSub == NULL)
				cout << "\n������ �������� �ʽ��ϴ�.";
			else
			{
				cout << "\n������� : ";
				InputValue(SearchSub->SubName);
				cout << "���������� : ";
				InputValue(SearchSub->Hakjum);
				cout << "������(A+ ~ F) : ";
				InputValue(SearchSub->Grade);

				CalcGPA(*SearchSub);

				cout << "\n";


				SearchStd->AveGPA = CalcAveGPA(SearchStd->Sub, SearchStd->SubNum);
			}


		}
	}
	else
		cout << "\n������ �����ϴ�.\n";

};

Subject* SubSearch(const Student& pSt) {
	string tempSubName; 
	Student SearchStd = pSt;
	cout << "\n�˻��� ���� �̸�:";
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
		cout << "\n*(" << SearchStd.Sub[cnt].SubName << ", ���� :" << SearchStd.Sub[cnt].Hakjum << ", ��� :" << SearchStd.Sub[cnt].Grade << ")�� ������ �����ϼ���.";
		return &pSt.Sub[cnt];
	}
};