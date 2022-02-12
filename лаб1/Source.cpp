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
	puts("Which method?\n1 - Dychotomy Method\n2 - Hords method");
	scanf_s("%i", &choice);
	puts("Working on it...");
	if (1 == choice) {
		puts("This is a demonstration of dychotomy method for x^3 - 3*x^2 + 6*x - 4 = 0");
		if (!checkBorders(borderA, borderB)) return -1;
		dychotomyMethod(borderA, borderB, epsilon);
	}
	else if (2 == choice) {
		puts("This is a demonstration of hords method for x^3 - 3*x^2 + 6*x - 4 = 0");
		if (!checkBorders(borderA, borderB)) return -1;
		hordsMethod(borderA, borderB, epsilon);
	}
}