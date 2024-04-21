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
COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
int occurence(COLUMN* col,int x);
int position(COLUMN* col, int x);
int superieur(COLUMN *col, int x);
int inferieur(COLUMN *col, int x);
int egale(COLUMN *col, int x);

/// Partie : Alimentation
COLUMN** creat_DATAFRAME(int taille);
void fill_DataFrame(COLUMN** DataFrame, int nombreCol);

/// Partie : Affichage
void print_DataFrame(COLUMN** DataFrame, int nombreCol);
void print_DataFrameLimitLigne(COLUMN** DataFrame, int nombreCol, int LigneLimite);
void print_DataFrameLimitCol(COLUMN** DataFrame, int nombreCol, int ColonneLimite);

/// Partie : Opérations
void fill_DataFrameLigne(COLUMN** DataFrame, int nombreCol);
void del_DataFrameLigne(COLUMN** DataFrame, int nombreCol);
void add_DataFrameColonne(COLUMN** DataFrame, int *nbcol);
void del_DataFrameColonne(COLUMN** DataFrame, int *nbcol);
void rename_Colonne(COLUMN** DataFrame, int* nbCol);
int Research_Value(COLUMN** DataFrame, int nbcol, int x);
void ReplaceValue(COLUMN** DataFrame, int nbcol);
void printName(COLUMN** DataFrame, int nbcol);

/// Partie : Analyses & Statistiques
int Nbr_lignes_DataFrame(COLUMN** DataFrame, int nb_col);
int Nbr_colonnes_DataFrame(COLUMN** DataFrame);
int Nbr_val_egale_DataFrame(COLUMN** DataFrame, int valeur, int nb_col);
int Nbr_val_sup_DataFrame(COLUMN** DataFrame, int valeur, int nb_col);
int Nbr_val_inf_DataFrame(COLUMN** DataFrame, int valeur, int nb_col);


#endif //PROJET_C_FONCTIONS_H