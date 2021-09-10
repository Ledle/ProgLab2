#pragma once
typedef struct user {
	int login,password;
	char* name;
};
typedef struct discipline {
	test* test;
	double* multiplier;
};
typedef struct group {
	user* member;
	discipline* disciplines;
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

