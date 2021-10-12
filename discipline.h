#pragma once
struct test;
typedef struct discipline {
	struct test** test;
	struct group** groups;
	int ntests, ngroups;
	char* name;
};

discipline makediscip(const char* name);//создание дисциплины

void rndisc(discipline* disc, const char* name);//переименовать дисциплину
void deltest(discipline* disc, int numbertest);//удалить тест из дисциплины
void delgroup(discipline* disc, int numbergroup);//удалить группу из дисциплины
int addtest(discipline* disc, test* tst);
discipline inpdiscip();//ввод дисциплины в консоль

void showdiscip(discipline disc);//вывод дисциплины в консоль