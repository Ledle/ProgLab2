#pragma once
struct question;
struct discipline;
typedef struct test {
	struct question* question;
	int* result;//���������� �������������
	struct discipline* discipline;
	int nres, nquests;
	char* name;
};
test maketest(question questions[], int n, const char* name);//�������� �����
int addresult(test* test, int login, int result);//������ ���������� ������������
void rntest(test* test, const char* name);//������������� ����
test inptest(discipline* disc);//���� ����� � �������
void showtest(test test);//����� ����� � �������