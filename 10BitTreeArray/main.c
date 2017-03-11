//
//  main.c
//  10BitTreeArray
//
//  Created by 王志远 on 2017/3/11.
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

#define MAXSIZE 100
#define MAX_TREE_SIZE 100

typedef int Status;
typedef int TElemType;

typedef TElemType SqBiTree[MAX_TREE_SIZE];

typedef struct{
    int level,order;
}Position;

TElemType Nil = 0;

Status visit(TElemType e){
    printf("%d",e);
    return OK;
}

Status InitBiTree(SqBiTree T){
    int i;
    for(i=0;i<MAX_TREE_SIZE;i++){
        T[i]=Nil;
    }
    return OK;
}

Status CreateBiTree(SqBiTree T){
    int i=0;
    while(i<9){
        T[i]=i+1;
        if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil){
            printf("出现无双亲的非根节点%d\n",T[i]);
            exit(ERROR);
        }
        i++;
    }
    while(i<MAX_TREE_SIZE){
        T[i]=Nil;
        i++;
    }
    return OK;
}

#define ClearBiTree InitBiTree

Status BiTreeEmpty(SqBiTree T){
    if(T[0]==Nil)
        return TRUE;
    else
        return FALSE;
}

int BiTreeDepth(SqBiTree T){
    int i,j=-1;
    for(i=MAX_TREE_SIZE;i>=0;i--)
        if(T[i]!=Nil)
            break;
    i++;
    do
        j++;
    while(i>=powl(2, j));
    return j;
}

TElemType Value(SqBiTree T,Position e){
    return T[(int)powl(2, e.level-1)+e.order-2];
}

Status Assgin(SqBiTree T,Position e,TElemType value){
    int i=(int)powl(2, e.level-1)+e.order-2;
    if(value!=Nil&&T[(i+1)/2-1]==Nil){
        return ERROR;
    }else if(value==Nil&&(T[i*2+1]!=Nil||T[i*2+2]!=Nil)){
        return ERROR;
    }
    T[i]=value;
    return OK;
}

TElemType Parent(SqBiTree T,TElemType e){
    int i;
    if(T[0]==Nil){
        return Nil;
    }
    for(i=1;i<=MAX_TREE_SIZE-1;i++){
        if(T[i]==e)
            return T[(i+1)/2-1];
    }
    return Nil;
}

TElemType LeftChild(SqBiTree T,TElemType e){
    int i;
    if(T[0]==Nil){
        return Nil;
    }
    for(i=0;i<=MAX_TREE_SIZE-1;i++)
        if(T[i]==e)
            return T[i*2+1];
    return Nil;
}

Status PreTraverse(SqBiTree T,int e){
    visit(T[e]);
    if(T[2*e+1]!=Nil)
        PreTraverse(T, 2*e+1);
    if(T[2*e+2]!=Nil)
        PreTraverse(T, 2*e+2);
    return OK;
}

Status PreOrderTraverse(SqBiTree T){
    if(!BiTreeEmpty(T)){
        PreTraverse(T, 0);
    }
    printf("\n");
    return OK;
}

/* InOrderTraverse()调用 */
void InTraverse(SqBiTree T,int e)
{
    if(T[2*e+1]!=Nil) /* 左子树不空 */
        InTraverse(T,2*e+1);
    visit(T[e]);
    if(T[2*e+2]!=Nil) /* 右子树不空 */
        InTraverse(T,2*e+2);
}

/* 初始条件: 二叉树存在 */
/* 操作结果: 中序遍历T。 */
Status InOrderTraverse(SqBiTree T)
{
    if(!BiTreeEmpty(T)) /* 树不空 */
        InTraverse(T,0);
    printf("\n");
    return OK;
}

/* PostOrderTraverse()调用 */
void PostTraverse(SqBiTree T,int e)
{
    if(T[2*e+1]!=Nil) /* 左子树不空 */
        PostTraverse(T,2*e+1);
    if(T[2*e+2]!=Nil) /* 右子树不空 */
        PostTraverse(T,2*e+2);
    visit(T[e]);
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 后序遍历T。 */
Status PostOrderTraverse(SqBiTree T)
{
    if(!BiTreeEmpty(T)) /* 树不空 */
        PostTraverse(T,0);
    printf("\n");
    return OK;
}

int main(int argc, const char * argv[]) {
    Status i;
    Position p;
    TElemType e;
    SqBiTree T;
    InitBiTree(T);
    CreateBiTree(T);
    printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    printf("前序遍历二叉树\n");
    PreOrderTraverse(T);
    printf("中序遍历二叉树\n");
    InOrderTraverse(T);
    printf("后序遍历二叉树\n");
    PostOrderTraverse(T);
    return 0;
}
























