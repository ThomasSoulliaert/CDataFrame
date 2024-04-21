//
// Created by SOULLIAERT & YE on 29/03/2024.
//


#include "fonctions.h"


/// Partie : Fonctions de base

/// Fonction qui créé dynamiquement une colonne vide à partir d’un titre.
COLUMN *create_column(char* title)
{
    COLUMN *col = (COLUMN*) malloc(sizeof(COLUMN));
    col->TP = 0;
    col->TL = 0;
    col->Data = NULL;
    col->Title = (char*) malloc((strlen(title) + 1) * sizeof(char));
    strcpy(col->Title,title); /// Copie du contenu de la chaîne de caractères title dans le champ Title de la structure COLUMN pointée par col.
    return col;
}

/// Fonction qui insert une valeur dans la colonne sélectionnée.
int insert_value(COLUMN *colonne, int value)
{
    if (colonne->TP == 0)
    {
        colonne->Data = (int*)malloc(REALOC_SIZE * sizeof(int));
        colonne->Data[colonne->TL] = value;
        colonne->TL++;
        colonne->TP = REALOC_SIZE;
        return 1;
    }
    else if(colonne->TL == colonne->TP) /// Si Taille logique = Taille physique : REALOC pour augmenter l'espace.
    {
        colonne->Data= (int*)realloc(colonne->Data, (colonne->TP + REALOC_SIZE) * sizeof (int));
        colonne->Data[colonne->TL] = value;
        colonne->TL++;
        colonne->TP += REALOC_SIZE;
        return 1;
    }
    else
    {
        colonne->Data[colonne->TL] = value;
        colonne->TL++;
        return 1;
    }
    return 0;
}

/// Fonction qui prend en paramètre une colonne et qui permet de libérer la mémoire qui a été allouée à la colonne et à son tableau de données.
void delete_column(COLUMN **colonne)
{
    free((*colonne)->Data);
    free((*colonne)->Title);
    free((*colonne));
    *colonne = NULL;
}

/// Fonction qui affiche une colonne en paramètres.
void print_col(COLUMN *colonne)
{
    for (int i = 0; i < colonne->TL; i++)
    {
        printf("[%d] %d\n", i, colonne->Data[i]);
    }
}

/// Fonction qui renvoie le nombre d’occurrences d’une valeur X.
int occurrence(COLUMN *colonne, int x)
{
    int occurence = 0;
    for (int i = 0; i < colonne->TL; i++)
    {
        if (colonne->Data[i] == x)
            occurence++;
    }
    return occurence;
}

/// Fonction qui renvoie la valeur présente à la position X.
int position(COLUMN *colonne, int x)
{
    return colonne->Data[x];
}

/// Fonction qui renvoie le nombre de valeurs supérieures à X.
int superieur(COLUMN *colonne, int x)
{
    int total = 0;
    for (int i = 0; i < colonne->TL; i++)
    {
        if (colonne->Data[i] > x)
            total++;
    }
    return total;
}

/// Fonction qui renvoie le nombre de valeurs inférieures à X.
int inferieur(COLUMN *colonne, int x)
{
    int total = 0;
    for (int i = 0; i < colonne->TL; i++)
    {
        if (colonne->Data[i] < x)
            total++;
    }
    return total;
}

///Fonction qui renvoie le nombre de valeurs égales à X.
int egale(COLUMN *colonne, int x)
{
    int total = 0;
    for (int i = 0; i < colonne->TL; i++)
    {
        if (colonne->Data[i] == x)
            total++;
    }
    return total;
}

/// Partie : Alimentation

/// Avec COLUMN**, nous créons un pointeur qui peut contenir l'adresse du premier élément d'un tableau de pointeurs vers des structures COLUMN.
/// Fonction qui gère dynamiquement le nombre de colonnes que nous souhaitons manipuler dans le programme.
COLUMN** creat_DATAFRAME(int taille)
{
    COLUMN** DataFrame = malloc(sizeof(COLUMN) * taille);
    return DataFrame;
}

/// Fonction qui demande à l'utilisateur du programme de remplir le DataFrame.
void fill_DataFrame(COLUMN** DataFrame, int nombreColonne)
{
    char titre[100];
    int taille, valeur;
    /// Création du nombre de colonnes à partir de nombreCol.
    for (int i = 0; i < nombreColonne; i++)
    {
        printf("Entrer le titre de la colone numéro %d\n", i);
        scanf("%s", titre);
        DataFrame[i] = create_column(titre);
        /// Remplissage de chaque colonne avec le nombre de valeurs souhaitées.
        printf("Combien de valeurs souhaitez-vous insérer dans cette colonne ?\n");
        scanf("%d", &taille);
        for (int j = 0; j < taille; j++) {
            printf("Entrez la %d valeur\n", j);
            scanf("%d", &valeur);
            insert_value(DataFrame[i], valeur);
        }
    }
}

