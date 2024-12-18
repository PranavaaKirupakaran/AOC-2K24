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

    for(int y = 0; y < y_length; y++){
        for(int x = 0; x < x_length; x++){
            if(crossword_puzzle[y][x] == key_word[0]){

                // FORWARD
                bool forward_flag = true;
                if(x + 3 < x_length){
                    for(int x_offset = 1; x_offset < key_length; x_offset++){
                        if(crossword_puzzle[y][x + x_offset] != key_word[x_offset]){
                            forward_flag = false;
                            break;
                        }
                    }
                    if(forward_flag){
                        key_found_count++;
                    }
                }

                // BACKWARD
                if(x - 3 >= 0){
                    bool backward_flag = true;
                    for(int x_offset = 1; x_offset < key_length; x_offset++){
                        if(crossword_puzzle[y][x - x_offset] != key_word[x_offset]){
                            backward_flag = false;
                            break;
                        }
                    }
                    if(backward_flag){
                        key_found_count++;
                    }   
                }

                // UPWARD
                if(y - 3 >= 0){
                    bool upward_flag = true;
                    for(int y_offset = 1; y_offset < key_length; y_offset++){
                        if(crossword_puzzle[y - y_offset][x] != key_word[y_offset]){
                            upward_flag = false;
                            break;
                        }
                    }
                    if(upward_flag){
                        key_found_count++;
                    }
                }

                // DOWNWARD
                if(y + 3 < y_length){
                    bool downward_flag = true;
                    for(int y_offset = 1; y_offset < key_length; y_offset++){
                        if(crossword_puzzle[y + y_offset][x] != key_word[y_offset]){
                            downward_flag = false;
                            break;
                        }
                    }
                    if(downward_flag){
                        key_found_count++;
                    }
                }

                // FORWARD UPWARD
                bool forward_upward_flag = true;
                if(x + 3 < x_length && y - 3 > 0){
                    for(int pos_offset = 1; pos_offset < key_length; pos_offset++){
                        if(crossword_puzzle[y - pos_offset][x + pos_offset] != key_word[pos_offset]){
                            forward_upward_flag = false;
                            break;
                        }
                    }
                    if(forward_upward_flag){
                        key_found_count++;
                    }
                }

                // FORWARD DOWNWARD
                bool forward_downward_flag = true;
                if(x + 3 < x_length && y + 3 < y_length){
                    for(int pos_offset = 1; pos_offset < key_length; pos_offset++){
                        if(crossword_puzzle[y + pos_offset][x + pos_offset] != key_word[pos_offset]){
                            forward_downward_flag = false;
                            break;
                        }
                    }
                    if(forward_downward_flag){
                        key_found_count++;
                    }
                }

                // BACKWARD UPWARD
                bool backward_upward_flag = true;
                if(x - 3 >= 0 && y - 3 >= 0){
                    for(int pos_offset = 1; pos_offset < key_length; pos_offset++){
                        if(crossword_puzzle[y - pos_offset][x - pos_offset] != key_word[pos_offset]){
                            backward_upward_flag = false;
                            break;
                        }
                    }
                    if(backward_upward_flag){
                        key_found_count++;
                    }
                }

                // BACKWARD DOWNWARD
                bool backward_downward_flag = true;
                if(x - 3 >= 0 && y + 3 < y_length){
                    for(int pos_offset = 1; pos_offset < key_length; pos_offset++){
                        if(crossword_puzzle[y + pos_offset][x - pos_offset] != key_word[pos_offset]){
                            backward_downward_flag = false;
                            break;
                        }
                    }
                    if(backward_downward_flag){
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