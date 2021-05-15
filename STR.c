/**
Author: Bruno Vasconcellos
USF ID: U93067202
Description: This program will make use of I/O files take an user external file as input. Then it will calculate and return the number of
DNA Short Tandem Repeats(a sequence prompted by the user) in a one line string repetitions from the user's selected file. In case the
file presents any error, the program will display an error message and shut it down returning 1.
**/

#include<stdio.h>
#include<string.h>
#define N 100
#define DNA_LEN 20000
#define STR_LEN 5

int count_repeats(char *sequence, char*STR);

int main(){

    char file_name[N], STR[STR_LEN], DNA_sequence[DNA_LEN];
    int num_repetitions;
    FILE *pFile;

    //user file prompt
    printf("Enter the file name for the DNA sequence: ");
    scanf("%s", file_name);

    //user STR
    printf("\nEnter STR: ");
    scanf("%s", STR);

    pFile = fopen(file_name, "r");

    //error handling
    if(pFile == NULL){
        printf("Error opening the file.");
        return 1;
    }

    //saves the content from the file into DNA_sequence string
    fscanf(pFile, "%[^\n]", DNA_sequence);

    //call the function
    num_repetitions = count_repeats(DNA_sequence, STR);

    //output
    printf("\n%s is repeated %d times.", STR, num_repetitions);

    //close the file
    fclose(pFile);

    return 0;

}//end of main

/**
The count_repeats function will use the extracted DNA string from the file and the user entered STR.
Then it will make use of a while loop and a conditional that makes use of strstr from the string library in order to
find substrings(STR) within the provided DNA sequence.
**/

int count_repeats(char *sequence, char*STR){

    int count = 0;

    while(*sequence != '\0'){
        if(sequence == strstr(sequence, STR)){
            count++;
            sequence+=strlen(STR - 1); //skips the amount of characters -1 (which will be added after the conditional) from the matched STR to avoid any possible repetition
        }
        sequence++;
    }

    return count;
}//end of function

