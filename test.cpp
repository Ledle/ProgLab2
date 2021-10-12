#define _CRT_SECURE_NO_WARNINGS
#include "test.h"
#include "question.h"
#include "discipline.h"
#include <stdio.h>
#include <cstdlib>
#include <cstring>

test maketest(question questions[], int n, const char* name) {
	test* t = (test*)malloc(sizeof(test));
	questions[n - 1];//проверка правильности n
	t->question = (question*)malloc(sizeof(question) * n);
	memcpy(t->question, questions, sizeof(question) * n);
	t->result = (int*)(malloc(sizeof(int) * 2));
	t->nres = 0;
	t->nquests = n;
	t->name = (char*)malloc(sizeof(name));
	strcpy(t->name, name);
	return *t;
}
int addresult(test* tst, int login, int result) {
	(*tst).result = (int*)realloc((*tst).result, sizeof(int) * (((*tst).nres * 2) + 2));
	(*tst).result[(*tst).nres * 2] = login;
	(*tst).result[(*tst).nres * 2 + 1] = result;
	(*tst).nres++;
	return (*tst).nres;
}

void rntest(test* test, const char* name) {
	test->name = (char*)realloc(test->name, strlen(name));
	strcpy(test->name, name);
}

void showtest(test test) {
	printf_s("Test %s in %s\n", test.name, test.discipline->name);
	if (test.nquests > 0) {
		printf_s(" Questions:\n");
		for (int i = 0; i < test.nquests; i++) {
			printf_s("  %d)Question: %s\n   Answer: %s(%d points)\n", i, test.question[i].text, test.question[i].answer, test.question[i].value);
		}
	}
	if (test.nres > 0) {
		printf_s(" Results:\n");
		for (int i = 0; i < test.nres; i++) {
			printf_s("  %d) Login: %d Result: %d\n", i, test.result[i * 2], test.result[i * 2 + 1]);
		}
	}
}

test inptest(discipline* disc) {
	int n;
	char name[64];
	printf_s("Enter name of test: ");
	gets_s(name, 64);
	printf_s("Enter number of questions: ");
	scanf_s("%d", &n);
	while (getchar() != '\n');
	question* quests = (question*)malloc(sizeof(question) * n);
	for (int i = 0; i < n; i++) {
		quests[i] = inpquestion();
	}
	return maketest(quests, n, name);
}