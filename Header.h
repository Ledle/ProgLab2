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

void rnuser(user* student, const char* name);//переименовать пользователя
void rndisc(discipline* disc, const char* name);//переименовать дисциплину
void rntest(test* test, const char* name);//переименовать тест
void rngroup(group* gr, const char* name);//переименовать группу
void changepass(user* student, int password);//сменить пароль пользователя
void movuser(user* student, group* gr);//сменить группу пользователя
void changequestion(question* qs, const char* text, const char* answer, int value);//изменить вопрос в тесте
void deldisc(group* gr, int numberdiscip);//удалить дисциплину из группы
void delstudent(group* gr, int numberuser);//удалить студента из группы
void deltest(discipline* disc, int numbertest);//удалить тест из дисциплины
void delgroup(discipline* disc, int numbergroup);//удалить группу из дисциплины

void showgroup(group group);//вывод группы в консоль
void showdiscip(discipline disc);//вывод дисциплины в консоль
void showtest(test test);//вывод теста в консоль
void showuser(user student);//вывод пользователя в консоль
void showquestion(question quest);//вывод вопроса в консоль

group inpgroup(group* thisgroup);
user* inpuser(group* gr);
discipline inpdiscip();
question inpquestion();
test inptest(discipline* disc);