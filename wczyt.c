#include <stdio.h>
#include <stdlib.h>

void wczyt(char *nazwapliku, int *n, int *m)
{
    FILE *file = fopen(nazwapliku, "r");
    if(file==NULL) {
        fprintf(stderr, "BLAD ODCZYTU PLIKU\n");
    }

    int i=0;
    int j=0;

    while(1) //obliczanie ilosci kolumn
    {
        char z = fgetc(file);
        if( z == '\n')
        {
            *n=i;
            break;
        }
        i++;
    }

    while(1) //obliczanie ilosci wierszy
    {
        j++;
        char z;
        for(i = 1; i <= *n ; i++) z = fgetc(file);
        z = fgetc(file);
        if(z==EOF)
        {
            *m=j;
            break;
        }
    }

    //printf("n:%d m:%d \n",*n,*m);
    rewind(file);

    char **tab = (char **)calloc(3 , sizeof(char *)); //alokowanie pamieci dla tab
    if (tab == NULL) //err
    {
        perror("Błąd alokacji pamięci dla wskaźników na wiersze");
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        tab[i] = (char *)calloc(2049 , sizeof(char));
        if (tab[i] == NULL) { //err
            perror("Błąd alokacji pamięci dla wiersza");
            for (int j = 0; j < i; j++) {
                free(tab[j]);
            }
            free(tab);
            return 1;
        }
    }

    for(int j=0;j<3;j++) //przepisywanie pierwszych 3 wierszy danych wejsciowych
    {
        for(int i=0;i<*n;i++)
        {
            char z=fgetc(file);
            tab[j][i]=z;
            //printf("%c",tab[j][i]);
        }
        //printf("\n");
        char z=fgetc(file);
    }

    char **temp = (char **)calloc(10, sizeof(char *)); //alokowanie pamieci dla temp
    if (temp == NULL) { //err
        perror("Błąd alokacji pamięci dla wskaźników na wiersze");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        temp[i] = (char *)calloc(1024, sizeof(char));
        if (temp[i] == NULL) { //err
            perror("Błąd alokacji pamięci dla wiersza");
            for (int j = 0; j < i; j++) {
                free(temp[j]);
            }
            free(temp);
            return 1;
        }
    }

    int x=1,y=1;

    for(int i=0;x<*n;i++) //analiza wejscia, zmiana z X na liczby dokąd można dojsc (N-2, E-4, S-8, W-16)
    {
        //printf("x:%d y:%d ",x,y);
        if(tab[1-1][x]==' ') temp[y/2][i]+=2;
        if(tab[1+1][x]==' ') temp[y/2][i]+=8;
        if(tab[1][x+1]==' ') temp[y/2][i]+=4;
        if(tab[1][x-1]==' ') temp[y/2][i]+=16;
        //printf("%d \n",temp[y/2][i]);
        x=x+2;
    }
    x=1;

    for(int j=0;y<*m-1;j++)
    {
        for(int i=0;i<*n;i++) //wczytywanie nastepnej linijki danych wejsciowych
        {
            tab[0][i]=tab[2][i];
            //printf("%c",tab[0][i]);
        }
        //printf("\n");
        for(int k=1;k<3;k++)
        {
            for(int i=0;i<*n;i++)
            {
                char z=fgetc(file);
                tab[k][i]=z;
                //printf("%c",tab[k][i]);
            }
            char z=fgetc(file);
            //printf("\n");
        }

        y=y+2;

        for(int i=0;x<*n;i++) //analiza wejscia, zmiana z X na liczby dokąd można dojsc (N-2, E-4, S-8, W-16)
        {
            //printf("x:%d y:%d ",x,y);
            if(tab[1-1][x]==' ') temp[(j)%10][i]+=2;
            if(tab[1+1][x]==' ') temp[(j)%10][i]+=8;
            if(tab[1][x+1]==' ') temp[(j)%10][i]+=4;
            if(tab[1][x-1]==' ') temp[(j)%10][i]+=16;
            //printf("%d \n",temp[(j)%10][i]);
            x=x+2;
        }
        x=1;

        if((y+1)%10==0) //uzupelnilismy caly jeden prostokat i go zapisujemy do pliku
        {
            printf("ZAPIS\n");
            ///ZAPISYWANIE DO PLIKU TRZEBA TUTAJ WSTAWIĆ

            for(int k=0;k<10;k++)free(temp[i]);  //zwalnianie pamieci
            free(temp);

            char **temp = (char **)calloc(10, sizeof(char *)); //alokowanie pamieci dla temp
            if (temp == NULL) { //err
                perror("Błąd alokacji pamięci dla wskaźników na wiersze");
                return 1;
            }
            for (int i = 0; i < 10; i++) {
                temp[i] = (char *)calloc(1024, sizeof(char));
                if (temp[i] == NULL) { //err
                    perror("Błąd alokacji pamięci dla wiersza");
                    for (int j = 0; j < i; j++) {
                        free(temp[j]);
                    }
                    free(temp);
                    return 1;
                }
            }
        }
    }
}