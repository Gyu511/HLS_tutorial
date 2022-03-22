#include <stdio.h>
#include <math.h>
#include "test_core.h"

int main(){
	printf("Testing gravity for mass m1=10 m2=20\n");
	float errorAcc = 0;
	for(int idx=0; idx<10; idx++){
		float force = gravity(10,20,idx);

		float errorCalc = fabsf(force - goldRef[idx]);
		errorAcc += errorCalc;

		printf("%d) Force : %f, Ref : %f, Diff : %f\n",(idx+1),force,goldRef[idx],errorCalc);

		if(errorCalc > 1){
			printf("Error to big abort\n");

			return 1;
		}
	}
	printf("No errors occurred average error: %f\n",errorAcc/10.0f);
	return 0;
}
