#include "cpu.h"

void CPU::load(){
        ACC = mem[PC];
        PC = (PC==MAX)? 0 : ++PC;
}

void CPU::store() {
        mem[PC] = ACC;
        PC = (PC==MAX)? 0 : ++PC;
}

void CPU::add() {
        temp = ACC + mem[PC];
        if(temp > MAX) {
                ACC = MAX;
                FLAG |= OVERFLOW;
        }else{
                ACC = temp;
        }
        PC = (PC==MAX)? 0 : ++PC;
}

void CPU::mul() {
        temp = ACC * mem[PC];
        if(temp > MAX) {
                ACC = MAX;
                FLAG |= OVERFLOW;
        }else{
                ACC = temp;
        }
        PC = (PC==MAX)? 0 : ++PC;
}

void CPU::div() {
        temp = ACC / mem[PC];
        if(temp < MIN) {
                ACC = MAX;
                FLAG |= UNDERFLOW;
        }else{
                ACC = temp;
        }
        PC = (PC==MAX)? 0 : ++PC;
}


void CPU::sub() {
        temp = ACC - mem[PC];
        if(temp < MIN) {
                ACC = MAX;
                FLAG |= UNDERFLOW;
        }else{
                ACC = temp;
        }
        PC = (PC==MAX)? 0 : ++PC;
}

void CPU::comp() {
        if(ACC<mem[PC]){
                FLAG |= LESS;
        }
        else if(ACC>mem[PC]) {
                FLAG |= GREAT;
        }
        else{
                FLAG |= EQUAL;
        }

        PC = (PC==MAX)? 0 : ++PC;
}

void CPU::jmp() {
        PC = mem[PC];
}

void CPU::jl() {
        if(FLAG & LESS) {
                jmp();
        }else{
                PC = (PC==MAX)? 0 : ++PC;
        }
}

void CPU::jle() {
        if(FLAG & (LESS | EQUAL)) {
                jmp();
        }else{
                PC = (PC==MAX)? 0 : ++PC;
        }
}

void CPU::je() {
        if(FLAG & EQUAL) {
                jmp();
        }else{
                PC = (PC==MAX)? 0 : ++PC;
        }
}

void CPU::jge() {
        if(FLAG & (GREAT | EQUAL)){
                jmp();
        }else{
                PC = (PC==MAX)? 0 : ++PC;
        }
}

void CPU::jg() {
        if(FLAG & GREAT) {
                jmp();
        }else{
                PC = (PC==MAX)? 0 : ++PC;
        }
}


int CPU::run(char *memory) {
        mem = memory;
        int counter = 1;
        while(true) {
                IR = mem[PC];
                PC++;
                counter++;
                switch(IR) {
                        case LOAD:
                                FLAG = 0;
                                load();
                                break;
                        case STORE:
                                FLAG = 0;
                                store();
                                break;
                        case ADD:
                                FLAG = 0;
                                add();
                                break;
                        case SUB:
                                FLAG = 0;
                                sub();
                                break;
                        case MUL:
                                FLAG = 0;
                                mul();
                                break;
                        case DIV:
                                FLAG = 0;
                                div();
                                break;
                        case COMP:
                                FLAG = 0;
                                comp();
                                break;
                        case JMP:
                                jmp();
                                FLAG = 0;
                                break;
                        case JL:
                                jl();
                                FLAG = 0;
                                break;
                        case JLE:
                                jle();
                                FLAG = 0;
                                break;
                        case JE:
                                je();
                                FLAG = 0;
                                break;
                        case JGE:
                                jge();
                                FLAG = 0;
                                break;
                        case JG:
                                jg();
                                FLAG = 0;
                                break;
                        case NOP:
                                break;
                        case OFF:
                                return counter;
                        default:
                                return counter;
                }
        }
}


