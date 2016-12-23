#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define ERROR 0
#define OK 1
#define INFEASIBLE -1

typedef int ElemType;
typedef int Status;
typedef ElemType *Triplet;

Status InitTriplet(Triplet &T, ElemType v1,ElemType v2,ElemType v3);

int main(){
printf("How are you?/n");
 Triplet T2;
 int v1=4;

 int v2=5;
 int v3 =6;
 Status i;
 i =InitTriplet(&T2,v1,v2,v3);
//printf("Elements in D %i", D[0]);

}

Status InitTriplet(Triplet &T, ElemType v1,ElemType v2,ElemType v3){
  // construct a three element array,initial values as v1,v2,and v3
ElemType  *T = (ElemType *)malloc(3 *sizeof(ElemType));
  if(!T)exit(OVERFLOW);
  T[0] = v1;
  T[1] = v2;
  T[2] = v3;
  return OK;

}
