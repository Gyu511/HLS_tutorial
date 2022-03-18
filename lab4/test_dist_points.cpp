#include <stdio.h>
#include <ap_fixed.h>

typedef ap_fixed<16,5> fix_t;

//function header
double distPoints_double(double Ax, double Ay, double Bx, double By);
float distPoints_float(float Ax, float Ay, float Bx, float By);
fix_t distPoints_fixed(fix_t Ax, fix_t Ay, fix_t Bx, fix_t By);

int main(){
	double Ax = 1.0;
	double Bx = 0.5f;
	double Ay = 2.5f;
	double By = 4.5f;

	double dist_double = distPoints_double(Ax,Ay,Bx,By);
	float dist_float = distPoints_float((float)Ax,(float)Ay,(float)Bx,(float)By);
	fix_t dist_fixed = distPoints_fixed((fix_t)Ax,(fix_t)Ay,(fix_t)Bx,(fix_t)By);

	printf("Dostance between A-B(double) : %f\n",(float)dist_double);
	printf("Dostance between A-B(float) : %f\n",(float)dist_float);
	printf("Dostance between A-B(fixed) : %f\n",(float)dist_fixed);

	return 0;
}
