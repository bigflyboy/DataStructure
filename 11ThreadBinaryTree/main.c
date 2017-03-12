//
//  main.c
//  11ThreadBinaryTree
//
//  Created by 王志远 on 2017/3/12.
//  Copyright © 2017年 wzy. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include "string.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;
typedef char TElemType;
typedef enum{Link,thread} PointerTag;

typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode, *BiThrTree;

TElemType Nil = '#';

Status Visit(TElemType e){
    printf("%d",e);
    return OK;
}

Status CreateBitThrTree(BiThrTree *T){
    TElemType h;
    scanf("%c",&h);
    
    if(h==Nil)
        *T=NULL;
    else{
        *T=(BiThrTree)malloc(sizeof(BiThrNode));
        if(!T){
            exit(OVERFLOW);
        }
        (*T)->data=h;
        CreateBitThrTree(&(*T)->lchild);
        if((*T)->lchild)
            (*T)->LTag=Link;
        CreateBitThrTree(&(*T)->rchild);
        if((*T)->rchild)
            (*T)->RTag=Link;
    }
    return OK;
}

BiThrTree pre;

void InThreading(BiThrTree p){
    if(p){
        InThreading(p->lchild);
        if(!p->lchild){
            p->LTag=thread;
            p->lchild=pre;
        }
        if(!pre->rchild){
            pre->RTag=thread;
            pre->rchild=p;
        }
        InThreading(p->rchild);
    }
}

Status InOrderThreading(BiThrTree *Thrt,BiThrTree T){
    *Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
    if(!*Thrt){
        exit(OVERFLOW);
    }
    (*Thrt)->LTag=Link;
    (*Thrt)->RTag=thread;
    (*Thrt)->rchild=(*Thrt);
    if(!T)
        (*Thrt)->lchild=*Thrt;
    else{
        (*Thrt)->lchild=T;
        pre=(*Thrt);
        InThreading(T);
        pre->rchild=*Thrt;
        pre->RTag=thread;
        (*Thrt)->rchild=pre;
    }
    return OK;
}

Status InOrderTarverse_Thr(BiThrTree T){
    BiThrTree p;
    p=T->lchild; /* p指向根结点 */
    while(p!=T)
    { /* 空树或遍历结束时,p==T */
        while(p->LTag==Link)
            p=p->lchild;
        if(!Visit(p->data)) /* 访问其左子树为空的结点 */
            return ERROR;
        while(p->RTag==thread&&p->rchild!=T)
        {
            p=p->rchild;
            Visit(p->data); /* 访问后继结点 */
        }
        p=p->rchild;
    }
    return OK;
}

int main(int argc, const char * argv[]) {
    BiThrTree H,T;
    printf("请按前序输入二叉树(如:'ABDH##I##EJ###CF##G##')\n");
    CreateBitThrTree(&T);
    InOrderThreading(&H, T);
    printf("中序遍历(输出)二叉线索树:\n");
    InOrderTarverse_Thr(H);
    printf("\n");
    return 0;
}

















