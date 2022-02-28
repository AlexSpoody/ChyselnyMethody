#include <stdio.h>
#include "methods.h"
EquationsSystem_x3 System_1 = {
	{1.24, 2.11, 0.48},
	{-0.87, -0.45, 1.25},
	{-3.17, 1.44, -0.63},
	{0.46, 1.50, 0.35}
};
int main() {
	int choice;
	do {
		puts("Enter your choice.\n1 - Cramer's Method\n2 - Reversed Matrix Method");
		scanf_s("%i", &choice);
	} while (choice != 1 && choice != 2);
	
	if(1==choice) CramersMethod(System_1);
	else if (2 == choice) ReversedMatrixMethod(System_1);
	return 0;
}