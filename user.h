#pragma once
struct group;
typedef struct user {
	int login, password;
	char* name;
	struct group* group;
};

user makeuser(int login, int password, const char* name);//создание пользователя

void rnuser(user* student, const char* name);//переименовать пользователя
void changepass(user* student, int password);//сменить пароль пользователя
void movuser(user* student, group* gr);//сменить группу пользователя

user* inpuser(group* gr);//ввод студента в консоль
void showuser(user student);//вывод пользователя в консоль
