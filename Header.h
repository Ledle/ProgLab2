#pragma once
#include <iostream>
#include <string>
#include <cstring>
typedef struct test {
	struct question* question;
	int* result;//���������� �������������
	struct discipline* discipline;
	int nres,nquests;
	char* name;
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
	char* name;
	struct group* group;
};

group makegroup(const char* name); //�������� ������
user makeuser(int login, int password, const char* name);//�������� ������������
discipline makediscip(const char* name);//�������� ����������
question makequestion(const char* text, const char* answer, int value);//�������� �������
question* qsts(int n, question a, ...);
test maketest(question questions[], discipline* disc, int n, const char* name);//�������� �����

int adddisc(group* group,discipline* disc);//���������� ���������� � ������
int addgroup(discipline* disc, group* gr);//���������� ������ � ����������
int adduser(group* group, user* student);//���������� ������������ � ������
int addtest(discipline* disc, test* tst,double multiplier);//���������� ����� � ����������
int addresult(test* test, int login, int result);//������ ���������� ������������

void rnuser(user* student, const char* name);//������������� ������������
void rndisc(discipline* disc, const char* name);//������������� ����������
void rntest(test* test, const char* name);//������������� ����
void rngroup(group* gr, const char* name);//������������� ������
void changepass(user* student, int password);//������� ������ ������������
void movuser(user* student, group* gr);//������� ������ ������������
void changequestion(question* qs, const char* text, const char* answer, int value);//�������� ������ � �����
void deldisc(group* gr, int numberdiscip);//������� ���������� �� ������
void delstudent(group* gr, int numberuser);//������� �������� �� ������
void deltest(discipline* disc, int numbertest);//������� ���� �� ����������
void delgroup(discipline* disc, int numbergroup);//������� ������ �� ����������

void showgroup(group group);//����� ������ � �������
void showdiscip(discipline disc);//����� ���������� � �������
void showtest(test test);//����� ����� � �������
void showuser(user student);//����� ������������ � �������
void showquestion(question quest);//����� ������� � �������

group inpgroup(group* thisgroup);
user* inpuser(group* gr);
discipline inpdiscip();
question inpquestion();
test inptest(discipline* disc);