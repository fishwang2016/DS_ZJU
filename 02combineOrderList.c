#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
} Node;
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    //L2 = Read();
    //L = Merge(L1, L2);
    // Print(L);
    Print(L1);
    //Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Read(){
	/*create list*/

	List L;
    List p;

	int i;

	L = (List) malloc(sizeof(Node));
	L->Next = NULL;


    int number=0;

    number = scanf("%d,",&number);

    for (i=0;i <number; i++){

    	p = (List) malloc(sizeof(Node));
    	scanf(&p->Data);
    	p->Next = L->Next;
    	L->Next = p;

    }
	return L;
}


void Print(List L){
	List p;
    p = L->Next;
    printf("printing...");
    while (p){
    	printf("%d ",p->Data);

    	p = p->Next;
    }
    printf("\n");


}
