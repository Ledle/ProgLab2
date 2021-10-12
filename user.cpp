#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "group.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
user makeuser(int login, int password, const char* name) {
	user us;
	us.login = login;
	us.password = password;
	us.group = NULL;
	us.name = (char*)malloc(sizeof(name));
	strcpy(us.name, name);
	return us;
}

void rnuser(user* student, const char* name) {
	student->name = (char*)realloc(student->name, strlen(name));
	strcpy(student->name, name);
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

void showuser(user student) {
	printf_s("User %s:\n", student.name);
	printf_s(" Group: %s\n Login: %d Password: %d\n", student.group->name, student.login, student.password);
}
user* inpuser(group* gr) {
	char name[128];
	int login, password;
	user* student = (user*)malloc(sizeof(user));
	printf_s("Enter name of student: ");
	gets_s(name, 128);
	printf_s("Enter login: ");
	scanf_s("%d", &login);
	while (getchar() != '\n');
	printf_s("Enter password: ");
	scanf_s("%d", &password);
	while (getchar() != '\n');
	*student = makeuser(login, password, name);
	adduser(gr, student);
	return student;
}