//
//  main.c
//  StaticLinkList
//
//  Created by sj on 17/3/4.
//  Copyright © 2017年 wzy. All rights reserved.
//

#include <stdio.h>
#include "ctype.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include "string.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000

typedef int Status;
typedef char ElemType;

Status visit(ElemType e){
    printf("%c",c);
    return OK;
}

typedef struct{
    ElemType data;
    int cur;
}Component,StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space){
    int i;
    for(i=0;i<MAXSIZE;i++){
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0;
    return OK;
}

int Malloc_SSL(StaticLinkList space){
    int i = space[0].cur;
    if(space[0].cur){
        space[0].cur = space[i].cur;
    }
}

void Free_SSL(StaticLinkList space, int k){
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

int LinkLength(StaticLinkList L){
    int j = 0;
    int i = L[MAXSIZE-1].cur;
    while(i){
        i = L[i].cur;
        j++;
    }
    return j;
}

Status LinkInsert(StaticLinkList L, int i, ElemType e){
    int j,k,l;
    k = MAXSIZE - 1;
    if(i<1 || i>ListLength(L)+1){
        return ERROR;
    }
    j = Malloc_SSL(L);
    if(j){
        L[j].data = e;
        for(l = 1; l<=i-1;l++){
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