/// Partie : Affichage

/// Fonction qui affiche l'ensemble du DataFrame.
void print_DataFrame(COLUMN** DataFrame, int nombreColonne)
{
    for(int i = 0; i < nombreColonne; i++) /// Pour chaque colonne du DataFrame...
    {
        printf("%de colonne :\n", i + 1);
        print_col(DataFrame[i]); /// ...on affiche chaque ligne de chaque colonne.
    }
}

/// Fonction qui affiche l'ensemble du DataFrame jusqu'à une certaine limite.
void print_DataFrameLimitLine(COLUMN** DataFrame, int nombreColonne, int LigneLimite)
{
    for(int i = 0; i < nombreColonne; i++) /// Pour chaque colonne du DataFrame...
    {
        printf("%de colonne :\n", i + 1);
        for (int j = 0; j < LigneLimite; j++) /// ...on réalise une boucle où on va afficher l'ensemble des lignes, exceptées celles situées après la limite fixée par l'utilisateur.
            printf("[%d]:%d\n", j, DataFrame[i]->Data[j]);
    }
}

/// Fonction qui affiche l'ensemble du DataFrame jusqu'à une certaine limite.
void print_DataFrameLimitColumn(COLUMN** DataFrame, int nombreColonne, int ColonneLimite)
{
    for(int i = 0; (i < nombreColonne) && (i < ColonneLimite); i++) /// Pour chaque colonne du DataFrame (si colonne < ColonneLimite)...
    {
        printf("%de colonne :\n", i + 1);
        print_col(DataFrame[i]); /// ...on affiche chaque ligne de chaque colonne.
    }
}

/// Partie : Opérations

/// Fonction qui rajoute une ligne dans une colonne.
void fill_DataFrameLine(COLUMN** DataFrame, int nombreColonne)
{
    int col, i = 0, value;
    printf("Dans quelle colonne souhaitez-vous rajouter une ligne ?\n");
    scanf("%d", &col);
    if (col <= nombreColonne)
    {
        printf("Quelle valeur souhaitez-vous rajouter ?\n");
        scanf("%d", &value);
        do /// Recherche du premier indice où nous pourrons insérer la valeur choisie par l'utilisateur.
        {
            i++;
        }
        while ((i < DataFrame[col]->TL) && (DataFrame[col]->Data[i] != 0)); /// Si le tableau est rempli au maximum, on évite de réaliser une boucle infinie.
        insert_value(DataFrame[col], value); /// Insertion de la valeur dans la colonne souhaitée.
    }
}

/// Fonction qui supprime une ligne dans une colonne.
void del_DataFrameLine(COLUMN** DataFrame, int nombreColonne)
{
    int colonne, ligne;
    printf("Quelle ligne de quelle colonne souahitez-vous supprimer ?\nColonne = ");
    scanf("%d\n", &colonne);
    printf("Ligne = ");
    scanf("%d",&ligne);
    if ((colonne < nombreColonne) && (DataFrame[colonne]->Data[ligne]!=0))
    {
        for (int j = ligne; j < DataFrame[colonne]->TL - 1; j++)
        {
            DataFrame[colonne]->Data[j] = DataFrame[colonne]->Data[j+1];
        }
        DataFrame[colonne]->TL--; /// Réajustement de la Taille Logique après la suppression de la ligne.
        printf("La ligne %d de la colonne %d a été supprimée avec succès.\n", ligne, colonne);
    }
    else
        printf("Erreur, les valeurs choisies ne permettent pas de réaliser l'opération souhaitée.\n");
}

/// Fonction qui rajoute une colonne dans le DataFrame.
void add_DataFrameColumn(COLUMN** DataFrame, int *nombreColonne) /// Passage par un pointeur pour *nbcol pour pouvoir enregistrer le changement
{
    char* titre[100];
    int taille,valeur;
    printf("Quel nom voulez-vous donner à votre nouvelle colonne ?");
    scanf("%s", titre);
    DataFrame[*nombreColonne] = create_column(titre);///on crée la nouvelle colonne
    printf("Combien de Valeur dans cette colonne ? ");
    scanf("%d", &taille);
    for (int j = 0; j < taille; j++)
    {
        printf("Entrez la %d valeur\n", j);
        scanf("%d", &valeur);
        insert_value(DataFrame[*nombreColonne], valeur);
    }
    (*nombreColonne)++;///on met à jour le nombre de colonne
}

