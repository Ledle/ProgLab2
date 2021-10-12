#pragma once
struct test;
typedef struct discipline {
	struct test** test;
	struct group** groups;
	int ntests, ngroups;
	char* name;
};

discipline makediscip(const char* name);//�������� ����������

void rndisc(discipline* disc, const char* name);//������������� ����������
void deltest(discipline* disc, int numbertest);//������� ���� �� ����������
void delgroup(discipline* disc, int numbergroup);//������� ������ �� ����������
int addtest(discipline* disc, test* tst);
discipline inpdiscip();//���� ���������� � �������

void showdiscip(discipline disc);//����� ���������� � �������