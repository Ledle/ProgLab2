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
discipline makediscip(test** tests, double* multiplier, int numbertests,const char* name) {
	discipline disc;
	disc.test = (test**)malloc(sizeof(test*)*numbertests);
	memcpy(disc.test, tests, sizeof(test*) * numbertests);
	disc.multiplier = (double*)malloc(sizeof(double*) * numbertests);
	memcpy(disc.multiplier, multiplier, sizeof(double*) * numbertests);
	disc.n = numbertests;
	disc.name = (char*)malloc(sizeof(name));
	strcpy(disc.name, name);
	return disc;
}
question makequestion(char* text, char* answer, int value) {
	question quest;
	quest.text = (char*)malloc(strlen(text)+1);
	memcpy(quest.text, text, strlen(text) + 1);
	quest.answer = (char*)malloc(strlen(answer) + 1);
	memcpy(quest.answer, answer, strlen(answer) + 1);
	quest.value = value;
	return quest;
}
test maketest(question questions[],discipline* disc,int n) {
	test t;
	question check = questions[n - 1];//проверка правильности n
	t.discipline = disc;
	t.question = (question*)malloc(sizeof(question) * n);
	memcpy(t.question, questions, sizeof(question) * n);
	t.result = (int*)(malloc(sizeof(int)*2));
	t.n = n;
	return t;
}
int adddisc(group* group, discipline* disc) {
	(*group).n++;
	discipline **buf = (discipline**)malloc(sizeof(discipline*)*(*group).n);
	memcpy(buf,(*group).disciplines, sizeof(discipline*) * ((*group).n-1));
	buf[(*group).n - 1] = disc;
	memcpy((*group).disciplines, buf, (*group).n);
	free(buf);
	return (*group).n;
}
bool addgroup(discipline* disc, group* group);
int adduser(group* group, user students[]);//добавление пользователя в группу
int addtest(discipline* disc, test* test, int multiplier);//добавление теста в дисциплину
int addresult(test* test, int login, int result);//запись результата пользователя
void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);