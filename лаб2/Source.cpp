#include "methods.h"
#include <stdio.h>
int main() {
	double borderA, borderB; int epsilon, choice;
	puts("Enter borders and epsilon");
	puts("Enter a:");
	scanf_s("%lf", &borderA);
	puts("Enter b:");
	scanf_s("%lf", &borderB);
	puts("Enter epsilon:");
	scanf_s("%i", &epsilon);
	puts("Which method?\n1 - Newthon Method\n2 - Iteration method");
	scanf_s("%i", &choice);
	puts("Working on it...");
	if (1 == choice) {
		puts("This is a demonstration of Newthon method for x^3 - 3*x^2 + 6*x - 4 = 0");
		if (!checkBorders(borderA, borderB)) return -1;
		NewthonMethod(borderA, borderB, epsilon);
	}
	else if (2 == choice) {
		puts("This is a demonstration of iteration method for x^3 - 3*x^2 + 6*x - 4 = 0");
		if (!checkBorders(borderA, borderB)) return -1;
		iterationMethod(borderA, borderB, epsilon);
	}
}
