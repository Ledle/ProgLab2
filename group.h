#pragma once
struct discipline;
struct user;
typedef struct group {
	struct user** students;
	struct discipline** disciplines;
	int nstudents, ndiscips;
	char* name;
};


group makegroup(const char* name); //�������� ������



int adduser(group* group, user* student);//���������� ������������ � ������

void deldisc(group* gr, int numberdiscip);//������� ���������� �� ������
void delstudent(group* gr, int numberuser);//������� �������� �� ������

void showgroup(group group);//����� ������ � �������


group inpgroup(group* thisgroup);//���� ������ � �������
int adddisc(group* group, discipline* disc);//���������� ���������� � ������

void rngroup(group* gr, const char* name);//������������� ������