#pragma once
struct discipline;
struct user;
typedef struct group {
	struct user** students;
	struct discipline** disciplines;
	int nstudents, ndiscips;
	char* name;
};


group makegroup(const char* name); //создание группы



int adduser(group* group, user* student);//добавление пользователя в группу

void deldisc(group* gr, int numberdiscip);//удалить дисциплину из группы
void delstudent(group* gr, int numberuser);//удалить студента из группы

void showgroup(group group);//вывод группы в консоль


group inpgroup(group* thisgroup);//ввод группы в консоль
int adddisc(group* group, discipline* disc);//добавление дисциплины в группу

void rngroup(group* gr, const char* name);//переименовать группу