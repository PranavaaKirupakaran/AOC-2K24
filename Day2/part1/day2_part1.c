#include "stdio.h"

char file_name[] = "C:\\Users\\prana\\OneDrive\\Documents\\GitHub\\AOC-2K24\\Day2\\puzzle_input.txt";

int main(){
    // Reading one line of puzzle input

    FILE *ptr = fopen(file_name, "r");

    if (ptr == NULL){
        printf("File Not Found \n");
        return 0;
    }

    char input_line[100];

    int safe_report_count = 0;

    int line_count = 0;

    while(fgets(input_line, 100, ptr)){
        printf("Analyzing one report of puzzle input... \n");

        int iterator = 0;
        int number_iterator = 0;
        int level_list[10];
        int level_count = 0;

        // Parsing through retrieved line from puzzle input, converting string to int to make proper level arrays

        while(1){
            if(*(input_line + iterator) == ' '){
                if(number_iterator == 2){
                    level_list[level_count] = (*(input_line + iterator - 2)- '0') * 10 + *(input_line + iterator - 1) - '0';
                    //printf("Added : %d to list \n", level_list[level_count]);
                    level_count++;
                    number_iterator = 0;
                }
                else if(number_iterator == 1){
                    level_list[level_count] = (int)*(input_line + iterator - 1) - '0';
                    //printf("Added : %d to list \n", level_list[level_count]);
                    level_count++;
                    number_iterator = 0;
                }
                else{
                    printf("Indeterminate state \n");
                }
            }
            else if(*(input_line + iterator) == '\0' || *(input_line + iterator) == '\n'){
                if(number_iterator == 2){
                    level_list[level_count] = (*(input_line + iterator - 2)- '0') * 10 + *(input_line + iterator - 1) - '0';
                    //printf("Added : %d to list \n", level_list[level_count]);
                    level_count++;
                    number_iterator = 0;
                }
                else if(number_iterator == 1){
                    level_list[level_count] = (int)*(input_line + iterator - 1) - '0';
                    //printf("Added : %d to list \n", level_list[level_count]);
                    level_count++;
                    number_iterator = 0;
                }
                else{
                    printf("Indeterminate state \n");
                }
                break;
            }
            else{
                number_iterator++;
            }
            iterator++;
        }
        //printf("Iterator: %d \n", iterator);

        // Checking for safe conditions

        int init_parity = level_list[0] - level_list[1];
        int safe_flag = 1;

        for(int i = 0; i < level_count - 1; i++){
            int level_difference = level_list[i] - level_list[i + 1];
            if(abs(level_difference) > 3 || abs(level_difference) < 1){
                break;
            }
            else if(init_parity * level_difference < 0){
                // if parity changes, it means that report went from increasing to decreasing or the opposite
                break;
            }
            safe_flag++;
        }

        if (safe_flag == level_count){
            printf("Report on line %d is safe \n", line_count);
            safe_report_count++;
        }
        else{
            printf("Report on line %d is not safe \n", line_count);
        }

        line_count++;

    }

    printf("Total safe report count: %d \n", safe_report_count);

}

