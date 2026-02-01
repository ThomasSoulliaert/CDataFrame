#include "fonctions.h"

// Partie I : Colonne
// Fonction qui créé dynamiquement une colonne vide à partir d’un titre.
COLUMN *create_column(char* titre)
// Retourne : Un pointeur vers une structure COLUMN.
// Paramètre : Un pointeur char* titre qui est une chaîne de caractères représentant le titre de la colonne.
{
    COLUMN *colonne = (COLUMN*)malloc(sizeof(COLUMN)); // Alloue dynamiquement de la mémoire pour une nouvelle structure COLUMN et retourne un pointeur vers cette mémoire allouée.
    colonne->TP = 0;
    colonne->TL = 0;
    colonne->Data = NULL;
    colonne->Title = (char*) malloc((strlen(titre) + 1) * sizeof(char));
    strcpy(colonne->Title,titre); // Copie du contenu de la chaîne de caractères titre dans le champ Title de la structure COLUMN pointée par col.
    return colonne;
}

// Fonction qui insert une valeur dans la colonne sélectionnée.
int insert_value(COLUMN *colonne, int valeur)
// Retourne : Un entier indiquant si l'insertion a été réussie (1 pour succès, 0 pour échec).
// Paramètres : COLUMN *colonne : Un pointeur vers une structure COLUMN dans laquelle la valeur sera insérée.
//              int valeur : La valeur entière à insérer dans la colonne.
{
    if (colonne->TP == 0)
    {
        colonne->Data = (int*)malloc(REALOC_SIZE * sizeof(int));
        colonne->Data[colonne->TL] = valeur;
        colonne->TL++;
        colonne->TP = REALOC_SIZE;
        return 1;
    }
    else if (colonne->TL == colonne->TP) // Si Taille logique = Taille physique : REALOC pour augmenter l'espace.
    {
        colonne->Data = (int*)realloc(colonne->Data, (colonne->TP + REALOC_SIZE) * sizeof (int));
        colonne->Data[colonne->TL] = valeur;
        colonne->TL++;
        colonne->TP += REALOC_SIZE;
        return 1;
    }
    else
    {
        colonne->Data[colonne->TL] = valeur;
        colonne->TL++;
        return 1;
    }
    return 0;
}

// Fonction qui prend en paramètre une colonne et qui permet de libérer la mémoire qui a été allouée à la colonne et à son tableau de données.
void delete_column(COLUMN **colonne)
{
    free((*colonne)->Data);
    free((*colonne)->Title);
    free((*colonne));
    *colonne = NULL;
}

// Fonction qui affiche une colonne en paramètres.
void print_col(COLUMN *colonne)
{
    for(int i = 0; i < colonne->TL; i++)
    {
        printf("[%d] %d\n", i, colonne->Data[i]);
    }
}

// Fonction qui renvoie le nombre d’occurrences d’une valeur X.
int occurrence(COLUMN *colonne, int x)
{
    int occurrence = 0;
    for (int i = 0; i < colonne->TL; i++)
    {
        if (colonne->Data[i] == x)
            occurrence++;
    }
    return occurrence;
}

// Fonction qui renvoie la valeur présente à la position X.
int position(COLUMN *colonne, int x)
{
    return colonne->Data[x];
}

// Fonction qui renvoie le nombre de valeurs supérieures à X.
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

// Fonction qui renvoie le nombre de valeurs inférieures à X.
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

//Fonction qui renvoie le nombre de valeurs égales à X.
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


// Partie II : DataFrame
// Partie 2.1 : Alimentation
// Fonction qui gère dynamiquement le nombre de colonnes que nous souhaitons manipuler dans le programme.
COLUMN** creat_DATAFRAME(int taille)
{
    COLUMN** DataFrame = malloc(sizeof(COLUMN) * taille);
    return DataFrame;
}

