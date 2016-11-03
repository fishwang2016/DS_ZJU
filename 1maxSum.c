#include<stdio.h>
int main(){
  int number,i; 
  scanf("%d", &number);    
  int a[number];
  for (i=0; i<number; i++){
     scanf("%d,",&a[i]);
   }
  // printf("Your input is:\n");
  // for (i=0;i<number; i++){
  //   printf("%d ",a[i]);
  // }
  // printf("\n");
  int max, sum,j;
  int lower=0, upper=0;
  int flag = 0;
  max =  a[0];


  for (i=0;i<number;i++){
      flag = 1;
      for(j=i;j<number; j++){
         if (flag){

          sum = a[i];
          flag = 0;

         }else{
          
           sum=sum+a[j];
         }

         if(sum>max){
           max =sum;
           upper = a[j];
           lower = a[i];
         }
      } 
  }
   if (max < 0){
    max = 0;
    lower =a[0];
    upper = a[number-1];
   }
  
   printf("%d %d %d\n",max, lower,upper);
   return 0;

}
