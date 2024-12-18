#include "stdio.h"
#include "stdbool.h"

char file_name[] = "C:\\Users\\prana\\OneDrive\\Documents\\GitHub\\AOC-2K24\\Day3\\puzzle_input.txt";

int main(){
    FILE *ptr = fopen(file_name, "r");

    if (ptr == NULL){
        printf("File Not Found \n");
        return 0;
    }

    int command_index = 0;

    bool mul_state = true;

    bool do_state = false;

    bool dont_state = false;
    
    int first_number_offset = 0;
    int first_number[3] = {0,0,0};
    bool first_number_done = false;

    int second_number_offset = 0;
    int second_number[3] = {0,0,0};
    bool second_numer_done = false;

    int sum_of_products = 0;

    while(1){
        char input_char;

        int num_char_read = fscanf(ptr, "%c", &input_char);

        if(num_char_read != 1){
            printf("End of File Reached... \n");
            break;
        }
        else{
            if(input_char == 'd' && command_index == 0){
                command_index++;
                do_state = true;
            }
            else if(input_char == 'o' && command_index == 1 && do_state){
                command_index++;
            }
            else if(input_char == '(' && command_index == 2 && do_state){
                command_index++;
            }
            else if(input_char == ')' && command_index == 3 && do_state){
                command_index = 0;
                mul_state = true;
                do_state = false;
            }
            else if(input_char == 'n' && command_index == 2 && do_state){
                command_index++;
                do_state = false;
                dont_state = true;
            }
            else if(input_char == 39 && command_index == 3 && dont_state){
                command_index++;
            }
            else if(input_char == 't' && command_index == 4 && dont_state){
                command_index++;
            }
            else if(input_char == '(' && command_index == 5 && dont_state){
                command_index++;
            }
            else if(input_char == ')' && command_index == 6 && dont_state){
                command_index = 0;
                mul_state = false;
                dont_state = false;
            }
            else if(input_char == 'm' && command_index == 0 && mul_state){
                command_index++;
            }
            else if(input_char == 'u' && command_index == 1 && mul_state){
                command_index++;
            }
            else if(input_char == 'l' && command_index == 2 && mul_state){
                command_index++;
            }
            else if(input_char == '(' && command_index == 3 && mul_state){
                command_index++;
            }
            else if(input_char >= '0' && input_char <= '9' && command_index >= 4 && !(first_number_done) && mul_state){
                *(first_number + first_number_offset) = input_char - '0';
                first_number_offset++;
                command_index++;
            }
            else if(input_char == ',' && command_index == 4 + first_number_offset && mul_state){
                command_index++;
                first_number_done = true;
            }
            else if(input_char >= '0' && input_char <= '9' && command_index >= 5 + first_number_offset && mul_state){
                *(second_number + second_number_offset) = input_char - '0';
                second_number_offset++;
                command_index++;
            }
            else if(input_char == ')' && command_index == 5 + first_number_offset + second_number_offset && mul_state){

                int temp_first_number;
                int temp_second_number;

                if(first_number_offset == 1){
                    temp_first_number = first_number[0];
                }
                else if(first_number_offset == 2){
                    temp_first_number = first_number[0]*10 + first_number[1];
                }
                else if(first_number_offset == 3){
                    temp_first_number = first_number[0]*100 + first_number[1]*10 + first_number[2];
                }
                else{
                    printf("Undefined behavior in first number... \n");
                }

                if(second_number_offset == 1){
                    temp_second_number = second_number[0];
                }
                else if(second_number_offset == 2){
                    temp_second_number = second_number[0]*10 + second_number[1];
                }
                else if(second_number_offset == 3){
                    temp_second_number = second_number[0]*100 + second_number[1]*10 + second_number[2];
                }
                else{
                    printf("Undefined behavior in second number... \n");
                }

                int temp_product = temp_first_number * temp_second_number;
                sum_of_products += temp_product;
                printf("Full command received, current product is %d and total sum is %d. First number was %d and second number was %d\n", temp_product, sum_of_products, temp_first_number, temp_second_number);

                command_index = 0;
                first_number_offset = 0;
                first_number_done = false;
                second_number_offset = 0;

                for(int i = 0; i < 3; i++){
                    first_number[i] = 0;
                    second_number[i] = 0;
                }
            }
            else{
                command_index = 0;
                first_number_offset = 0;
                first_number_done = false;
                second_number_offset = 0;

                do_state = false;
                dont_state = false;

                for(int i = 0; i < 3; i++){
                    first_number[i] = 0;
                    second_number[i] = 0;
                }
            }
        }
    }
}