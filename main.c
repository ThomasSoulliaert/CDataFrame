//
// Created by tsoul on 29/03/2024.
//

#include <stdio.h>
#include <stdlib.h>

#define REALOC_SIZE 256

int main()
{
    COLUMN *mycol = create_column("My column");

    COLUMN *mycol = create_column("My column");
    int val = 5;
    if (insert_value(mycol, val))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");


    return 0;
}