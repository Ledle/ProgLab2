#pragma once
typedef struct user {
	int login,password;
	const char* name;
	group* group;
};
typedef struct discipline {
	test** test;
	double* multiplier; //������������ ������ ��� �������� ��������
	group** groups;
};
typedef struct group {
	user** students;
	discipline** disciplines;
};
typedef struct question {
	const char* text,answer;
	int value;//���������� ������ �� ������
};
typedef struct test {
	question* question;
	int* result;//���������� �������������
	discipline** discipline;
};

int starttest(test test, user student);//maybe
user makeuser(int login, int password, group* group, const char* name);//�������� ������������
discipline makediscip(test* tests, double* multiplier);//�������� ����������
question makequestion(const char* text, const char* answer, int value);//�������� �������
test maketest(question questions[]);//�������� �����
bool addgroup(discipline* disc, group* group);//���������� ������ � ����������
bool adduser(group* group, user students[], int n = 1);//���������� ������������ � ������
int addtest(discipline* disc, test* test,int multiplier);//���������� ����� � ����������
int addresult(test* test, int login, int result);//������ ���������� ������������
void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);