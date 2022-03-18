#include "hls_math.h"
#include <math.h>//pow is not part of hls_math
#include <ap_fixed.h>

typedef ap_fixed<16,5> fix_t; // <,>���� �պκ��� ��ü ������ �� �κ��� ���� ������

double distPoints_double(double Ax, double Ay, double Bx, double By){
	return hls::sqrt(pow(Ax-Bx,2.0) + pow(Ay-By,2.0)); //hls::�� hls_math funt���
}

float distPoints_float(float Ax, float Ay, float Bx, float By){
	return hls::sqrtf(pow(Ax-Bx,2.0) + pow(Ay-By,2.0));//sqrt�� f�� �Ⱥ��̸� double������ ��
}

fix_t distPoints_fixed(fix_t Ax, fix_t Ay, fix_t Bx, fix_t By){
	return hls::sqrt(pow(Ax-Bx,2.0) + pow(Ay-By,2.0));
}
