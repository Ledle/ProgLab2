#pragma once
#include <iostream>
#include <string>
typedef struct test {
	struct question* question;
	int* result;//результаты пользователей
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
	int value;//количество баллов за вопрос
};
typedef struct user {
	int login, password;
	const char* name;
	struct group* group;
};

group makegroup(const char* name); //создание группы
user makeuser(int login, int password, const char* name);//создание пользователя
discipline makediscip(const char* name);//создание дисциплины
question makequestion(const char* text, const char* answer, int value);//создание вопроса
question* qsts(int n, question a, ...);
test maketest(question questions[], discipline* disc, int n);//создание теста

int adddisc(group* group,discipline* disc);//добавление дисциплины в группу
int addgroup(discipline* disc, group* gr);//добавление группы в дисциплину
int adduser(group* group, user* student);//добавление пользователя в группу
int addtest(discipline* disc, test* tst,double multiplier);//добавление теста в дисциплину
int addresult(test* test, int login, int result);//запись результата пользователя

void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);