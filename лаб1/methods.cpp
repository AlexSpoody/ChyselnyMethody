#include "methods.h"
#include <stdio.h>
#include <math.h>
// Варік 20
static double function(double x) {
	return x * x * x - 3*x*x + 6*x - 4;
}
static void printValues(double a, double b, double x, int eps) {
	printf("a = %.*lf	b = %.*lf	x = %.*lf\n", eps, a, eps, b, eps, x);
}
int checkBorders(double a, double b) {
	if (function(a) * function(b) >= 0) {
		puts("Sorry, you entered wrong borders"); return 0;
	}
	return 1;
}
static int sign(double param) {
	if (param > 0) return 1;
	else return 0;
}

// Метод дихотомії
double dychotomyMethod(double a, double b, int eps) {
	double newA = a, newB = b;
	double newX = (newA + newB) / 2.0;
	printValues(newA, newB, newX, eps);
	if (fabs(newA - newB) <= 1.0 / pow(10, eps)) return newX;
	else {
		if (sign(function(newA)) == sign(function(newX))) newA = newX;
		if (sign(function(newB)) == sign(function(newX))) newB = newX;
	}
	dychotomyMethod(newA, newB, eps);
}

// Метод хорд (не зовсім точний)
static double secondPohidna(double x) {
	return 6.0 * x - 6.0;
}
double hordsMethod(double a, double b, int eps) {
	double oldX, newX;
	if (sign(function(a)) == sign(secondPohidna(a))) {
		oldX = b;
		newX = b - ((function(b) * (b - a)) / (function(b) - function(a)));
		printValues(a, b, newX, eps);
		if (fabs(newX - oldX) < 1.0 / pow(10, eps)) return newX; // якщо хочете точне відображення, то пишіть eps+2, а не eps
		hordsMethod(a, newX, eps);
	}
	else if(sign(function(b)) == sign(secondPohidna(b))) {
		oldX = a;
		newX = a - ((function(a) * (b - a)) / (function(b) - function(a)));
		printValues(a, b, newX, eps);
		if (fabs(newX - oldX) < 1.0 / pow(10, eps)) return newX; // аналогічно
		hordsMethod(newX, b, eps);
	}
}