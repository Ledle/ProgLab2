#pragma once
#include <iostream>
#include <string>
typedef struct test {
	struct question* question;
	int* result;//результаты пользователей
	struct discipline* discipline;
	int n;
};
typedef struct discipline {
	struct test** test;
	double* multiplier; //коэффициенты тестов для подсчёта рейтинга
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
	int value;//количество баллов за вопрос
};
typedef struct user {
	int login, password;
	const char* name;
	struct group* group;
};

int starttest(test test, user student);//maybe
user makeuser(int login, int password, group* group, const char* name);//создание пользователя
discipline makediscip(test* tests, double* multiplier,int n);//создание дисциплины
question makequestion(char* text, char* answer, int value);//создание вопроса
test maketest(question questions[], discipline* disc, int n);//создание теста
int adddisc(group* group,discipline* disc);//добавление дисциплины в группу
int addgroup(discipline* disc, group* gr);//добавление группы в дисциплину
int adduser(group* group, user* student);//добавление пользователя в группу
int addtest(discipline* disc, test* test,int multiplier);//добавление теста в дисциплину
int addresult(test* test, int login, int result);//запись результата пользователя
void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);