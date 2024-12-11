#include "stdio.h"
#include "stdlib.h"

char file_name[] = "C:\\Users\\prana\\OneDrive\\Documents\\GitHub\\AOC-2K24\\Day1\\part1\\puzzleInput.txt";

void sort_ascending(int* array, int len);

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

    // Sorting puzzle inputs

    //printf("Printing elements in left distance array pre sort... \n");
    //for(int i = 0; i < counter; i++){
        //printf("%d \n", *(distance_left_list + i));
    //}

    sort_ascending(distance_left_list, counter);

    //printf("Printing elements in left distance array post sort... \n");
    //for(int i = 0; i < counter; i++){
        //printf("%d \n", *(distance_left_list + i));
    //}

    //printf("Printing elements in right distance array pre sort... \n");
    //for(int i = 0; i < counter; i++){
        //printf("%d \n", *(distance_right_list + i));
    //}

    sort_ascending(distance_right_list, counter);

    //printf("Printing elements in right distance array post sort... \n");
    //for(int i = 0; i < counter; i++){
        //printf("%d \n", *(distance_right_list + i));
    //}

    // Calculating total distance

    int total_distance = 0;

    printf("Computing total distance... \n");

    for(int i = 0; i < counter; i++){
        total_distance += abs(*(distance_left_list + i) - *(distance_right_list + i));
    }

    printf("Total distance is %d \n", total_distance);

}

void sort_ascending(int* array, int len){
    printf("sorting algorithm start... \n");
    int sort_flag = 1;

    do{
        sort_flag = 0;
        for(int i = 0; i < len - 1; i++){
            if(*(array + i) > *(array + i + 1)){
                int smaller = *(array + i + 1);
                int bigger = *(array + i);

                *(array + i + 1) = bigger;
                *(array + i) = smaller;

                sort_flag++;

                //printf("swapping... \n");

            }

        }

    }while(sort_flag > 0);

    printf("sorting complete... \n");
}