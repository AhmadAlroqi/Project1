#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>  
#include <unistd.h>   
#include "instruction.h"  
#include "alu.h"          
#include "loader.h"       
			  
int main() {
    char *buffer[9] = {NULL};
    int count = 0;

    int RA = 0, RB = 0, RO = 0, carry = 0;
    int pc = 0;

    load(buffer, &count);

    while (pc < count) {
        
        char *instruction = fetch(buffer, pc);
        if (instruction == NULL) {
            printf("Invalid fetch at PC=%d\n", pc);
            break;
        }

        Instruction inst;
        strncpy(inst.binary, instruction, 8);
        inst.binary[8] = '\0';

        decodeInstruction(&inst);
        executeInstruction(&inst, &RA, &RB, &RO, &pc, &carry);

        pc++; 
        usleep(200000); 
    }

    for (int j = 0; j < count; j++) {
        free(buffer[j]);
    }

    return 0;
}

