//
// Created by tsoul on 29/03/2024.
//
#include <stdio.h>
#include "fonctions.h"

COLUMN * create_column( char *title)
{
    COlUMN *col = (COLUMN*)malloc(sizeof(COLUMN));
    col->Taille_Physique = 0 ;
    col->Taille_Logique = 0;
    col->Data = NULL;
    col ->Title = (char*)malloc((strlen(titre)+1)*sizeof(char));
    strcpy(col->Title,title);
    return col;
}