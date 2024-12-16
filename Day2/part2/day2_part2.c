#include "stdio.h"
#include "stdbool.h"

char file_name[] = "C:\\Users\\prana\\OneDrive\\Documents\\GitHub\\AOC-2K24\\Day2\\puzzle_input.txt";

bool checkReportSafetyMain(int* level_list, int level_count);
bool checkReportSafety(int* level_list, int level_count);
void removeLevel(int* level_list, int level_count, int level_index, int* newReport);

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

        if(checkReportSafetyMain(level_list,level_count)){
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


bool checkReportSafetyMain(int* level_list, int level_count){
    int safe_flag = 1;

    for(int i = 0; i < level_count - 1; i++){
        int level_difference = level_list[i] - level_list[i + 1];
        if(abs(level_difference) > 3 || abs(level_difference) < 1){
            int removedLevelList1[10];
            removeLevel(level_list, level_count, i, removedLevelList1);
            int removedLevelList2[10];
            removeLevel(level_list, level_count, i + 1, removedLevelList2);
            if(checkReportSafety(removedLevelList1, level_count - 1)){
                safe_flag = level_count;
                printf("Report made safe 1\n");
            }
            else if(checkReportSafety(removedLevelList2, level_count - 1)){
                safe_flag = level_count;
                printf("Report made safe 2\n");
            }
            break;
        }
        if(i + 2 < level_count){
            int diff1 = level_list[i+ 1] - level_list[i];
            int diff2 = level_list[i+2] - level_list[i+1];
            if(diff1 * diff2 < 0){
                int removedLevelList1[10];
                removeLevel(level_list, level_count,i, removedLevelList1);
                int removedLevelList2[10];
                removeLevel(level_list, level_count,i + 1, removedLevelList2);
                int removedLevelList3[10];
                removeLevel(level_list, level_count,i + 2, removedLevelList3);
                if(checkReportSafety(removedLevelList1, level_count - 1)){
                    safe_flag = level_count;
                    printf("Report made safe 3\n");
                }
                else if(checkReportSafety(removedLevelList2, level_count - 1)){
                    safe_flag = level_count;
                    printf("Report made safe 4\n");
                }
                else if(checkReportSafety(removedLevelList3, level_count - 1)){
                    safe_flag = level_count;
                    printf("Report made safe 5\n");
                }
                break;
            }
        }
        safe_flag++;
    }

    if (safe_flag == level_count){
        return true;
    }
    else{
        return false;
    }
}

bool checkReportSafety(int* level_list, int level_count){
    int init_parity = level_list[0] - level_list[1];
    int safe_flag = 1;

    for(int i = 0; i < level_count - 1; i++){
        int level_difference = level_list[i] - level_list[i + 1];
        if(abs(level_difference) > 3 || abs(level_difference) < 1){
            break;
        }
        if(i + 2 < level_count){
            int diff1 = level_list[i+ 1] - level_list[i];
            int diff2 = level_list[i+2] - level_list[i+1];
            if(diff1 * diff2 < 0){
                break;
            }
        }
        safe_flag++;
    }

    if (safe_flag == level_count){
        return true;
    }
    else{
        return false;
    }
}

void removeLevel(int* level_list, int level_count,int level_index, int* newReport){
    int iterator = 0;
    for(int i = 0; i < level_count; i++){
        if(i == level_index){
            //printf("Removing Index %d from report \n", i);
        }
        else{
            *(newReport + iterator) = level_list[i];
            iterator++;
        }
        
    }
}