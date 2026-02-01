# CDataFrame

Date de rendu : 19/05/2024

Promo 2028, P1, Groupe D
Binôme :
 - SOULLIAERT Thomas
 - YE Lucas


# Fichiers :
Dans le dossier remis, nous avons plusieurs fichiers :
 - main.c : une série d'instructions afin de tester les différentes fonctionnalités de notre programme.
 - fonctions.c : ensemble des fonctions nécessaires au projet
 - fonctions.h
 - README.txt : instructions


# Lancement du programme
Vous devez ouvrir le fichier main.c afin de lancer le programme.
L'ensemble des instructions sera donné par des messages qui s'afficheront sur la console.
Chaque instruction dans la console est reliée à une fonction qui a été appelée dans le programme main.c


# Structure du Code
Partie I : Colonne
1. Création et gestion des colonnes
    COLUMN *create_column(char* titre) : Crée dynamiquement une colonne vide avec un titre spécifié.
    int insert_value(COLUMN *colonne, int valeur) : Insère une valeur entière dans une colonne.
    void delete_column(COLUMN **colonne) : Libère la mémoire allouée pour une colonne et ses données.
    void print_col(COLUMN *colonne) : Affiche toutes les valeurs d'une colonne.
    int occurrence(COLUMN *colonne, int x) : Retourne le nombre d'occurrences d'une valeur dans une colonne.
    int position(COLUMN *colonne, int x) : Retourne la valeur présente à une position spécifique dans une colonne.
    int superieur(COLUMN *colonne, int x) : Retourne le nombre de valeurs supérieures à une valeur donnée dans une colonne.
    int inferieur(COLUMN *colonne, int x) : Retourne le nombre de valeurs inférieures à une valeur donnée dans une colonne.
    int egale(COLUMN *colonne, int x) : Retourne le nombre de valeurs égales à une valeur donnée dans une colonne.


Partie II : DataFrame
2.1 : Alimentation
    COLUMN** creat_DATAFRAME(int taille) : Crée dynamiquement un tableau de colonnes de taille spécifiée.
    void fill_DataFrame(COLUMN** DataFrame, int nombreColonne) : Demande à l'utilisateur de remplir le DataFrame avec des titres de colonnes et des valeurs.


2.2 : Affichage
    void print_DataFrame(COLUMN** DataFrame, int nombreColonne) : Affiche l'ensemble du DataFrame.
    void print_DataFrameLimitLine(COLUMN** DataFrame, int nombreColonne, int LigneLimite) : Affiche les lignes du DataFrame jusqu'à une certaine limite.
    void print_DataFrameLimitColumn(COLUMN** DataFrame, int nombreColonne, int ColonneLimite) : Affiche les colonnes du DataFrame jusqu'à une certaine limite.


2.3 : Opérations usuelles
    void fill_DataFrameLine(COLUMN** DataFrame, int nombreColonne) : Ajoute une ligne dans une colonne du DataFrame.
    void del_DataFrameLine(COLUMN** DataFrame, int nombreColonne) : Supprime une ligne d'une colonne du DataFrame.
    void add_DataFrameColumn(COLUMN** DataFrame, int *nombreColonne) : Ajoute une nouvelle colonne au DataFrame.
    void del_DataFrameColumn(COLUMN** DataFrame, int *nombreColonne) : Supprime une colonne du DataFrame.
    void rename_Column(COLUMN** DataFrame, int *nombreColonne) : Renomme une colonne du DataFrame.
    int Research_Value(COLUMN** DataFrame, int nombreColonne, int x) : Recherche une valeur dans le DataFrame.
    void ReplaceValue(COLUMN** DataFrame, int nombreColonne) : Remplace une valeur dans le DataFrame.
    void printName(COLUMN** DataFrame, int nombreColonne) : Affiche les titres des colonnes du DataFrame.


2.4 : Analyses & Statistiques
    int numberLines_DataFrame(COLUMN** DataFrame, int nombreColonne) : Retourne le nombre de lignes dans le DataFrame.
    int numberColumns_DataFrame(COLUMN** DataFrame, int nombreColonne) : Retourne le nombre de colonnes dans le DataFrame.
    int numberValues_Equal_DataFrame(COLUMN** DataFrame, int x, int nombreColonne) : Retourne le nombre de valeurs égales à une valeur donnée dans le DataFrame.
    int numberValues_Sup_DataFrame(COLUMN** DataFrame, int x, int nombreColonne) : Retourne le nombre de valeurs supérieures à une valeur donnée dans le DataFrame.
    int numberValues_Inf_DataFrame(COLUMN** DataFrame, int x, int nombreColonne) : Retourne le nombre de valeurs inférieures à une valeur donnée dans le DataFrame.