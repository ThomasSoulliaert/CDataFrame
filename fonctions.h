#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PROJET_C_FONCTIONS_H
#define PROJET_C_FONCTIONS_H

#define REALOC_SIZE 256

typedef struct
{
    char * Title;
    int TP;
    int TL;
    int * Data;
}COLUMN; // Nouveau type de structure : type "COLUMN"

// Partie I : Colonne
COLUMN *create_column(char*);
int insert_value(COLUMN*, int);
void delete_column(COLUMN**);
void print_col(COLUMN*);
int occurrence(COLUMN*, int);
int position(COLUMN*, int);
int superieur(COLUMN*, int);
int inferieur(COLUMN*, int);
int egale(COLUMN*, int);


// Partie II : DataFrame
// Partie 2.1 : Alimentation
COLUMN** creat_DATAFRAME(int);
void fill_DataFrame(COLUMN**, int);

// Partie 2.2 : Affichage
void print_DataFrame(COLUMN** , int);
void print_DataFrameLimitLine(COLUMN**, int, int);
void print_DataFrameLimitColumn(COLUMN**, int, int);

// Partie 2.3 : Opérations usuelles
void fill_DataFrameLine(COLUMN** , int);
void del_DataFrameLine(COLUMN** , int);
void add_DataFrameColumn(COLUMN** , int*);
void del_DataFrameColumn(COLUMN** , int*);
void rename_Column(COLUMN** , int*);
int Research_Value(COLUMN** , int , int);
void ReplaceValue(COLUMN** , int);
void printName(COLUMN** , int);

// Partie 2.4 : Analyses & Statistiques
int numberLines_DataFrame(COLUMN**, int);
int numberColumns_DataFrame(COLUMN** , int);
int numberValues_Equal_DataFrame(COLUMN** , int , int);
int numberValues_Sup_DataFrame(COLUMN** , int , int);
int numberValues_Inf_DataFrame(COLUMN** , int , int);


#endif //PROJET_C_FONCTIONS_H