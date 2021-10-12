#define _CRT_SECURE_NO_WARNINGS
#include "group.h"
#include "user.h"
#include "discipline.h"
#include <stdio.h>
#include <cstdlib>
#include <cstring>


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

void rngroup(group* gr, const char* name) {
	gr->name = (char*)realloc(gr->name, strlen(name));
	strcpy(gr->name, name);
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
		gr->students[numberuser]->group = NULL;
		for (int i = numberuser; i < gr->nstudents; i++) {
			gr->students[i] = gr->students[i + 1];
		}
		gr->students = (user**)realloc(gr->students, sizeof(user*) * gr->nstudents);
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


group inpgroup(group* thisgroup) {
	char name[128];
	int n;
	printf_s("Enter name of group: ");
	gets_s(name, 128);
	*thisgroup = makegroup(name);
	printf_s("Enter number of students: ");
	scanf_s("%d", &n);
	while (getchar() != '\n');
	user** students = (user**)malloc(sizeof(user*) * n);
	for (int i = 0; i < n; i++) {
		printf_s("%d)\n", i);
		students[i] = inpuser(thisgroup);
	}
	return *thisgroup;
}