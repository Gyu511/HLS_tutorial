#include <stdio.h>

void find(char val, char in_vec[10], char out_vec[10]);

int main(){
	char input_arr[10] = {1,2,3,4,5,6,7,8,9,1};
	char out_arr[10];

	find(1,input_arr,out_arr);

	for(int idx = 0; idx < 10; idx++) printf("val on out[%d] = %d\n",idx,out_arr[idx]);
}
