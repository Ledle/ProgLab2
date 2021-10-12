#pragma once

typedef struct question {
	char* text, * answer;
	int value;//количество баллов за вопрос
};

question makequestion(const char* text, const char* answer, int value);//создание вопроса
question* qsts(int n, question a, ...);
void changequestion(question* qs, const char* text, const char* answer, int value);//изменить вопрос в тесте

question inpquestion();//ввод вопроса в консоль
void showquestion(question quest);//вывод вопроса в консоль