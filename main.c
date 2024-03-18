//
// Created by jakub on 18.03.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "wczyt.h"
#include <io.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
//    if(_chmod(argv[1], _S_IREAD) != 0){
//        printf("siusiak");
//        return 1
//    }

    int n = 0;
    int m = 0;
    printf("sijaoi");
    wczyt(argv[1],&n,&m);
    printf("%d , %d",n,m);
}