#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"
#include <iostream>

user makeuser(int login, int password, group* group, const char* name) {
	user user;
	user.login = login;
	user.password = password;
	user.group = group;
	user.name = name;
	return user;
}
discipline makediscip(test** tests, double* multiplier, int n,const char* name) {
	discipline disc;
	disc.test = (test**)malloc(sizeof(test*)*n);
	memcpy(disc.test, tests, sizeof(test*) * n);
	disc.multiplier = (double*)malloc(sizeof(double*) * n);
	memcpy(disc.multiplier, multiplier, sizeof(double*) * n);
	disc.n = n;
	disc.name = (char*)malloc(sizeof(name));
	strcpy(disc.name, name);
	return disc;
}
question makequestion(const char* text, const char* answer, int value);//�������� �������
test maketest(question questions[]);//�������� �����
bool addgroup(discipline* disc, group* group);//���������� ������ � ����������
bool adduser(group* group, user students[]);//���������� ������������ � ������
int addtest(discipline* disc, test* test, int multiplier);//���������� ����� � ����������
int addresult(test* test, int login, int result);//������ ���������� ������������
void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);