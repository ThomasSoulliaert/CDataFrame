//
// Created by tsoul on 29/03/2024.
//

#ifndef PROJET_C_FONCTIONS_H
#define PROJET_C_FONCTIONS_H

typedef struct
{
    char *Title;
    int Taille_Physique ;
    int Taille_Logique ;
    int *Data;
}COLUMN;

COLUMN *creat_column(char* title);


#endif //PROJET_C_FONCTIONS_H