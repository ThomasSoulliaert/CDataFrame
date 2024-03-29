//
// Created by tsoul on 29/03/2024.
//
#include <stdio.h>
#include "fonctions.h"
#include "string.h"

COLUMN * create_column(char *title)
{
    COLUMN *col = (COLUMN*) malloc(sizeof(COLUMN));
    col->Taille_Physique = 0 ;
    col->Taille_Logique = 0;
    col->Data = NULL;
    col ->Title = (char*) malloc((strlen(title)+1)*sizeof(char));
    strcpy(col->Title,title);
    return col;
}

int insert_value(COLUMN* col, int value)
{

}