// Fonction qui demande à l'utilisateur du programme de remplir le DataFrame.
void fill_DataFrame(COLUMN** DataFrame, int nombreColonne)
{
    char titre[100];
    int taille, valeur;
    // Création du nombre de colonnes à partir de nombreColonne.
    for (int i = 0; i < nombreColonne; i++)
    {
        printf("Entrer le titre de la colonne numero %d\n", i);
        scanf("%s", titre);
        DataFrame[i] = create_column(titre);
        // Remplissage de chaque colonne avec le nombre de valeurs souhaitées.
        printf("Combien de valeurs souhaitez-vous inserer dans cette colonne ?\n");
        scanf("%d", &taille);
        for (int j = 0; j < taille; j++)
        {
            printf("Entrez la valeur a l'indice %d\n", j);
            scanf("%d", &valeur);
            insert_value(DataFrame[i], valeur);
        }
    }
}


// Partie 2.2 : Affichage
// Fonction qui affiche l'ensemble du DataFrame.
void print_DataFrame(COLUMN** DataFrame, int nombreColonne)
{
    for (int i = 0; i < nombreColonne; i++) // Pour chaque colonne du DataFrame...
    {
        printf("Colonne numero %d : %s\n", i, DataFrame[i]->Title);
        print_col(DataFrame[i]); // ...on affiche chaque ligne de chaque colonne.
    }
}

// Fonction qui affiche l'ensemble des lignes du DataFrame jusqu'à une certaine limite.
void print_DataFrameLimitLine(COLUMN** DataFrame, int nombreColonne, int LigneLimite)
{
    for (int i = 0; i < nombreColonne; i++) // Pour chaque colonne du DataFrame...
    {
        printf("Colonne numero %d : %s\n", i, DataFrame[i]->Title);
        for (int j = 0; j < LigneLimite; j++) // ...on réalise une boucle où on va afficher l'ensemble des lignes, exceptées celles situées après la limite fixée par l'utilisateur.
            if (j < DataFrame[i]->TL) // Vérifie si l'index de la ligne est inférieur à la taille logique de la colonne.
                printf("[%d] %d\n", j, DataFrame[i]->Data[j]);
            else // Si l'index dépasse la taille logique, ne rien afficher.
                break; // Sortir de la boucle si on a atteint la fin des données valides pour cette colonne.
    }
}

// Fonction qui affiche l'ensemble des colonnes du DataFrame jusqu'à une certaine limite.
void print_DataFrameLimitColumn(COLUMN** DataFrame, int nombreColonne, int ColonneLimite)
{
    if (nombreColonne > ColonneLimite)
    {
        print_DataFrame(DataFrame, ColonneLimite);
    }
    else
    {
        print_DataFrame(DataFrame, nombreColonne);
    }
}


// Partie 2.3 : Opérations usuelles
// Fonction qui rajoute une ligne dans une colonne.
void fill_DataFrameLine(COLUMN** DataFrame, int nombreColonne)
{
    int colonne, i = 0, valeur;
    printf("Dans quelle colonne souhaitez-vous rajouter une ligne ?\n");
    scanf("%d", &colonne);
    if (colonne <= nombreColonne)
    {
        printf("Quelle valeur souhaitez-vous rajouter ?\n");
        scanf("%d", &valeur);
        do // Recherche du premier indice où nous pourrons insérer la valeur choisie par l'utilisateur.
        {
            i++;
        }
        while ((i < DataFrame[colonne]->TL) && (DataFrame[colonne]->Data[i] != 0)); // Si le tableau est rempli au maximum, on évite de réaliser une boucle infinie.
        insert_value(DataFrame[colonne], valeur); // Insertion de la valeur dans la colonne souhaitée.
    }
}

// Fonction qui supprime une ligne dans une colonne.
void del_DataFrameLine(COLUMN** DataFrame, int nombreColonne)
{
    int colonne, ligne;
    printf("Quelle ligne de quelle colonne souhaitez-vous supprimer ?\nColonne =");
    scanf(" %d", &colonne);
    printf("Ligne =");
    scanf(" %d",&ligne);
    if ((colonne < nombreColonne) && (DataFrame[colonne]->Data[ligne] != 0))
    {
        for (int j = ligne; j < DataFrame[colonne]->TL - 1; j++)
        {
            DataFrame[colonne]->Data[j] = DataFrame[colonne]->Data[j+1];
        }
        DataFrame[colonne]->TL--; // Réajustement de la Taille Logique après la suppression de la ligne.
        printf("La ligne %d de la colonne %d a ete supprimee avec succes.\n", ligne, colonne);
    }
    else
        printf("Erreur, les valeurs choisies ne permettent pas de realiser l'operation souhaitee.\n");
}

