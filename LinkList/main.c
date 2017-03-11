//
//  main.c
//  LinkList
//
//  Created by sj on 17/3/4.
//  Copyright © 2017年 wzy. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

//打印一个Elemtype类型的数
Status visit(ElemType c){
    printf("%d",c);
    return OK;
}

typedef struct Node *LinkList;

//初始化顺序线性表
Status InitList(LinkList *L){
    *L=(LinkList)malloc(sizeof(Node));
    if(!(*L)){
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}

Status ListEmpty(LinkList *L){
    if((*L)->next){
        return FALSE;
    }else{
        return TRUE;
    }
}

Status ClearList(LinkList *L){
    LinkList p,q;
    p = (*L)->next;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

int ListLength(LinkList L){
    int i = 0;
    LinkList p = L->next;
    while(p){
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L,int i,ElemType *e){
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while(p && j<i){
        p = p->next;
        ++j;
    }
    if(!p || j>i){
        return ERROR;
    }
    *e = p->data;
    return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e){
    LinkList p,s;
    int j;
    p = *L;
    j = 1;
    while(p && j<i){
        p = p->next;
        ++j;
    }
    if(!p||j>i){
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status LinkDelete(LinkList *L,int i,ElemType *e){
    int j;
    LinkList p,q;
    p = *L;
    j = 1;
    while(p->next || j<i){
        p = p->next;
        ++j;
    }
    if(!(p->next)||j>i){
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

Status ListTraverse(LinkList L){
    LinkList p = L->next;
    while(p){
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
//头插法建立List
void CreateListHead(LinkList *L, int n){
    LinkList p;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for(i=0;i<n;i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}
//尾插法建立List
void CreateListTail(LinkList *L, int n){
    LinkList p,r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r= *L;
    for(i=0; i<n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

int main(int argc, const char * argv[]) {
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i = InitList(&L);
    //printf("初始化L后：LinkLength(L)=%d\n",ListLength(L));
    
    for(j=1;j<=5;j++){
        i = ListInsert(&L, 1, j);
    }
    printf("初始化L后：LinkLength(L)=%d\n",ListLength(L));
    ListTraverse(L);
    i=ClearList(&L);
    printf("清空L后：ListLength(L)=%d\n",ListLength(L));
    
    for(j = 1;j <=10;j++){
        i = ListInsert(&L, j, j);
    }
    printf("初始化L后：LinkLength(L)=%d\n",ListLength(L));
    ListTraverse(L);
    i = ClearList(&L);
    CreateListHead(&L, 13);
    printf("头插法L后：LinkLength(L)=%d\n",ListLength(L));
    ListTraverse(L);
    CreateListTail(&L, 13);
    printf("尾插法L后：LinkLength(L)=%d\n",ListLength(L));
    ListTraverse(L);
    return 0;
}
