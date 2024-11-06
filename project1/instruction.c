#include <stdio.h>
#include <string.h>
#include "instruction.h"

void decodeInstruction(Instruction *inst) {
    inst->J = inst->binary[0] - '0';
    inst->C = inst->binary[1] - '0';
    inst->D1 = inst->binary[2] - '0';
    inst->D0 = inst->binary[3] - '0';
    inst->Sreg = inst->binary[4] - '0';
    inst->S = inst->binary[5] - '0';
    inst->imm = inst->binary[6] - '0';
    inst->imm1 = inst->binary[7] - '0';
}

void decoder(char *buffer[9], int pc_counter) {
    Instruction inst;
    strncpy(inst.binary, buffer[pc_counter], 8);
    inst.binary[8] = '\0';

    decodeInstruction(&inst);

    printf("Decoded Instruction %d: J=%d, C=%d, D1=%d, D0=%d, Sreg=%d, S=%d, imm=%d, imm1=%d\n",
           pc_counter + 1, inst.J, inst.C, inst.D1, inst.D0, inst.Sreg, inst.S, inst.imm, inst.imm1);
}

void print_instruction(char *buffer[9], int pc_counter) {
    if (buffer[pc_counter] != NULL) {
        printf("Instruction %d: %s\n", pc_counter + 1, buffer[pc_counter]);
    } else {
        printf("No instruction\n");
    }
}

