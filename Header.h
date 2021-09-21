#pragma once
#include <iostream>
#include <string>
typedef struct test {
	struct question* question;
	int* result;//���������� �������������
	struct discipline* discipline;
	int nres,nquests;
};
typedef struct discipline {
	struct test** test;
	struct group** groups;
	int ntests,ngroups;
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

group makegroup(const char* name); //�������� ������
user makeuser(int login, int password, const char* name);//�������� ������������
discipline makediscip(const char* name);//�������� ����������
question makequestion(const char* text, const char* answer, int value);//�������� �������
question* qsts(int n, question a, ...);
test maketest(question questions[], discipline* disc, int n);//�������� �����

int adddisc(group* group,discipline* disc);//���������� ���������� � ������
int addgroup(discipline* disc, group* gr);//���������� ������ � ����������
int adduser(group* group, user* student);//���������� ������������ � ������
int addtest(discipline* disc, test* tst,double multiplier);//���������� ����� � ����������
int addresult(test* test, int login, int result);//������ ���������� ������������

void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);