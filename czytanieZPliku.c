#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH

void readSquareFromFile(const char filename, int start_line, int end_line, int start_char, int num_chars) {
    FILEfile = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }


//    for (int i = 1; i < start_line; ++i) {
//        char line[MAX_LINE_LENGTH];
//        if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
//            printf("Reached end of file before finding start_line.\n");
//            fclose(file);
//            return;
//        }
//    }


    for (int i = start_line; i <= end_line; ++i) {
        char line[MAX_LINE_LENGTH];
        if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
            printf("Reached end of file before finding end_line.\n");
            fclose(file);
            return;
        }


        if (start_char + num_chars > MAX_LINE_LENGTH) {
            printf("Line length exceeds maximum limit.\n");
            fclose(file);
            return;
        }


        for (int j = start_char; j < start_char + num_chars; ++j) {
            if (line[j] == '\0' || line[j] == '\n') {
                printf("Reached end of line before reading specified number of characters.\n");
                fclose(file);
                return;
            }
            printf("%c", line[j]);
        }
        printf("\n");
    }

    fclose(file);
}

int main() {
    const char *filename = "przyklad.txt";
    int start_line = 10;
    int end_line = 60;
    int start_char = 10;
    int num_chars = 60;


    readSquareFromFile(filename, start_line, end_line, start_char, num_chars);

    return 0;
}