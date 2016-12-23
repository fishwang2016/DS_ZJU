#include<stdio.h>

int main(){


	int i =1;
	int s =0;
	int n;
	scanf("%d",&n);
	while (i <= 2*n-1){
		//printf("%d\n",i);


		s=s+i;
		
		i = i+2;
	}

	printf("%d\n",s);
	return 0;
}