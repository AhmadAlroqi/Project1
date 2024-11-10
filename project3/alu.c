#include <stdio.h>
#include "alu.h"

int ALU(int RA, int RB, int op, int *Result, int *Carry) {
    int sum = 0;
    if (op == 0) { // Addition
        sum = RA + RB;
        *Carry = (sum > 15) ? 1 : 0; // Set carry if overflow
    } else if (op == 1) { // Subtraction
        sum = RA - RB;
    } 
    return sum;
}

