#include "methods.h"
#include <stdio.h>
double det;
int getDet(double m_col1[3], double m_col2[3], double m_col3[3], double* result) {
	double determinant = 0.0;
	determinant += m_col1[2] * m_col2[0] * m_col3[1];
	determinant += m_col1[0] * m_col2[1] * m_col3[2];
	determinant += m_col1[1] * m_col2[2] * m_col3[0];

	determinant -= m_col1[2] * m_col2[1] * m_col3[0];
	determinant -= m_col1[1] * m_col2[0] * m_col3[2];
	determinant -= m_col1[0] * m_col2[2] * m_col3[1];
	if (determinant < 0.00000001) return 0;
	else *result = determinant;
	return 1;
}

inline double det2(double elem11, double elem12, double elem21, double elem22) {
	return elem11 * elem22 - elem12 * elem21;
}

void CramersMethod(EquationsSystem_x3 system) {
	
	printf("System determinant: %lf\n", det);
	double det1, det2, det3;
	getDet(system.m_colB, system.m_col2, system.m_col3, &det1);
	printf("First determinant: %lf\n", det1);
	getDet(system.m_col1, system.m_colB, system.m_col3, &det2);
	printf("Second determinant: %lf\n", det2);
	getDet(system.m_col1, system.m_col2, system.m_colB, &det3);
	printf("Third determinant: %lf\n", det3);
	double x1 = double(det1 / det);
	printf("First root: %lf\n", x1);
	double x2 = double(det2 / det);
	printf("Second root: %lf\n", x2);
	double x3 = double(det3 / det);
	printf("Third root: %lf\n", x3);
} 

void ReversedMatrixMethod(EquationsSystem_x3 system) {
	if (!getDet(system.m_col1, system.m_col2, system.m_col3, &det)) {
		puts("Sorry, determinant equals zero!");
		return;
	}
	printf("System determinant: %lf\n", det);
	double systemMatrix[3][3];
	for (int i = 0; i < 3; i++) {
		systemMatrix[0][i] = system.m_col1[i];
		systemMatrix[1][i] = system.m_col2[i];
		systemMatrix[2][i] = system.m_col3[i];
	}
	double reversedMatrix[3][3];
	reversedMatrix[0][0] = det2(systemMatrix[1][1], systemMatrix[1][2], systemMatrix[2][1], systemMatrix[2][2]);
	reversedMatrix[1][0] = -det2(systemMatrix[1][0], systemMatrix[1][2], systemMatrix[2][0], systemMatrix[2][2]);
	reversedMatrix[2][0] = det2(systemMatrix[1][0], systemMatrix[1][1], systemMatrix[2][0], systemMatrix[2][1]);
	reversedMatrix[0][1] = -det2(systemMatrix[0][1], systemMatrix[0][2], systemMatrix[2][1], systemMatrix[2][2]);
	reversedMatrix[1][1] = det2(systemMatrix[0][0], systemMatrix[0][2], systemMatrix[2][0], systemMatrix[2][2]);
	reversedMatrix[2][1] = -det2(systemMatrix[0][0], systemMatrix[0][1], systemMatrix[2][0], systemMatrix[2][1]);
	reversedMatrix[0][2] = det2(systemMatrix[0][1], systemMatrix[0][2], systemMatrix[1][1], systemMatrix[1][2]);
	reversedMatrix[1][2] = -det2(systemMatrix[0][0], systemMatrix[0][2], systemMatrix[1][0], systemMatrix[1][2]);
	reversedMatrix[2][2] = det2(systemMatrix[0][0], systemMatrix[0][1], systemMatrix[1][0], systemMatrix[1][1]);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			reversedMatrix[i][j] /= det;
		}
	}

	puts("Reversed matrix:");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%lf\t", reversedMatrix[i][j]);
		}
		puts("");
	}

	for (int i = 0; i < 3; i++) system.m_colX[i] = 0.0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			system.m_colX[i] += reversedMatrix[i][j] * system.m_colB[i];
		}
	}

	for (int i = 0; i < 3; i++) printf("Solution number %d: %lf\n",i,system.m_colX[i]);
}