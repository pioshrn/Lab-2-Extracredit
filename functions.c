#include <stdio.h>
#include <string.h>

#include "functions.h"

void read_distribution(double arr[]){
    FILE *fp;
    fp = fopen("D:\\Sem2\\OOP\\Labs\\ExtraCredit1\\distribution.txt", "r");

    if (fp == NULL){
        printf("Could not open file.\n");
        return;
    }

    int index = 0;
    while (fscanf(fp, "%lf", &arr[index]) != EOF){
        index++;
    }

    fclose(fp);
}

void compute_normalized_frequency(double histogram[], const char str[]){
    for (int index = 0; index <= 25; ++index)
        histogram[index] = 0;
    for (int index = 0; str[index]; ++index){
        int ch_code = (int)(str[index]);

        if (ch_code >= 97 && ch_code <= 122)
            histogram[ch_code - 97]++;

        if (ch_code >= 65 && ch_code <= 90)
            histogram[ch_code - 65]++;
    }
}

int ChiSquared_distance(const double histogram1[], const double histogram2[]){
    int ChiSquared_sum = 0;

    for (int index = 0; index <= 25; ++index){
        double character_discrepancy = histogram1[index] - histogram2[index];
        character_discrepancy = character_discrepancy * character_discrepancy;

        if (histogram2[index])
            character_discrepancy /= histogram2[index];

        ChiSquared_sum += (int)character_discrepancy;
    }

    return ChiSquared_sum;
}

void permutation(char str[], int permutation_degree){
    for (int index = 0; str[index] != '\0'; ++index){
        int ch_code = (int)(str[index]);

        if (ch_code >= 97 && ch_code <= 122)
            str[index] = (str[index] - permutation_degree - 71) % 26 + 97;

        if (ch_code >= 65 && ch_code <= 90)
            str[index] = (str[index] - permutation_degree - 39) % 26 + 65;
    }
}

int Break_Caesars_Cypher(char message[], double character_distribution[]){
    double histogram[26] = { 0 };
    compute_normalized_frequency(histogram, message);

    int ChiSquared_key = ChiSquared_distance(histogram, character_distribution);
    int key_degree = 0;

    for (int degree = 1; degree <= 25; ++degree){
        char copy[1024];
        strcpy(copy, message);

        permutation(copy, degree);
        compute_normalized_frequency(histogram, copy);
        int ChiSquared_trial = ChiSquared_distance(histogram, character_distribution);

        if (ChiSquared_trial < ChiSquared_key){
            ChiSquared_key = ChiSquared_trial;
            key_degree = degree;
        }
    }

    return key_degree;
}