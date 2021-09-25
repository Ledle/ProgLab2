#include "Header.h"
#define CRT_SECURE_NO_WARNINGS
#define mq makequestion
#define mu makeuser

int main(){
	discipline disc = makediscip("Math");
	test t = maketest(qsts(4, mq("2+2", "4", 2), mq("9+7", "16", 3), mq("5*3", "15", 4), mq("18/3", "6", 5)), &disc, 4, "Test 1");
	group PI = makegroup("PI");
	user sergey = mu(5613, 112233, "Sergey");
	user john = mu(9852, 541234, "John");
	adduser(&PI, &sergey);
	adduser(&PI, &john);
	adddisc(&PI, &disc);
	addresult(disc.test[0], sergey.login, 50);
	showgroup(PI);
	putchar('\n');
	showdiscip(disc);
	putchar('\n');
	showtest(*(disc.test[0]));
	putchar('\n');
	showuser(*(PI.students[0]));
	putchar('\n');
	addresult(disc.test[0], john.login, 80);
	printf_s("Add result in \"Test 1\"\n");
	showtest(*(disc.test[0]));
	printf_s("Rename Sergey to Dima, John to Dave,PI to IB, Test 1 to Old Test 1,Math to Algebra:\n");
	rnuser(&sergey, "Dima");
	rnuser(&john, "Dave");
	rndisc(&disc, "Algebra");
	rngroup(&PI, "IB");
	rntest(disc.test[0], "Old Test 1");
	showgroup(PI);
	putchar('\n');
	showdiscip(disc);
	putchar('\n');
	showtest(*(disc.test[0]));
	putchar('\n');
	showuser(*(PI.students[0]));
	putchar('\n');
	discipline kidmath = makediscip("KidMath");
	printf_s("Delete Dave:\n");
	delstudent(&PI, 1);
	showdiscip(disc);
	printf_s("Delete \"Algebra\" from \"IB\" and add \"KidMath\":\n");
	deldisc(&PI, 0);
	adddisc(&PI, &kidmath);
	showgroup(PI);
	printf_s("Move Dima to new group \"IBK\"\n");
	group ibk = makegroup("IBK");
	movuser(&sergey, &ibk);
	showgroup(ibk);
	printf_s("Delete \"PI\" from \"Algebra\"\n");
	delgroup(&disc, 0);
	showdiscip(disc);
	printf_s("Change question 1 in \"Old Test 1\"\n");
	changequestion(&(disc.test[0]->question[0]), "This question", "is changed", 99);
	showtest(*(disc.test[0]));
	printf_s("Delete \"Old Test 1\" from \"Algebra\"\nBefore:\n");
	showdiscip(disc);
	deltest(&disc, 0);
	printf_s("After:\n");
	showdiscip(disc);
	discipline discip = inpdiscip();
	inptest(&discip);
	showtest(*discip.test[0]);
	question newquest = inpquestion();
	changequestion(&(discip.test[0]->question[0]), newquest.text, newquest.answer, newquest.value);
	showtest(*discip.test[0]);
	group pi03 = inpgroup(&pi03);
	showgroup(pi03);
	user* student = inpuser(&pi03);
	showgroup(pi03);
}
