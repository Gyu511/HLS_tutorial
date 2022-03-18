#include <ap_int.h> //for size custom

//ap_unit<원하는 비트> uint = unsigned int
ap_uint<17> simpleALU(ap_uint<17> inA, ap_uint<17> inB, ap_uint<1> op){

	if (op == 1) return inA + inB;
	else return inA - inB;
}
