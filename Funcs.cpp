#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"
#include <iostream>

group makegroup(const char* name) {
	group gr;
	gr.students = (user**)malloc(sizeof(user*));
	gr.nstudents = 0;
	gr.ndiscips = 0;
	gr.name = (char*)malloc(sizeof(name));
	gr.disciplines = (discipline**)malloc(sizeof(discipline*));
	strcpy(gr.name, name);
	return gr;
}
user makeuser(int login, int password, const char* name) {
	user us;
	us.login = login;
	us.password = password;
	us.group = NULL;
	us.name = name;
	return us;
}
discipline makediscip(const char* name) {
	discipline disc;
	disc.test = (test**)malloc(sizeof(test*));
	disc.ntests = 0;
	disc.ngroups = 0;
	disc.groups = (group**)malloc(sizeof(group*));
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
	(*disc).test = (test**)realloc((*disc).test, sizeof(test*) * (*disc).ntests);
	disc->test[(*disc).ntests - 1] = &t;
	return t;
}
int adddisc(group* gr, discipline* disc) {
	(*gr).ndiscips++;
	(*gr).disciplines = (discipline**)realloc((*gr).disciplines, sizeof(discipline*)*(gr->ndiscips));
	(*gr).disciplines[(*gr).ndiscips - 1] = disc;
	addgroup(disc, gr);
	return (*gr).ndiscips;
}
int addgroup(discipline* disc, group* gr) {
	(*disc).ngroups++;
	(*disc).groups = (group**)realloc((*disc).groups, sizeof(group*) * (*disc).ngroups);
	(*disc).groups[(*disc).ngroups - 1] = gr;
	return (*disc).ngroups;
}
int adduser(group* gr, user* student) {
	(*gr).nstudents++;
	(*gr).students = (user**)realloc((*gr).students, sizeof(user*) * (*gr).nstudents);
	(*gr).students[(*gr).nstudents - 1] = student;
	return (*gr).nstudents;
}
int addresult(test* tst, int login, int result) {
	(*tst).result[(*tst).nres * 2] = login;
	(*tst).result[(*tst).nres * 2 + 1] = result;
	(*tst).nres++;
	(*tst).result = (int*)realloc((*tst).result,sizeof(int) * (((*tst).nres * 2)+2));
	return (*tst).nres;
}
void showgroup(group group) {
	printf_s("Group: %s\n", group.name);
	if (group.nstudents > 0) {
		printf_s("Students:\n");
		for (int i = 0; i < group.nstudents; i++) {
			printf_s(" %d) Name: %s Login: %d\n", i, group.students[i]->name, group.students[i]->login);
		}
	}
	if (group.ndiscips > 0) {
		printf_s("Disciplines:\n");
		for (int i = 0; i < group.ndiscips; i++) {
			printf_s(" %d) Discipline: %s Tests: %d\n", i,group.disciplines[i]->name,group.disciplines[i]->ntests);
		}
	}
}
void showdiscip(discipline disc) {

}
void showtest(test test);
void showuser(user student);