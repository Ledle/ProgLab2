#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "question.h"

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
question inpquestion() {
	char text[128], answer[128];
	int pts;
	printf_s("Enter question: ");
	gets_s(text, 128);
	printf_s("Enter answer: ");
	gets_s(answer, 128);
	printf_s("Enter number of points: ");
	scanf_s("%d", &pts);
	while (getchar() != '\n');
	return makequestion(text, answer, pts);
}
void showquestion(question quest) {
	printf_s("Text: %s\n", quest.text);
	printf_s("Answer: %s(%d pts)\n", quest.answer, quest.value);
}
void changequestion(question* qs, const char* text, const char* answer, int value) {
	qs->text = (char*)realloc(qs->text, strlen(text));
	strcpy(qs->text, text);
	qs->answer = (char*)realloc(qs->answer, strlen(answer));
	strcpy(qs->answer, answer);
	qs->value = value;
}