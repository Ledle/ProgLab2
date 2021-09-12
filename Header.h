#pragma once
typedef struct user {
	int login,password;
	const char* name;
	group* group;
};
typedef struct discipline {
	test** test;
	double* multiplier; //коэффициенты тестов для подсчёта рейтинга
	group** groups;
};
typedef struct group {
	user** students;
	discipline** disciplines;
};
typedef struct question {
	const char* text,answer;
	int value;//количество баллов за вопрос
};
typedef struct test {
	question* question;
	int* result;//результаты пользователей
	discipline** discipline;
};

int starttest(test test, user student);//maybe
user makeuser(int login, int password, group* group, const char* name);//создание пользователя
discipline makediscip(test* tests, double* multiplier);//создание дисциплины
question makequestion(const char* text, const char* answer, int value);//создание вопроса
test maketest(question questions[]);//создание теста
bool addgroup(discipline* disc, group* group);//добавление группы в дисциплину
bool adduser(group* group, user students[], int n = 1);//добавление пользователя в группу
int addtest(discipline* disc, test* test,int multiplier);//добавление теста в дисциплину
int addresult(test* test, int login, int result);//запись результата пользователя
void showgroup(group group);
void showdiscip(discipline disc);
void showtest(test test);
void showuser(user student);