//
//  main.c
//  01stack
//
//  Created by sj on 17/3/7.
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

typedef int Status;
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

//顺序栈结构
typedef struct{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

Status visit(SElemType c){
    printf("%d",c);
    return OK;
}

Status InitStack(SqStack *S){
    S->top = -1;
    return OK;
}

Status ClearStack(SqStack *S){
    S->top = -1;
    return OK;
}

Status StackEmpty(SqStack S){
    if(S.top == -1){
        return TRUE;
    }else{
        return FALSE;
    }
}

int StackLength(SqStack S){
    return S.top+1;
}

Status GetTop(SqStack S,SElemType *e){
    if(S.top == -1){
        return ERROR;
    }
    *e = S.data[S.top];
    return OK;
}

Status Push(SqStack *S,SElemType e){
    if(S->top == MAXSIZE-1){
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}

Status Pop(SqStack *S,SElemType *e){
    if(S->top == -1){
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}

Status StackTraverse(SqStack S){
    int i;
    i = 0;
    while(i<=S.top){
        visit(S.data[i++]);
    }
    printf("\n");
    return OK;
}

int main(int argc, const char * argv[]) {
    int j;
    SqStack s;
    int e;
    if(InitStack(&s) == OK){
        for(j=1;j<=10;j++){
            Push(&s,j);
        }
    }
    printf("栈中的元素依次为：");
    StackTraverse(s);
    Pop(&s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    Pop(&s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    Pop(&s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    Pop(&s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    GetTop(s, &e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    return 0;
}
