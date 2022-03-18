void divide(unsigned char N, unsigned char D, unsigned char *Q, unsigned char *R)
{
	if(D != 0){
		*Q = 0;
		*R = 0;

		for(int i = 7; i >= 0; i--){
			*R = *R << 1;

			char iBitN = (N & (1 << i)) >> i;

			*R ^= (-iBitN ^ (*R)) & (1 << 0);

			if((*R) >= D){
				*R = *R - D;

				*Q |= 1 << i;
			}
		}
	}
}
