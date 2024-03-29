//
// Created by tsoul on 29/03/2024.
//
#include <stdio.h>
#include <stdlib.h>

#define REALOC_SIZE 256

int main()
{
    typedef struct
    {
        char Titre[100];
        int Taille_physique;
        int Taille_logique;
        int Data[REALOC_SIZE];
    }column;

    printf("Hello world\n");
    printf("Test OK");
    return 0;
}