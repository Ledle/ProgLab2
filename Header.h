#pragma once
#include <iostream>
#include <string>
typedef struct test {
	struct question* question;
	int* result;//���������� �������������
	struct discipline* discipline;
	int n;
};
typedef struct discipline {
	struct test** test;
	double* multiplier; //������������ ������ ��� �������� ��������
	struct group** groups;
	int nstudents,ngroups;
	char* name;
};
typedef struct group {
	struct user** students;
	struct discipline** disciplines;
	int nstudents,ndiscips;
	char* name;
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
test maketest(question questions[], discipline* disc, int n);//�������� �����
int adddisc(group* group,discipline* disc);//���������� ���������� � ������
int addgroup(discipline* disc, group* gr);//���������� ������ � ����������
int adduser(group* group, user* student);//���������� ������������ � ������
int addtest(discipline* disc, test* test,int multiplier);//���������� ����� � ����������
int addresult(test* test, int login, int result);//������ ���������� ������������
void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);