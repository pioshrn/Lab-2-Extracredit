#ifndef EXTRACREDIT1_FUNCTIONS_H
#define EXTRACREDIT1_FUNCTIONS_H

extern void read_distribution(double arr[]);

extern void compute_normalized_frequency(double histogram[], const char str[]);

extern int ChiSquared_distance(const double histogram1[], const double histogram2[]);

extern void permutation(char str[], int permutation_degree);

extern int Break_Caesars_Cypher(char message[], double character_distribution[]);

#endif //EXTRACREDIT1_FUNCTIONS_H