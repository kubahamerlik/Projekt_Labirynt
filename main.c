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

    int num_files = 100;

    FILE *temp_files[num_files];

    //Tworzenie i otwieranie plików tymczasowych
    for (int i = 0; i < num_files; i++) {
        temp_files[i] = tmpfile();
        if (temp_files[i] == NULL) {
            perror("Nie udało się utworzyć pliku tymczasowego");
            exit(1);
        }
    }
    wczyt(argv[1], temp_files[2], &n, &m);

    printf("%d , %d",n,m);


    for (int i = 0; i < num_files; i++) {
        fclose(temp_files[i]);
        //Po zamknięciu pliku tymczasowego, zostanie on automatycznie usunięty
    }
}