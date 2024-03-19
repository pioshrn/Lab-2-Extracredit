#include <stdio.h>

#include "functions.h"

void print_ui(){
    printf("In order to decipher a message you must permute it by the Caesar's Cypher key.\n");
    printf("Choose an option: \n");
    printf("[1] Enter a message\n");
    printf("[2] Compute a histogram of your message\n");
    printf("[3] Permute the message by a degree\n");
    printf("[4] Get the key for Caesar's Cypher\n");
    printf("[0] Exit\n");
    printf("Enter Option: ");
}


int main(){
    int option;
    char message[1024];
    double distribution[26];
    double histogram[26];
    int degree, key;
    read_distribution(distribution);
    do{
        print_ui();
        scanf("%d", &option);

        switch (option){
            case 1:
                printf("\nEnter message: ");
                getchar();
                fgets(message, 1000, stdin);
                break;

            case 2:
                compute_normalized_frequency(histogram, message);
                printf("The histogram of your message is: \n");

                for (int index = 0; index <= 25; ++index)
                    printf("%c : %.1f\n", (char)(index + 97), histogram[index]);
                break;

            case 3:
                printf("Enter the degree of permutation: ");
                scanf("%d", &degree);
                permutation(message, degree);
                printf("The new message is: %s\n", message);
                break;

            case 4:
                key = Break_Caesars_Cypher(message, distribution);
                printf("Your key is: %d\n", key);
                break;

            case 0:
                break;

            default:
                printf("Invalid option.\n");
        }
    } while (option != 0);

    //"Uf ime ftq nqef ar fuyqe, uf ime ftq iadef ar fuyqe, uf ime ftq msq ar iuepay, uf ime ftq msq ar raaxuetzqee, uf ime ftq qbaot ar nqxuqr,""uf ime ftq qbaot ar uzodqpgxufk, uf ime ftq eqmeaz ar xustf, uf ime ftq eqmeaz ar pmdwzqee, uf ime ftq ebduzs ar tabq, uf ime ftq iuzfqd ar pqebmud.";
    return 0;
}