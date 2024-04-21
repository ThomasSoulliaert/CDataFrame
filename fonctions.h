//
// Created by SOULLIAERT & YE on 29/03/2024.
//


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
}COLUMN; /// Nouveau type de structure : type "COLUMN"

/// Partie : Fonctions de base
COLUMN *create_column(char *titre);
int insert_value(COLUMN *colonne, int valeur);
void delete_column(COLUMN **colonne);
void print_col(COLUMN *colonne);
int occurrence(COLUMN *colonne,int x);
int position(COLUMN *colonne, int x);
int superieur(COLUMN *colonne, int x);
int inferieur(COLUMN *colonne, int x);
int egale(COLUMN *colonne, int x);

/// Partie : Alimentation
COLUMN** creat_DATAFRAME(int taille);
void fill_DataFrame(COLUMN** DataFrame, int nombreColonne);

/// Partie : Affichage
void print_DataFrame(COLUMN** DataFrame, int nombreColonne);
void print_DataFrameLimitLine(COLUMN** DataFrame, int nombreColonne, int LigneLimite);
void print_DataFrameLimitColumn(COLUMN** DataFrame, int nombreColonne, int ColonneLimite);

/// Partie : Opérations
void fill_DataFrameLine(COLUMN** DataFrame, int nombreColonne);
void del_DataFrameLine(COLUMN** DataFrame, int nombreColonne);
void add_DataFrameColumn(COLUMN** DataFrame, int *nombreColonne);
void del_DataFrameColumn(COLUMN** DataFrame, int *nombreColonne);
void rename_Column(COLUMN** DataFrame, int *nombreColonne);
int Research_Value(COLUMN** DataFrame, int nombreColonne, int x);
void ReplaceValue(COLUMN** DataFrame, int nombreColonne);
void printName(COLUMN** DataFrame, int nombreColonne);

/// Partie : Analyses & Statistiques
int numberLines_DataFrame(COLUMN** DataFrame, int nombreColonne);
int numberColumns_DataFrame(COLUMN** DataFrame);
int numberValues_Equal_DataFrame(COLUMN** DataFrame, int x, int nombreColonne);
int numberValues_Sup_DataFrame(COLUMN** DataFrame, int x, int nombreColonne);
int numberValues_Inf_DataFrame(COLUMN** DataFrame, int x, int nombreColonne);


#endif //PROJET_C_FONCTIONS_H