// Fonction qui rajoute une colonne dans le DataFrame.
void add_DataFrameColumn(COLUMN** DataFrame, int *nombreColonne) // Passage par un pointeur pour *nbcol pour pouvoir enregistrer le changement
{
    char *titre[100];
    int taille, valeur;
    printf("Entrez le nom de votre nouvelle colonne : \n");
    scanf("%s", titre);
    DataFrame[*nombreColonne] = create_column(titre); // Création d'une nouvelle colonne.
    printf("Combien de valeurs souhaitez-vous ajouter dans cette nouvelle colonne ?\n");
    scanf("%d", &taille);
    for (int j = 0; j < taille; j++)
    {
        printf("Entrez la valeur a l'indice %d\n", j);
        scanf("%d", &valeur);
        insert_value(DataFrame[*nombreColonne], valeur);
    }
    (*nombreColonne)++; // Mise à jour du nombre de colonnes.
}

// Fonction qui supprime une colonne du DataFrame.
void del_DataFrameColumn(COLUMN** DataFrame,int *nombreColonne)
{
    int colonne;
    printf("Quelle colonne voulez-vous supprimer ?\n");
    scanf("%d", &colonne);
    if (colonne < *nombreColonne)
    {
        // Suppression de la colonne à l'indice souhaité.
        delete_column(&DataFrame[colonne]);

        // Déplacement des indices vers la gauche.
        for (int i = colonne; i < *nombreColonne - 1; i++)
        {
            DataFrame[i] = DataFrame[i + 1];
        }

        // Mise à jour du dernier élément à NULL après déplacement.
        DataFrame[*nombreColonne - 1] = NULL;

        // Mise à jour du nombre de colonnes.
        (*nombreColonne)--;
    }

    else
        printf("Erreur, les valeurs choisies ne permettent pas de realiser l'operation souhaitee.\n");
}

// Fonction qui renomme une colonne du DataFrame.
void rename_Column(COLUMN** DataFrame, int *nombreColonne)
{
    char titre[100];
    int colonne;
    printf("Quelle colonne souhaitez-vous renommer ?\n");
    scanf("%d",&colonne);
    if (colonne < *nombreColonne)
    {
        printf("Ecrivez le nouveau titre pour la colonne choisie :\n");
        scanf("%s",titre);
        strcpy(DataFrame[colonne]->Title, titre); // Copie la nouvelle chaîne dans le champ Title.
    }
    else
        printf("Erreur, les valeurs choisies ne permettent pas de realiser l'operation souhaitee.\n");
}

// Fonction qui recherche une valeur dans le DataFrame.
int Research_Value(COLUMN** DataFrame, int nombreColonne, int x)
{
    int trouve = 0;
    for (int i = 0; i < nombreColonne; i++) // Pour chaque colonne...
    {
        for (int j = 0 ; j < DataFrame[i]->TL; j++) // ...puis pour chaque ligne...
        {
            if (DataFrame[i]->Data[j] == x) // ...on regarde si la valeur X est trouvée.
            {
                trouve = 1; // Utilisation d'un booléen pour savoir si la valeur est trouvée ou non.
                printf("La valeur %d a ete trouvee a cet endroit : col = %d Data[%d]=%d\n", x, i, j, DataFrame[i]->Data[j]);
            }
        }
    }
    if (trouve != 1)
        printf("La valeur %d n'a pas ete trouvee\n", x);
    return 0; // Valeur X non-trouvée : la fonction renvoie 0.
}

