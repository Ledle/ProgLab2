#pragma once
struct group;
typedef struct user {
	int login, password;
	char* name;
	struct group* group;
};

user makeuser(int login, int password, const char* name);//�������� ������������

void rnuser(user* student, const char* name);//������������� ������������
void changepass(user* student, int password);//������� ������ ������������
void movuser(user* student, group* gr);//������� ������ ������������

user* inpuser(group* gr);//���� �������� � �������
void showuser(user student);//����� ������������ � �������
