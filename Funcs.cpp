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
	disc.ntests = numbertests;
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
	(*group).nstudents++;
	discipline **buf = (discipline**)malloc(sizeof(discipline*)*(*group).nstudents);
	memcpy(buf,(*group).disciplines, sizeof(discipline*) * ((*group).nstudents -1));
	buf[(*group).nstudents - 1] = disc;
	free((*group).disciplines);
	(*group).disciplines = buf;
	return (*group).nstudents;
}
int addgroup(discipline* disc, group* gr) {
	(*disc).ngroups++;
	group** buf = (group**)malloc(sizeof(group*) * (*disc).ngroups);
	memcpy(buf, (*disc).groups, sizeof(group*) * ((*disc).ngroups - 1));
	buf[(*disc).ngroups - 1] = gr;
	free((*disc).groups);
	(*disc).groups = buf;
	return (*disc).ngroups;
}
int adduser(group* gr, user* student) {
	(*gr).nstudents++;
	user** buf = (user**)malloc(sizeof(user*) * (*gr).nstudents);
	memcpy(buf, (*gr).students, sizeof(user*) * ((*gr).nstudents - 1));
	buf[(*gr).nstudents - 1] = student;
	free((*gr).students);
	(*gr).students = buf;
	return (*gr).nstudents;
}
int addtest(discipline* disc, test* tst, double multiplier) {
	(*disc).ntests++;
	test** buf = (test**)malloc(sizeof(test*) * (*disc).ntests);
	double* bufm = (double*)malloc(sizeof(double) * (*disc).ntests);
	memcpy(buf, (*disc).test, sizeof(test*) * ((*disc).ntests - 1));
	memcpy(bufm, (*disc).multiplier, sizeof(double*) * ((*disc).ntests - 1));
	buf[(*disc).ntests - 1] = tst;
	bufm[(*disc).ntests - 1] = multiplier;
	free((*disc).multiplier);
	free((*disc).test);
	(*disc).multiplier = bufm;
	(*disc).test = buf;
	return (*disc).ntests;
}
int addresult(test* test, int login, int result);//запись результата пользователя
void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);