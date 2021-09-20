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
discipline makediscip(const char* name) {
	discipline disc;
	disc.test = (test**)malloc(sizeof(test*));
	disc.ntests = 0;
	disc.name = (char*)malloc(sizeof(name));
	strcpy(disc.name, name);
	return disc;
}
question makequestion(const char* text, const char* answer, int value) {
	question quest;
	int a = strlen(text) + 1;
	quest.text = (char*)malloc(a);
	memcpy(quest.text, text, strlen(text) + 1);
	quest.answer = (char*)malloc(strlen(answer) + 1);
	memcpy(quest.answer, answer, strlen(answer) + 1);
	quest.value = value;
	return quest;
}
question* qsts(int n, question a, ...) {
	question* q = (question*)malloc(sizeof(question) * n);
	question* src = &a;
	memcpy(q, src, sizeof(question) * n);
	return q;
}
test maketest(question questions[],discipline* disc,int n) {
	test t;
	question check = questions[n - 1];//проверка правильности n
	t.discipline = disc;
	t.question = (question*)malloc(sizeof(question) * n);
	memcpy(t.question, questions, sizeof(question) * n);
	t.result = (int*)(malloc(sizeof(int)*2));
	t.nres = 0;
	t.nquests = n;
	(*disc).ntests++;
	test** buf = (test**)malloc(sizeof(test*) * (*disc).ntests);
	memcpy(buf, (*disc).test, sizeof(test*) * ((*disc).ntests - 1));
	buf[(*disc).ntests - 1] = &t;
	free((*disc).test);
	(*disc).test = buf;
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
int addresult(test* tst, int login, int result) {
	int a = (*tst).nres * 2;
	(*tst).result[a] = login;
	(*tst).result[a + 1] = result;
	(*tst).nres++;
	int* buf = (int*)malloc(sizeof(int) * (((*tst).nres * 2)+2));
	memcpy(buf, (*tst).result, sizeof(int) * (((*tst).nres - 1) + 2));
	free((*tst).result);
	(*tst).result = buf;
	return (*tst).nres;
}
void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);