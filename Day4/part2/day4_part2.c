#include "stdio.h"
#include "stdbool.h"

void print_crossword_puzzle();

char file_name[] = "C:\\Users\\prana\\OneDrive\\Documents\\GitHub\\AOC-2K24\\Day4\\puzzle_input.txt";

char key_word[] = "XMAS";
int key_length = 4;
int key_found_count = 0;

int y_length = 140;
int x_length = 140;

char crossword_puzzle[140][141];

int main(){
    FILE *ptr = fopen(file_name, "r");

    if (ptr == NULL){
        printf("File Not Found \n");
        return 0;
    }

    for(int y = 0; y < y_length; y++){
        for(int x = 0; x < x_length + 1; x++){
            char temp_char;
            fscanf(ptr, "%c", &temp_char);
            crossword_puzzle[y][x] = temp_char;
        }
    }

    //print_crossword_puzzle();

    for(int y = 0; y < y_length; y++){
        for(int x = 0; x < x_length; x++){
            if(crossword_puzzle[y][x] == key_word[2]){

                if(x + 1 < x_length && x - 1 >= 0 && y - 1 >= 0 && y + 1 < y_length){
                    int left_bar = 0;
                    int right_bar = 0;

                    if(crossword_puzzle[y-1][x-1] == key_word[1] && crossword_puzzle[y+1][x+1] == key_word[3]){
                        left_bar++;
                    }
                    else if(crossword_puzzle[y-1][x-1] == key_word[3] && crossword_puzzle[y+1][x+1] == key_word[1]){
                        left_bar++;
                    }
                    else{

                    }

                    if(crossword_puzzle[y-1][x+1] == key_word[1] && crossword_puzzle[y+1][x-1] == key_word[3]){
                        right_bar++;
                    }
                    else if(crossword_puzzle[y-1][x+1] == key_word[3] && crossword_puzzle[y+1][x-1] == key_word[1]){
                        right_bar++;
                    }
                    else{

                    }

                    if(right_bar == 1 && left_bar == 1){
                        key_found_count++;
                    }
                }

            }
        }
    }

    printf("Found %d XMAS \n", key_found_count);

    

}

void print_crossword_puzzle(){
    for(int y = 0; y < y_length; y++){
        for(int x = 0; x < x_length + 1; x++){
            printf("%c", crossword_puzzle [y][x]);
        }
    }
}