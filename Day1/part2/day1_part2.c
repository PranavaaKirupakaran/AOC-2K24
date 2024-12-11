#include "stdio.h"
#include "stdlib.h"

char file_name[] = "C:\\Users\\prana\\OneDrive\\Documents\\GitHub\\AOC-2K24\\Day1\\part1\\puzzleInput.txt";

int main(){

    // Reading puzzle input and storing in arrays

    FILE *ptr = fopen(file_name, "r");

    if (ptr == NULL){
        printf("File Not Found \n");
        return 0;
    }

    int distance_left_list[1000];
    int distance_left;

    int distance_right_list[1000];
    int distance_right;

    int counter = 0;

    printf("Storing puzzle input in array.. \n");

    while(fscanf(ptr, "%d %d", &distance_left, &distance_right) == 2){
        //printf("%d %d \n",distance_left, distance_right);

        //printf("adding left distance to array... \n");
        *(distance_left_list + counter) = distance_left;

        //printf("adding right distance to array... \n");
        *(distance_right_list + counter) = distance_right;

        counter++;
    }

    printf("Building repetition count array.. \n");

    int repetition_count_list[1000];

    for(int i = 0; i < counter; i++){
        int repetition_count = 0;
        for(int j = 0; j < counter; j++){
            if(*(distance_left_list + i) == *(distance_right_list + j)){
                repetition_count++;
            }
        }
        printf("Found %d repetition of %d \n", repetition_count, distance_left_list[i]);
        *(repetition_count_list + i) = repetition_count;
    }

    printf("Computing similarity score... \n");

    int similarity_score = 0;

    for(int i = 0; i < counter; i++){
        similarity_score += *(distance_left_list + i) * *(repetition_count_list + i);
    }

    printf("Similarity score: %d \n", similarity_score);



}