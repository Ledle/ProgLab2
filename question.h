#pragma once

typedef struct question {
	char* text, * answer;
	int value;//���������� ������ �� ������
};

question makequestion(const char* text, const char* answer, int value);//�������� �������
question* qsts(int n, question a, ...);
void changequestion(question* qs, const char* text, const char* answer, int value);//�������� ������ � �����

question inpquestion();//���� ������� � �������
void showquestion(question quest);//����� ������� � �������