void del_DataFrameColumn(COLUMN** DataFrame,int *nombreColonne)
{
    int col;
    printf("Quelle colonne voulez-vous supprimer ?\n ");
    scanf(" %d",&col);
    if (col< *nombreColonne)
    {
        delete_column(&DataFrame[col]);///supprimer la colonne à l'index voulut
        for (int i=col ;i+1 < *nombreColonne; i++)
            DataFrame[i+1]=DataFrame[i];///on déplace les indices vers la gauche
        (*nombreColonne)--;///on met à jour le nombre de colonnes
    }

    else
        printf("Erreur avec les valeurs choisies \n");
}

/// Fonction qui renomme une colonne.
void rename_Column(COLUMN** DataFrame, int *nombreColonne)
{
    char titre[100];
    int colonne;
    printf("Quel colonne souhaitez vous renommer ? \n");
    scanf("%d",&colonne);
    if (colonne < *nombreColonne)
    {
        printf("Rentrez le nouveau titre \n");
        scanf("%s",titre);
        strcpy(DataFrame[colonne]->Title, titre); // Copie la nouvelle chaîne dans le champ Title
    }
}

int Research_Value(COLUMN** DataFrame,int nombreColonne,int x)
{
    for (int i=0;i<nombreColonne;i++)
    {
        for (int j=0 ; j<DataFrame[i]->TL; j++)///regarde toutes les lignes
        {
            if (DataFrame[i]->Data[j]==x)
                return 1;///la valeure x a été trouvé
        }
    }
    return 0; ///la valeure x n'a pas été trouvé
}

void ReplaceValue(COLUMN** DataFrame,int nombreColonne)
{
    int col,ligne,value;
    printf("Quelle colonne ?\n");
    scanf("%d",&col);
    printf("Quelle ligne ?\n");
    scanf("%d",&ligne);
    printf("Nouvelle valeur ?\n");
    scanf("%d",&value);
    if (col<nombreColonne && ligne<DataFrame[col]->TL) {
        DataFrame[col]->Data[ligne] = value;
    }
    else {
        printf("Erreur avec les valeurs choisies !\n");
    }
}

void printName(COLUMN** DataFrame,int nombreColonne)
{
    for (int i=0;i<nombreColonne;i++){
        printf("colonne numéro %d = %s \n",i,DataFrame[i]->Title);
    }
}

/// Partie : Analyses & Statistiques

/// Fonction
int Nbr_lignes_DataFrame(COLUMN** DataFrame, int nombreColonne)
{
    int nombre_lig=0;
    for (int i=0;i<nombreColonne;i++) /// On parcourt tout le Dataframe en prenant en compte le nb de col
    {
        nombre_lig=nombre_lig + DataFrame[i]->TL;
    }
    return(nombre_lig);
}

int Nbr_colonnes_DataFrame(COLUMN** DataFrame)
{
    return(sizeof(DataFrame)/sizeof(int)); /// On récupère la taille de cette manirère, sizeof donne la taille de données mémoire, mais si on la divise par la taille de la donnée (ici un int en l'occurence, on a la taille du tableau
}


int Nbr_val_egale_DataFrame(COLUMN** DataFrame, int valeur, int nombreColonne)
{
    int i,j,nombre_val=0;
    for(i=0;i<nombreColonne;i++){
        for(j=0;j<DataFrame[i]->TL;j++){
            if(DataFrame[i]->Data[j] == valeur )
                nombre_val++; /// Variable qui s'incrémente à chaques fois pour compter le nb de valeures égales à x
        }
    }
    return(nombre_val);
}

int Nbr_val_sup_DataFrame(COLUMN** DataFrame, int valeur, int nombreColonne)
{
    int i,j,nombre_val=0;
    for(i=0;i<nombreColonne;i++){
        for(j=0;j<DataFrame[i]->TL;j++){
            if(DataFrame[i]->Data[j] > valeur )
                nombre_val++; /// Variable qui s'incrémente à chaques fois pour compter le nb de valeures égales à x
        }
    }
    return(nombre_val);
}

int Nbr_val_inf_DataFrame(COLUMN** DataFrame, int valeur, int nombreColonne)
{
    int i,j,nombre_val=0;
    for(i=0;i<nombreColonne;i++)
    {
        for(j=0;j<DataFrame[i]->TL;j++)
        {
            if(DataFrame[i]->Data[j] < valeur)
                nombre_val++; /// Variable qui s'incrémente à chaques fois pour compter le nb de valeures égales à x
        }
    }
    return(nombre_val);
}