#pragma once
#include <iostream>
#include <string>
#include <cstring>
typedef struct test {
	struct question* question;
	int* result;//результаты пользователей
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
	int value;//количество баллов за вопрос
};
typedef struct user {
	int login, password;
	char* name;
	struct group* group;
};

group makegroup(const char* name); //создание группы
user makeuser(int login, int password, const char* name);//создание пользователя
discipline makediscip(const char* name);//создание дисциплины
question makequestion(const char* text, const char* answer, int value);//создание вопроса
question* qsts(int n, question a, ...);
test maketest(question questions[], discipline* disc, int n, const char* name);//создание теста

int adddisc(group* group,discipline* disc);//добавление дисциплины в группу
int addgroup(discipline* disc, group* gr);//добавление группы в дисциплину
int adduser(group* group, user* student);//добавление пользователя в группу
int addtest(discipline* disc, test* tst,double multiplier);//добавление теста в дисциплину
int addresult(test* test, int login, int result);//запись результата пользователя

void rnuser(user* student, const char* name);
void rndisc(discipline* disc, const char* name);
void rntest(test* test, const char* name);
void rngroup(group* gr, const char* name);
void changepass(user* student, int password);
void movuser(user* student, group* gr);
void changequestion(question* qs, const char* text, const char* answer, int value);
void deldisc(group* gr, int numberdiscip);
void delstudent(group* gr, int numberuser);
void deltest(discipline* disc, int numbertest);
void delgroup(discipline* disc, int numbergroup);

void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);