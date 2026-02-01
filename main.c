#include <stdio.h>
#include "fonctions.h"


int main()
{
    // --- Colonne ---
    printf("Premiere partie du test : Colonne\n\n");
    COLUMN *mycol = create_column("Colonne de Lucas et Thomas\n");

    int a = 52, b = 44, c = 15, d = 18, e = 52, f = 25, g = 1; // Valeurs utilisées pour les tests
    insert_value(mycol, a);
    insert_value(mycol, b);
    insert_value(mycol, c);
    insert_value(mycol, d);
    insert_value(mycol, e);
    insert_value(mycol, f);
    print_col(mycol);

    int occ, pos, sup, inf, ega;
    occ = occurrence(mycol, a);
    printf("Occurrence de la valeur %d dans la colonne : %d\n", a, occ);
    pos = position(mycol, g);
    printf("La valeur a la position %d est : %d\n", g, pos);
    sup = superieur(mycol, f);
    printf("Nombre de valeurs superieures a %d : %d\n", f, sup);
    inf = inferieur(mycol, f);
    printf("Nombre de valeurs inferieures a %d : %d\n", f, inf);
    ega = egale(mycol, a);
    printf("Nombre de valeurs egales a %d : %d\n", a, ega);
    // Remarque : occurrence et egale sont exactement les mêmes fonctions

    // Supprimer la colonne et libérer la mémoire
    delete_column(&mycol);
    // Vérifier si la colonne a été supprimée
    if (mycol == NULL)
        printf("La colonne a ete supprimee avec succes.\n");
    else
        printf("La colonne n'a pas ete supprimee.\n");


    // --- DataFrame ---
    printf("\n\nDeuxieme partie du test : DataFrame\n\n");
    COLUMN** DataFrame;
    int nombreCol;

    printf("Entrez le nombre de colonnes qui vous souhaitez creer dans le DataFrame : \n");
    scanf("%d", &nombreCol);

    int taille_DataFrame = nombreCol + 1;
    int x = 5, y = 3, z = 2; // Valeurs utilisées pour les tests

    DataFrame = creat_DATAFRAME(taille_DataFrame);
    fill_DataFrame(DataFrame, nombreCol);
    print_DataFrame(DataFrame, nombreCol);

    // Affiche l'ensemble des lignes du DataFrame jusqu'à une certaine limite.
    print_DataFrameLimitLine(DataFrame, nombreCol, 5);
    // Affiche l'ensemble des colonnes du DataFrame jusqu'à une certaine limite.
    print_DataFrameLimitColumn(DataFrame, nombreCol, 2);

    //Rajouter une ligne dans une colonne du DataFrame.
    fill_DataFrameLine(DataFrame, nombreCol);
    print_DataFrame(DataFrame, nombreCol);

    // Supprimer une ligne dans une colonne du DataFrame.
    del_DataFrameLine(DataFrame, nombreCol);
    print_DataFrame(DataFrame, nombreCol);

    // Rajouter une colonne du DataFrame.
    add_DataFrameColumn(DataFrame, &nombreCol);
    print_DataFrame(DataFrame, nombreCol);

    // Supprimer une colonne du DataFrame.
    del_DataFrameColumn(DataFrame, &nombreCol);
    print_DataFrame(DataFrame, nombreCol);

    // Renommer une colonne du DataFrame.
    rename_Column(DataFrame, &nombreCol);

    // Fonction qui affiche le titre des colonnes du DataFrame.
    printName(DataFrame, nombreCol);

    // Rechercher une valeur dans le DataFrame.
    Research_Value(DataFrame, nombreCol, x);

    // Remplacer une valeur dans le DataFrame.
    ReplaceValue(DataFrame, nombreCol);
    print_DataFrame(DataFrame, nombreCol);

    // Renvoie le nombre de lignes (nombre de cases créées pour y insérer les valeurs).
    numberLines_DataFrame(DataFrame, nombreCol);

    // Renvoie le nombre de colonnes.
    numberColumns_DataFrame(DataFrame, nombreCol);

    // Renvoie le nombre de valeurs égales à X dans le DataFrame.
    numberValues_Equal_DataFrame(DataFrame, x, nombreCol);

    // Fonction qui renvoie le nombre de valeurs supérieures à X dans le DataFrame.
    numberValues_Sup_DataFrame(DataFrame, y, nombreCol);

    // Renvoie le nombre de valeurs inférieures à X dans le DataFrame.
    numberValues_Inf_DataFrame(DataFrame, z, nombreCol);

    return 0;
}