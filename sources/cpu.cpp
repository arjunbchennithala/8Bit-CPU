#include "cpu.h"

void CPU::inc() {
        if(PC>=MAX) {
                PC = 0;
        }else{
                PC++;
        }
}


void CPU::run() {
        while(true) {
                IR = mem[PC];
                inc();
                switch(IR) {
                        case LOAD:
                                FLAG = 0;
                                MAR = PC;
                                MBR = mem[MAR];
                                R1 = MBR;
                                inc();
                                break;

                        case STORE:
                                FLAG = 0;
                                MAR = PC;
                                MBR = R1;
                                mem[MAR] = MBR;
                                inc();
                                break;

                        case STORER:
                                FLAG = 0;
                                MAR = PC;
                                MBR = R2;
                                mem[MAR] = MBR;
                                inc();
                                break;

                        case ADD:
                                FLAG = 0;
                                MAR = PC;
                                MBR = mem[MAR];
                                R2 = MBR;
                                temp = R1 + R2;
                                if(temp>MAX){R1 = MAX;FLAG |= OVERFLOW;}else{R1 = temp;}
                                inc();
                                break;

                        case SUB:
                                FLAG = 0;
                                MAR = PC;
                                MBR = mem[MAR];
                                R2 = MBR;
                                temp = R1 - R2;
                                if(temp<0){R1 = 0;FLAG |= UNDERFLOW;}else{R1 = temp;}
                                inc();
                                break;

                        case MUL:
                                FLAG = 0;
                                MAR = PC;
                                MBR = mem[MAR];
                                R2 = MBR;
                                temp = R1;
                                for(int i=1; i<R2; i++){
                                        temp += R1;
                                }
                                if(temp>MAX){R1 = MAX;FLAG |= OVERFLOW;}else{R1 = temp;}
                                inc();
                                break;

                        case DIV:
                                FLAG = 0;
                                MAR = PC;
                                MBR = mem[MAR];
                                R2 = MBR;
                                temp = R1;
                                int i;
                                for(i=0; ((temp - R2) >= 0); i++) {     //(temp > R2) && 
                                        temp -= R2;
                                }
                                if(temp<0){R1 = 0;FLAG |= UNDERFLOW;}else{R1 = i; R2 = temp;}
                                inc();
                                break;

                        case COMP:
                                FLAG = 0;
                                MAR = PC;
                                MBR = mem[MAR];
                                R2 = MBR;
                                if(R2<R1) {
                                        FLAG |= LESS;
                                }else if(R2>R1) {
                                        FLAG |= GREAT;
                                }else{
                                        FLAG |= EQUAL;
                                }
                                inc();
                                break;

                        case JMP:
                                MAR = PC;
                                MBR = mem[MAR];
                                PC = MBR;
                                FLAG = 0;
                                break;

                        case JL:
                                MAR = PC;
                                MBR = mem[MAR];
                                if(FLAG & LESS) {
                                        PC = MBR;
                                }else{
                                        inc();
                                }
                                FLAG = 0;
                                break;

                        case JLE:
                                MAR = PC;
                                MBR = mem[MAR];
                                if(FLAG & (LESS | EQUAL)) {
                                        PC = MBR;
                                }else{
                                        inc();
                                }
                                FLAG = 0;
                                break;

                        case JE:
                                MAR = PC;
                                MBR = mem[MAR];
                                if(FLAG & EQUAL) {
                                        PC = MBR;
                                }else{
                                        inc();
                                }
                                FLAG = 0;
                                break;

                        case JGE:
                                MAR = PC;
                                MBR = mem[MAR];
                                if(FLAG & (GREAT | EQUAL)) {
                                        PC = MBR;
                                }else{
                                        inc();
                                }
                                FLAG = 0;
                                break;

                        case JG:
                                MAR = PC;
                                MBR = mem[MAR];
                                if(FLAG & GREAT) {
                                        PC = MBR;
                                }else{
                                        inc();
                                }
                                FLAG = 0;
                                break;

                        case NOP:
                                FLAG = 0;
                                inc();
                                break;

                        case OFF:
                                return;

                        default:
                                return;
                }
        }
}


