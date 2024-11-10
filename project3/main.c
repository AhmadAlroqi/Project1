#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asm2bin.h"

int main(int argc, char *argv[]) {

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen("output.bin", "w");

    if (input == NULL) {
        printf("Input file not found!\n");
        return 1;
    }
    if (output == NULL) {
        printf("Could not open output file!\n");
        fclose(input);
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), input)) {
        line[strcspn(line, "\n")] = 0;  
        asm2bin(line, output);
    }

    fclose(input);
    fclose(output);

    
    return 0;
}

