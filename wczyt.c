//
// Created by jakub on 18.03.2024.
//
#include <stdio.h>
#include <stdlib.h>

void wczyt(const char *filename, int *n, int *m)
{
    printf("suema");
    FILE *file = fopen("dane1.txt", "r");

    if(file==NULL) {
        fprintf(stderr, "BLAD ODCZYTU PLIKU\n");
    }

    int i=0;
    int j=1;

    while(1)
    {
        char z = fgetc(file);
        printf("%c ", z);
        if( z == '\n')
        {
            *n=i;
            break;
        }
        i++;
    }
    while(1)
    {
        j++;
        char z;

        for(i = 1; i <= *n ; i++) {
            z = fgetc(file);
        }

        z = fgetc(file);

        if(z==EOF)
        {
            *m=j;
            break;
        }
    }

}