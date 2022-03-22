float gravity(float m1, float m2, float distance){

	#pragma HLS INTERFACE s_axilite port = return bundle = CRTLS
	#pragma HLS INTERFACE s_axilite port = m1 bundle = CRTLS
	#pragma HLS INTERFACE s_axilite port = m2 bundle = CRTLS
	#pragma HLS INTERFACE s_axilite port = distance bundle = CRTLS

	float force = 0;
	float distsquare = 0;

	if(distance==0){
		distsquare = 0.000001f;
	}
	else distsquare = distance*distance;

	force = 10.f * (m1*m2) / distsquare;

	return force;
}
