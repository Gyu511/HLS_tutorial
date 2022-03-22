/*
 * Empty C++ Application
 */

#include <stdio.h>
#include <math.h>
#include <xparameters.h>
#include <xgravity.h>
#include "platform.h"

//reference code
double goldRef[] = {2000000000.00000, 2000, 500, 222.22222222222, 125, 80,55.555555555556, 40.8163265306122, 31.250000000000, 24.6913580246914};

float gravity(float m1, float m2, float distance){

	float force = 0;
	float distsquare = 0;

	if(distance==0){
		distsquare = 0.000001f;
	}
	else distsquare = distance*distance;

	force = 10.f * (m1*m2) / distsquare;

	return force;
}

int main()
{
	init_platform();

	//initialize our core (gravity)
	int status;
	XGravity doGravity;
	XGravity_Config *doGravity_cfg;

	doGravity_cfg = XGravity_LookupConfig(XPAR_GRAVITY_0_DEVICE_ID);
	if(!doGravity_cfg){
		printf("Error loading config for doGravity_cfg\n");
	}
	status = XGravity_CfgInitialize(&doGravity,doGravity_cfg);
	if(status != XST_SUCCESS){
		printf("Error initializing for doGravity\n");
	}
	//XGravity_Initilaize(&doGravity,XPAR_GRAVITY_0_DEVICE_ID);

	printf("Running algorithm (SW) mode\n"); //SW 코드와 비교해보면 좋음
	float errorAcc = 0;
	for(int idx=0; idx<10; idx++){
		float force = gravity(10,20,idx);

		//calculate difference
		float errorCalc = fabsf(force - goldRef[idx]);
		errorAcc += errorCalc;

		printf("%d) Force : %f, Ref : %f, Diff : %f\n",(idx+1),force,goldRef[idx],errorCalc);
	}
	printf("No errors occurred average error: %f (SW)\n",errorAcc/10.0f);

	printf("Running algorithm (HW) mode\n");
	errorAcc = 0;
	//Now let's do it on the Hardware way (Call the vivado hls IP core generated)
	for(int idx=0; idx<10; idx++){ //parameter set
		XGravity_Set_m1(&doGravity,10);
		XGravity_Set_m2(&doGravity,20);
		XGravity_Set_distance(&doGravity,idx);
		//Start
		XGravity_Start(&doGravity);
		//Wait until done
		while(!XGravity_IsDone(&doGravity));

		float force_hw = (float)XGravity_Get_return(&doGravity);

		float errorCalc = fabsf(force_hw - goldRef[idx]);
		errorAcc += errorCalc;
	}

	printf("No errors occurred average error: %f (HW)\n",errorAcc/10.0f);

	return 0;
}