// Fonction qui remplace une valeur dans le DataFrame.
void ReplaceValue(COLUMN** DataFrame, int nombreColonne)
{
    int colonne, ligne, valeur;
    printf("Donnez l'emplacement de la valeur que vous souhaitez remplacer :\n");
    printf("Quelle est la colonne de cette valeur ?\n");
    scanf("%d",&colonne);
    printf("Quelle est la ligne de cette valeur ?\n");
    scanf("%d",&ligne);
    printf("Ecrivez la nouvelle valeur ?\n");
    scanf("%d",&valeur);
    if ((colonne < nombreColonne) && (ligne < DataFrame[colonne]->TL))
    {
        DataFrame[colonne]->Data[ligne] = valeur;
    }
    else
    {
        printf("Erreur, les valeurs choisies ne permettent pas de realiser l'operation souhaitee.\n");
    }
}

// Fonction qui affiche le titre des colonnes du DataFrame.
void printName(COLUMN** DataFrame, int nombreColonne)
{
    for (int i = 0; i < nombreColonne; i++)
    {
        printf("Le titre de la colonne numero %d est %s \n", i, DataFrame[i]->Title);
    }
}

// Partie 2.4 : Analyses & Statistiques
// Fonction qui renvoie le nombre de lignes.
int numberLines_DataFrame(COLUMN** DataFrame, int nombreColonne)
{
    int nombreLigne = 0;
    for (int i = 0; i < nombreColonne; i++) // On parcourt l'ensemble du Dataframe.
    {
        nombreLigne = nombreLigne + DataFrame[i]->TL;
    }
    printf("Nombre de lignes dans le DataFrame : %d\n", nombreLigne);
    return(nombreLigne);
}

// Fonction qui renvoie le nombre de colonnes.
int numberColumns_DataFrame(COLUMN** DataFrame, int nombreColonne)
{
    // int nbCol = sizeof(DataFrame) / sizeof(int);
    printf("Nombre de colonnes dans le DataFrame : %d\n", nombreColonne);
    return nombreColonne;
}

// Fonction qui renvoie le nombre de valeurs égales à X dans le DataFrame.
int numberValues_Equal_DataFrame(COLUMN** DataFrame, int x, int nombreColonne)
{
    int i, j, nombreValeur = 0;
    for (i = 0; i < nombreColonne; i++)
    {
        for (j = 0; j < DataFrame[i]->TL; j++)
        {
            if (DataFrame[i]->Data[j] == x)
                nombreValeur++; // Variable qui s'incrémente à chaque fois pour compter le nombre de valeurs égales à X.
        }
    }
    printf("Nombre de valeurs egales a %d dans le DataFrame : %d\n", x, nombreValeur);
    return(nombreValeur);
}

// Fonction qui renvoie le nombre de valeurs supérieures à X dans le DataFrame.
int numberValues_Sup_DataFrame(COLUMN** DataFrame, int x, int nombreColonne)
{
    int i, j, nombreValeur = 0;
    for (i = 0; i < nombreColonne; i++)
    {
        for (j = 0; j < DataFrame[i]->TL; j++)
        {
            if (DataFrame[i]->Data[j] > x)
                nombreValeur++; // Variable qui s'incrémente à chaques fois pour compter le nombre de valeurs supérieures à X.
        }
    }
    printf("Nombre de valeurs superieures a %d dans le DataFrame : %d\n", x, nombreValeur);
    return(nombreValeur);
}

// Fonction qui renvoie le nombre de valeurs inférieures à X dans le DataFrame.
int numberValues_Inf_DataFrame(COLUMN** DataFrame, int x, int nombreColonne)
{
    int i, j, nombreValeur = 0;
    for (i = 0; i < nombreColonne; i++)
    {
        for (j = 0; j < DataFrame[i]->TL; j++)
        {
            if (DataFrame[i]->Data[j] < x)
                nombreValeur++; // Variable qui s'incrémente à chaques fois pour compter le nombre de valeurs inférieures à X.
        }
    }
    printf("Nombre de valeurs inferieures a %d dans le DataFrame : %d\n", x, nombreValeur);
    return(nombreValeur);
}