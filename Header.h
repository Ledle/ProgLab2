#pragma once
#include <iostream>
#include <string>
typedef struct test {
	struct question* question;
	int* result;//���������� �������������
	struct discipline** discipline;
};
typedef struct discipline {
	struct test** test;
	double* multiplier; //������������ ������ ��� �������� ��������
	struct group** groups;
	int n;
	char* name;
};
typedef struct group {
	struct user** students;
	struct discipline** disciplines;
};
typedef struct question {
	char* text,*answer;
	int value;//���������� ������ �� ������
};
typedef struct user {
	int login, password;
	const char* name;
	struct group* group;
};

int starttest(test test, user student);//maybe
user makeuser(int login, int password, group* group, const char* name);//�������� ������������
discipline makediscip(test* tests, double* multiplier,int n);//�������� ����������
question makequestion(char* text, char* answer, int value);//�������� �������
test maketest(question questions[]);//�������� �����
bool addgroup(discipline* disc, group* group);//���������� ������ � ����������
bool adduser(group* group, user students[], int n = 1);//���������� ������������ � ������
int addtest(discipline* disc, test* test,int multiplier);//���������� ����� � ����������
int addresult(test* test, int login, int result);//������ ���������� ������������
void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);