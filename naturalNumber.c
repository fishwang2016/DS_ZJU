#include<stdio.h>

int main(){

  int number;
  scanf("%d",&number);
  int step =1;

  while(number !=1 || step >1000){
  	  printf("%d,",number);


	  if (number % 2 == 0){

	  	number = number/2 ;
	    
	  }else{

	  	number = number * 3 +1;

	  }

	  step++;
  }
   printf("%d\n",number);
   printf("step=%d\n",step);
  return 0;

}