#include "methods.h"
#include <stdio.h>
#include <math.h>
static double function(double x) {
	return x * x * x - 3 * x * x + 6 * x - 4;
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
double derivative(double (*pFunc)(double), double x0) {
	const double deltaX = 1e-6;
	double x1 = x0 - deltaX;
	double x2 = x0 + deltaX;
	double y1 = (*pFunc)(x1);
	double y2 = (*pFunc)(x2);
	return (y2 - y1) / (x2 - x1);
}
double n_der(double (*pFunc)(double), double x0, int n) {
	double der;
	for (int i = 0; i < n; i++) der = derivative(&function, x0);
	return der;
}
double NewthonMethod(double a, double b, int eps) {
	double newX, oldX;
	if (sign(function(a)) == sign(n_der(&function, a, 2))) {
		newX = a;
		oldX = newX;
		newX = oldX - function(oldX) / derivative(&function, oldX);
		printValues(a, b, newX, eps);
		if (fabs(newX - oldX) < 1.0 / pow(10, eps)) return newX;
		NewthonMethod(newX, b, eps);
	}
	else if (sign(function(b)) == sign(n_der(&function, b, 2))) {
		newX = b;
		oldX = newX;
		newX = oldX - function(oldX) / derivative(&function, oldX);
		printValues(a, b, newX, eps);
		if (fabs(newX - oldX) < 1.0 / pow(10, eps)) return newX;
		NewthonMethod(a, newX, eps);
	}
}
double max(double param1, double param2) {
	if (param1 > param2) return param1;
	else return param2;
}
double iterationMethod(double a, double b, int eps) {
	double newX = b, k, Q;
	Q = max(fabs(derivative(&function, a)), fabs(derivative(&function, b)));
	if (sign(max(derivative(&function, a), derivative(&function, b)))) k = Q / 2.0;
	else k = -(Q / 2.0);
	double oldX = newX;
	printValues(a, newX, newX, eps);
	newX = oldX - (function(oldX)) / k;
	if (fabs(newX - oldX) <= 1.0 / pow(10, eps)) return newX;
	iterationMethod(a, newX, eps);
}