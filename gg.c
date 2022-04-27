void dec_to_bin (int n, char s[]){
	int i,j; char v[17];
	for(i=0; i<16; i++){
		v[i]= n%2+48;//adunam 48 pentru codul ASCII
		n=n/2;	
	}//impartiri repetate la 2 si adaugare in vector v pana la 16 biti
	v[16]='\0';
	i=i-1;
	for(j=i; j>=0; j--)
		s[j]=v[i-j];//intoarcerea vectorului v pentru ca s sa fie in baza 2
	s[16]='\0';
}

int bin_to_dec (char s[]){
	int i,n=0,aux=1;
	for(i=15; i>=0; i--){
		n=n+(s[i]-48)*aux; //scadem 48 pentru codul ASCII
		aux=aux*2;} //inmultim cu 2 pentru a transforma in baza 10;
	return n;
	
}