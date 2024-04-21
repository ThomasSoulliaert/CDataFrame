//
// Created by SOULLIAERT & YE on 29/03/2024.
//


#include <stdio.h>
#include "fonctions.h"


int main()
{
    COLUMN *mycol = create_column("My column");
    COLUMN** DataFrame;
    int nombreCol = 1, valeur = 3;
    DataFrame = creat_DATAFRAME(3);
    fill_DataFrame(DataFrame, nombreCol);
    Nbr_val_egale_DataFrame(DataFrame, valeur, nombreCol);
    return 0;
}