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
discipline makediscip(test** tests, double* multiplier) {
	discipline disc;
	disc.test = tests;
	disc.multiplier = multiplier;
}
question makequestion(const char* text, const char* answer, int value);//�������� �������
test maketest(question questions[]);//�������� �����
bool addgroup(discipline* disc, group* group);//���������� ������ � ����������
bool adduser(group* group, user students[], int n = 1);//���������� ������������ � ������
int addtest(discipline* disc, test* test, int multiplier);//���������� ����� � ����������
int addresult(test* test, int login, int result);//������ ���������� ������������
void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);