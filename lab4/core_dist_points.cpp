#include "hls_math.h"
#include <math.h>//pow is not part of hls_math
#include <ap_fixed.h>

typedef ap_fixed<16,5> fix_t; // <,>에서 앞부분이 전체 사이즈 뒷 부분이 정수 사이즈

double distPoints_double(double Ax, double Ay, double Bx, double By){
	return hls::sqrt(pow(Ax-Bx,2.0) + pow(Ay-By,2.0)); //hls::로 hls_math funt사용
}

float distPoints_float(float Ax, float Ay, float Bx, float By){
	return hls::sqrtf(pow(Ax-Bx,2.0) + pow(Ay-By,2.0));//sqrt에 f를 안붙이면 double형으로 됨
}

fix_t distPoints_fixed(fix_t Ax, fix_t Ay, fix_t Bx, fix_t By){
	return hls::sqrt(pow(Ax-Bx,2.0) + pow(Ay-By,2.0));
}
