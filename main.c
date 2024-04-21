//
// Created by SOULLIAERT & YE on 29/03/2024.
//


#include <stdio.h>
#include "fonctions.h"


int main()
{
    /*
    char str[5];
    COLUMN *mycol = create_column(INT, "My column");
    int a = 52, b = 44, c = 15, d = 18;
    insert_value(mycol, &a);
    insert_value(mycol, &b);
    insert_value(mycol, &c);
    insert_value(mycol, &d);
    convert_value(mycol, 2, str, N);
    printf("%s \n", str);
    delete_column(&mycol);
     */

    COLUMN *mycol = create_column("My column");
    COLUMN** DataFrame;
    int nombreCol = 1, valeur = 3;
    DataFrame = creat_DATAFRAME(3);
    fill_DataFrame(DataFrame, nombreCol);
    Nbr_val_egale_DataFrame(DataFrame, valeur, nombreCol);
    return 0;
}