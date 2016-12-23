#include<stdio.h>

int main(){
int m,n,i;
scanf("%d,%d",&m,&n);
int min = m;
if (n<min) min =n;

for(i=min;i>=1;i--){
  if (m%i ==0 && n%i==0){
   printf("%d\n",i);
   break;
  }

}
 return 0;

}