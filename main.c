//
// Created by jakub on 18.03.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "wczyt.h"


int main(int argc, char* argv[])
{

    int n = 0;
    int m = 0;

    wczyt(argv[1],&n,&m);

    printf("%d , %d",n,m);
}