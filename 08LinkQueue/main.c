//
//  main.c
//  08LinkQueue
//
//  Created by sj on 17/3/8.
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

typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

typedef struct{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
    QueuePtr front,rear;
} LinkQueue;

Status visit(QElemType c){
    printf("%d",c);
    return OK;
}

Status InitQueue(LinkQueue *Q){
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front){
        exit(OVERFLOW);
    }
    Q->front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue *Q){
    while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

Status ClearQueue(LinkQueue *Q){
    QueuePtr p,q;
    Q->rear = Q->front;
    p = Q->front->next;
    Q->front->next = NULL;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

Status QueueEmpty(LinkQueue Q){
    if(Q.front == Q.rear){
        return TRUE;
    }else{
        return FALSE;
    }
}

int QueueLength(LinkQueue Q){
    int i = 0;
    QueuePtr p;
    p = Q.front;
    while(Q.rear!=p){
        i++;
        p = p->next;
    }
    return i;
}

Status GetHead(LinkQueue Q,QElemType *e){
    QueuePtr p;
    if(Q.front == Q.rear){
        return ERROR;
    }
    p = Q.front->next;
    *e = p->data;
    return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e){
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if(!s){
        exit(OVERFLOW);
    }
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e){
    QueuePtr p;
    if(Q->front == Q->rear)
        return ERROR;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return OK;
}

Status QueueTraverse(LinkQueue Q)
{
    QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

int main(int argc, const char * argv[]) {
    int i;
    QElemType d;
    LinkQueue q;
    i = InitQueue(&q);
    if(i){
        printf("成功地构造了一个空队列！\n");
    }
    QueueTraverse(q);
    EnQueue(&q, -5);
    EnQueue(&q, -25);
    EnQueue(&q, -35);
    QueueTraverse(q);
    DeQueue(&q, &d);
    QueueTraverse(q);
    return 0;
}
