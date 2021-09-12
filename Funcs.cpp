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
question makequestion(const char* text, const char* answer, int value);//создание вопроса
test maketest(question questions[]);//создание теста
bool addgroup(discipline* disc, group* group);//добавление группы в дисциплину
bool adduser(group* group, user students[], int n = 1);//добавление пользователя в группу
int addtest(discipline* disc, test* test, int multiplier);//добавление теста в дисциплину
int addresult(test* test, int login, int result);//запись результата пользователя
void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);