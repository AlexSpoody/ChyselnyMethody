#pragma once
typedef struct EquationsSystem_x3 {
	double m_col1[3];
	double m_col2[3];
	double m_col3[3];
	double m_colB[3];
	double m_colX[3];
}EquationsSystem_x3;
void CramersMethod(EquationsSystem_x3 system);
void ReversedMatrixMethod(EquationsSystem_x3 system);