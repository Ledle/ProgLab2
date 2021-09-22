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
	us.name = (char*)malloc(sizeof(name));
	strcpy(us.name, name);
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
test maketest(question questions[],discipline* disc,int n, const char* name) {
	test t;
	question check = questions[n - 1];//проверка правильности n
	t.discipline = disc;
	t.question = (question*)malloc(sizeof(question) * n);
	memcpy(t.question, questions, sizeof(question) * n);
	t.result = (int*)(malloc(sizeof(int) * 2));
	t.nres = 0;
	t.nquests = n;
	(*disc).ntests++;
	(*disc).test = (test**)realloc((*disc).test, sizeof(test*) * (*disc).ntests);
	disc->test[(*disc).ntests - 1] = &t;
	t.name = (char*)malloc(sizeof(name));
	strcpy(t.name, name);
	return t;
}
int adddisc(group* gr, discipline* disc) {
	(*gr).ndiscips++;
	(*gr).disciplines = (discipline**)realloc((*gr).disciplines, sizeof(discipline*) * (gr->ndiscips));
	(*gr).disciplines[(*gr).ndiscips - 1] = disc;
	(*disc).ngroups++;
	(*disc).groups = (group**)realloc((*disc).groups, sizeof(group*) * (*disc).ngroups);
	(*disc).groups[(*disc).ngroups - 1] = gr;
	return (*gr).ndiscips;
}
int adduser(group* gr, user* student) {
	(*gr).nstudents++;
	(*gr).students = (user**)realloc((*gr).students, sizeof(user*) * (*gr).nstudents);
	(*gr).students[(*gr).nstudents - 1] = student;
	student->group = gr;
	return (*gr).nstudents;
}
int addresult(test* tst, int login, int result) {
	(*tst).result = (int*)realloc((*tst).result, sizeof(int) * (((*tst).nres * 2) + 2));
	(*tst).result[(*tst).nres * 2] = login;
	(*tst).result[(*tst).nres * 2 + 1] = result;
	(*tst).nres++;
	return (*tst).nres;
}
void rnuser(user* student, const char* name) {
	student->name = (char*)realloc(student->name, strlen(name));
	strcpy(student->name, name);
}
void rndisc(discipline* disc, const char* name) {
	disc->name = (char*)realloc(disc->name, strlen(name));
	strcpy(disc->name, name);
}
void rntest(test* test, const char* name) {
	test->name = (char*)realloc(test->name, strlen(name));
	strcpy(test->name, name);
}
void rngroup(group* gr, const char* name) {
	gr->name = (char*)realloc(gr->name, strlen(name));
	strcpy(gr->name, name);
}
void changepass(user* student, int password) {
	student->password = password;
}
void movuser(user* student, group* ngr) {
	int id = -1;
	group* gr = student->group;
	for (int i = 0; i < gr->nstudents; i++) {
		if (student->login == gr->students[i]->login) {
			id = i;
			break;
		}
	}
	if (id > 0) {
		gr->nstudents--;
		for (int i = id; i < gr->nstudents; i++) {
			gr->students[i] = gr->students[i + 1];
		}
	}
	gr->students = (user**)realloc(gr->students, sizeof(user*) * (gr->nstudents));
	adduser(ngr, student);
}
void changequestion(question* qs, const char* text, const char* answer, int value) {
	qs->text = (char*)realloc(qs->text, strlen(text));
	strcpy(qs->text, text);
	qs->answer = (char*)realloc(qs->answer, strlen(answer));
	strcpy(qs->answer, answer);
	qs->value = value;
}
void deldisc(group* gr, int numberdiscip) {
	if (numberdiscip < gr->ndiscips && gr->ndiscips>0) {
		gr->ndiscips--;
		for (int i = numberdiscip; i < gr->ndiscips; i++) {
			gr->disciplines[i] = gr->disciplines[i + 1];
		}
		gr->disciplines = (discipline**)realloc(gr->disciplines, sizeof(discipline*) * gr->ndiscips);
	}
}
void delstudent(group* gr, int numberuser) {
	if (numberuser < gr->nstudents && gr->nstudents>0) {
		gr->nstudents--;
		for (int i = numberuser; i < gr->nstudents; i++) {
			gr->students[i] = gr->students[i + 1];
		}
		gr->students = (user**)realloc(gr->students, sizeof(user*) * gr->nstudents);
	}
}
void deltest(discipline* disc, int numbertest) {
	if (numbertest < disc->ntests && disc->ntests>0) {
		disc->ntests--;
		for (int i = numbertest; i < disc->ntests; i++) {
			disc->test[i] = disc->test[i + 1];
		}
		disc->test = (test**)realloc(disc->test, sizeof(test*) * disc->ntests);
	}
}
void delgroup(discipline* disc, int numbergroup) {
	if (numbergroup < disc->ngroups && disc->ngroups>0) {
		disc->ngroups--;
		for (int i = numbergroup; i < disc->ngroups; i++) {
			disc->groups[i] = disc->groups[i + 1];
		}
		disc->groups = (group**)realloc(disc->groups, sizeof(group*) * disc->ngroups);
	}
}
void showgroup(group group) {
	printf_s("Group %s:\n", group.name);
	if (group.nstudents > 0) {
		for (int i = 0; i < group.nstudents; i++) {
			printf_s(" %d) Name: %s Login: %d\n", i, group.students[i]->name, group.students[i]->login);
		}
	}
	if (group.ndiscips > 0) {
		printf_s(" Disciplines:\n");
		for (int i = 0; i < group.ndiscips; i++) {
			printf_s("  %d) Discipline: %s Tests: %d\n", i, group.disciplines[i]->name, group.disciplines[i]->ntests);
		}
	}
}
void showdiscip(discipline disc) {
	printf_s("Discipline %s:\n", disc.name);
	if (disc.ngroups > 0) {
		printf_s(" Groups:\n");
		for (int i = 0; i < disc.ngroups; i++) {
			printf_s("  %d) Name: %s Students: %d\n", i, disc.groups[i]->name, disc.groups[i]->nstudents);
		}
	}
	if (disc.ntests >= 0) {
		printf_s(" Tests: %d\n", disc.ntests);
	}
}
void showtest(test test) {
	printf_s("Test %s in %s\n", test.name, test.discipline->name);
	if (test.nquests > 0) {
		printf_s(" Questions:\n");
		for (int i = 0; i < test.nquests; i++) {
			printf_s("  %d)Question: %s\n   Answer: %s(%d balls)\n", i, test.question[i].text, test.question[i].answer, test.question[i].value);
		}
	}
	if (test.nres > 0) {
		printf_s(" Results:\n");
		for (int i = 0; i < test.nres; i++) {
			printf_s("  %d) Login: %d Result: %d\n", i, test.result[i * 2], test.result[i * 2 + 1]);
		}
	}
}
void showuser(user student) {
	printf_s("User %s:\n", student.name);
	printf_s(" Group: %s\n Login: %d Password: %d\n", student.group->name, student.login, student.password);
}