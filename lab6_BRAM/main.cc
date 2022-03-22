#include <stdio.h>
#include <xcrazyfunction.h>
#include <xparameters.h>
#include <math.h>
#include "AxiTimerHelper.h"

float *XVecHW = (float *)0x4000_0000;
float *resHW = (float *)0x4200_0000;

XCrazyfunction doCrazyFunction;
XCrazyfunction_Config *doCrazyFunction_cfg;

void init_crazyCore(){
	int status = 0;
	doCrazyFunction_cfg = XCrazyfuntion_LookupConfig(XPAR_CRAZYFUNCTION_0_DEVICE_ID);
	if(doCrazyFunction_cfg){
		status = XCrazyfunction_CfgInitialize(&doCrazyFunction,doCrazyFunction_cfg);
		if(status != XST_SUCCESS){
			printf("Failed to initialize\n");
		}
	}
}

//SW version
void crazyFunction(float x[100], float y, float res[100]){
	for(int idx = 0; idx < 100; idx++){
		res[idx] = (hls::sin(x[idx]) + hls::sqrtf(hls::expf(y))) / 2;
	}
}

unsigned int float_to_u32(float val){
	unsigned int result;
	union float_bytes{
		float v;
		unsigned char bytes[4];
	} data;
	data.v = val;

	result = (data.bytes[3] << 24) + (data.bytes[2] << 16) + (data.bytes[1] << 8) + (data.bytes[0] << 0);
	return result;
}

int main()
{
	init_carzycore();
	AxitimerHelprt time;
	printf("Test BRAM\n");

	float XVecSW[100];
	float resSW[100];
	for(int idxX = 0;idxX<100; idxX++){
		XVecSW[idxX] = idxX;
		XVecHw[idxX] = idxX;
	}

	timer.startTimer();
	scatyFunction(XVecSW, 0.01f, resSW);
	timer.stopTimer();
	double timeSW = timer.getElapsedTimerInSeconds();
	printf("SW test finished in %f seconds\n",timeSW);

	//Use IP
	XCrazyfunction_Set_y(&doCrazyFunction,float_to_u32(0.01f));
	timer.startTimer();
	while (!SCrazyfunction_IsDone(&doCrazyFucntion));
	timer.stopTimer();
	double timeHW = timer.getElapsedTimerInSeconds();
	printf("HW test finished in %f seconds\n",timeHW);

	double error = 0;
	for(int idx = 0; idx < 100; idx++){
		error += fabsf(resHW[idx] - resSW[idx]);
	}
	error /= 100.0f;
	printf("Total average error %f\n",error);

	return 0;
}
