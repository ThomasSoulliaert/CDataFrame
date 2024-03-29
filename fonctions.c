//
// Created by tsoul on 29/03/2024.
//

#include "fonctions.h"

COLUMN * create_column( char *title)
{
    COlUMN *col = (COLUMN*)malloc(sizeof(COLUMN));
    col->TaillePhysique = 0 ;
    col->TailleLogique = 0;
    col->date = NULL;
    col ->Titre = (char*)malloc((strlen(titre)+1)*sizeof(char));
    strcpy(col->Titre,title);
    return col;
}