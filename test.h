#pragma once
struct question;
struct discipline;
typedef struct test {
	struct question* question;
	int* result;//результаты пользователей
	struct discipline* discipline;
	int nres, nquests;
	char* name;
};
test maketest(question questions[], int n, const char* name);//создание теста
int addresult(test* test, int login, int result);//запись результата пользователя
void rntest(test* test, const char* name);//переименовать тест
test inptest(discipline* disc);//ввод теста в консоль
void showtest(test test);//вывод теста в консоль