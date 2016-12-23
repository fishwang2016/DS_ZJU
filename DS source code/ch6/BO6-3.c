 /* bo6-3.c �������Ķ��������洢(�洢�ṹ��c6-3.h����)�Ļ������� */
 Status CreateBiThrTree(BiThrTree *T)
 { /* ��������������������н���ֵ,�������������T */
   /* 0(����)/�ո�(�ַ���)��ʾ�ս�� */
   TElemType h;
 #if CHAR
   scanf("%c",&h);
 #else
   scanf("%d",&h);
 #endif
   if(h==Nil)
     *T=NULL;
   else
   {
     *T=(BiThrTree)malloc(sizeof(BiThrNode));
     if(!*T)
       exit(OVERFLOW);
     (*T)->data=h; /* ���ɸ����(����) */
     CreateBiThrTree(&(*T)->lchild); /* �ݹ鹹�������� */
     if((*T)->lchild) /* ������ */
       (*T)->LTag=Link;
     CreateBiThrTree(&(*T)->rchild); /* �ݹ鹹�������� */
     if((*T)->rchild) /* ���Һ��� */
       (*T)->RTag=Link;
   }
   return OK;
 }

 BiThrTree pre; /* ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ�� */
 void InThreading(BiThrTree p)
 { /* ������������������������㷨6.7 */
   if(p)
   {
     InThreading(p->lchild); /* �ݹ������������� */
     if(!p->lchild) /* û������ */
     {
       p->LTag=Thread; /* ǰ������ */
       p->lchild=pre; /* ����ָ��ָ��ǰ�� */
     }
     if(!pre->rchild) /* ǰ��û���Һ��� */
     {
       pre->RTag=Thread; /* ������� */
       pre->rchild=p; /* ǰ���Һ���ָ��ָ����(��ǰ���p) */
     }
     pre=p; /* ����preָ��p��ǰ�� */
     InThreading(p->rchild); /* �ݹ������������� */
   }
 }

 Status InOrderThreading(BiThrTree *Thrt,BiThrTree T)
 { /* �������������T,����������������,Thrtָ��ͷ��㡣�㷨6.6 */
   *Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
   if(!*Thrt)
     exit(OVERFLOW);
   (*Thrt)->LTag=Link; /* ��ͷ��� */
   (*Thrt)->RTag=Thread;
   (*Thrt)->rchild=*Thrt; /* ��ָ���ָ */
   if(!T) /* ���������գ�����ָ���ָ */
     (*Thrt)->lchild=*Thrt;
   else
   {
     (*Thrt)->lchild=T;
     pre=*Thrt;
     InThreading(T); /* ��������������������� */
     pre->rchild=*Thrt;
     pre->RTag=Thread; /* ���һ����������� */
     (*Thrt)->rchild=pre;
   }
   return OK;
 }

 Status InOrderTraverse_Thr(BiThrTree T,Status(*Visit)(TElemType))
 { /* �����������������T(ͷ���)�ķǵݹ��㷨���㷨6.5 */
   BiThrTree p;
   p=T->lchild; /* pָ������ */
   while(p!=T)
   { /* �������������ʱ,p==T */
     while(p->LTag==Link)
       p=p->lchild;
     if(!Visit(p->data)) /* ������������Ϊ�յĽ�� */
       return ERROR;
     while(p->RTag==Thread&&p->rchild!=T)
     {
       p=p->rchild;
       Visit(p->data); /* ���ʺ�̽�� */
     }
     p=p->rchild;
   }
   return OK;
 }