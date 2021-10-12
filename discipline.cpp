#define _CRT_SECURE_NO_WARNINGS
#include "discipline.h"
#include "group.h"
#include "test.h"
#include <stdio.h>
#include <cstdlib>
#include <cstring>

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

int addtest(discipline* disc, test* tst) {
	tst->discipline = disc;
	(*disc).ntests++;
	(*disc).test = (test**)realloc((*disc).test, sizeof(test*) * (*disc).ntests);
	disc->test[(*disc).ntests - 1] = tst;
	return disc->ntests;
}

void rndisc(discipline* disc, const char* name) {
	disc->name = (char*)realloc(disc->name, strlen(name));
	strcpy(disc->name, name);
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

discipline inpdiscip() {
	char name[128];
	printf_s("Enter name of discipline: ");
	gets_s(name, 128);
	return makediscip(name);
}