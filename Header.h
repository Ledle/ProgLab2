#pragma once
typedef struct user {
	int login,password;
	char* name;

};
typedef struct group {
	user* member;
	discipline discipline;
};
typedef struct question {
	char* text,answer;
	int value;
};
typedef struct test {
	question* question;
	int* result;
	discipline* discipline;
};
typedef struct discipline {
	test* test;
	double* multiplier;
	group group;
};