//
//  main.c
//  DataStructure
//
//  Created by sj on 17/3/1.
//  Copyright © 2017年 wzy. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int Status;     //Status是函数的类型，其值是函数结果状态代码，如OK等
typedef int ElemType;   //ElemType类型根据实际情况而定，这里假设为int

Status visit(ElemType c){
    printf("%d", c);
    return OK;
}

typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

Status InitList(SqList *L){
    L->length=0;
    return OK;
}

Status ListEmpty(SqList L){
    if (L.length == 0) {
        return TRUE;
    }else{
        return FALSE;
    }
}

//初始条件：顺序线性表L已存在。操作结果：将L置为空表
Status ClearList(SqList *L){
    L->length = 0;
    return OK;
}

//初始条件：顺序线性表L已存在。操作结果：取出i位置的元素。
Status GetItem(SqList *L,int i,ElemType *e){
    if(L->length==0 || i<1 || i>L->length){
        return ERROR;
    }
    *e = L->data[i-1];
    return OK;
}

int ListLength(SqList *L){
    return L->length;
}

/*初始条件：线性表L已经存在*/
/*操作结果：返回L中第一个与e满足关系的元素的位置*/
/*若这样的元素不存在，侧返回值为0*/
int LocateElem(SqList L,ElemType e){
    int i;
    if(L.length == 0){
        return 0;
    }
    for(i=0;i<L.length;i++){
        if(L.data[i]==e){
            break;
        }
    }
    if(i>=L.length){
        return 0;
    }
    return i+1;
}

/*在i的位置插入元素*/

Status ListInsert(SqList *L,int i,ElemType e){
    int k;
    if(L->length == MAXSIZE){
        return ERROR;
    }
    if(i<1 || i>L->length+1){
        return ERROR;
    }
    if(i<=L->length){
        for(k=L->length-1;k>=i-1;k--){
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}
/*删除第i个元素*/
Status ListDelete(SqList *L,int i,ElemType *e){
    int k;
    if(L->length == 0){
        return ERROR;
    }
    if(i<1 || i>L->length){
        return ERROR;
    }
    if(i<L->length){
        for(k=i;k<L->length;k++)
            L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}

Status ListTraverse(SqList L){
    int i;
    for(i=0;i<L.length;i++){
        visit(L.data[i]);
    }
    printf("\n");
    return OK;
}

void unionl(SqList *La,SqList Lb){
    int La_len,Lb_len,i;
    ElemType e;
    La_len = ListLength(La);
    Lb_len = ListLength(&Lb);
    for(i=1;i<=Lb_len;i++){
        GetItem(&Lb, i, &e);
        if(!LocateElem(*La, e)){
            ListInsert(La, ++La_len, e);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
