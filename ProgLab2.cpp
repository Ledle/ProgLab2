#include "Header.h"
#define CRT_SECURE_NO_WARNINGS
#define mq makequestion
#define mu makeuser

int main(){
	discipline disc = makediscip("hello");
	question one = mq("opa", "epa", 2);
	question two = mq("three?", "no", 2);
	group PI =  makegroup("PI");
	user on = mu(1, 1, "Ledle");
	user to = mu(2, 2, "Fedle");
	adduser(&PI, &on);
	adduser(&PI, &to);
	maketest(qsts(2, mq("for", "while", 5), mq("what", "the", 5)), &disc, 2);
	addresult(disc.test[0], on.login, 50);
	adddisc(&PI, &disc);
	showgroup(PI);
}
