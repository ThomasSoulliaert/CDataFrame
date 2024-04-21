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
COLUMN *create_column(char *title);
int insert_value(COLUMN *colonne, int value);
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
int Nbr_lignes_DataFrame(COLUMN** DataFrame, int nb_col);
int Nbr_colonnes_DataFrame(COLUMN** DataFrame);
int Nbr_val_egale_DataFrame(COLUMN** DataFrame, int valeur, int nb_col);
int Nbr_val_sup_DataFrame(COLUMN** DataFrame, int valeur, int nb_col);
int Nbr_val_inf_DataFrame(COLUMN** DataFrame, int valeur, int nb_col);


#endif //PROJET_C_FONCTIONS_H