//
//  main.c
//  09String
//
//  Created by sj on 17/3/9.
//  Copyright © 2017年 wzy. All rights reserved.
//

#include <stdio.h>
#include "string.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40

typedef int Status;
typedef int ElemType;

typedef char String[MAXSIZE+1];//0号单元存放串的长度

Status StrAssign(String T, char *chars){
    int i;
    if(strlen(chars)>MAXSIZE){
        return ERROR;
    }else{
        T[0] = strlen(chars);
        for(i=1;i<=T[0];i++){
            T[i]=*(cahrs+i-1);
        }
        return OK;
    }
}

Status StrCopy(String T,String S){
    int i;
    for(i=0;i<=S[0];i++)
        T[i]=S[i];
    return OK;
}

Status StrEmpty(String S){
    if(S[0]==0)
        return TRUE;
    else
        return FALSE;
}

int StrCompare(String S,String T){
    int i;
    for(i=1;i<=S[0]&&i<=T[0];++i){
        if(S[i]!=T[i]){
            return S[i]-T[i];
        }
    }
    return S[0]-T[0];
}

int StrLength(String S){
    return S[0];
}

Status ClearString(String S){
    S[0] = 0;
    return OK;
}

Status Concat(String T,String S1,String S2){
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
