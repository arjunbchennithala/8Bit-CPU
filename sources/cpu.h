#ifndef CPU_H 

#define CPU_H 1

enum InstructionSet {
        LOAD = 1, //Load data to r1 register
        STORE,    //Store data from r1 register to next memory address
        STORER,   //Store data from r2 register to next memory address
        ADD,      //Adds value in register r1 with value at next memory location and stores back to the r1
        SUB,      //Subtracts value in next memory location from value in r1 and stores back to the r1
        MUL,      //Multiplies value in next memory location with value in r1 and stores back to the r1
        DIV,      //Divides value in r1 by value at next memory lcoation, quotient stores to r1 and remainder to r2
        COMP,     //Compare the value in next memory location with r1, stores the result in FLAG register as LESS, GREAT, EQUAL bits
        JMP,      //Alters program flow to the address in next memory location without any condition
        JL,       //Alters program flow to the address in next memory location when only if COMP instruction set LESS bit
        JLE,      //Alters program flow to the address in next memory location when only if COMP instruction set LESS or EQUAL bit
        JE,       //Alters program flow to the address in next memory location when only if COMP instruction set EQUAL bit
        JGE,      //Alters program flow to the address in next memory location when only if COMP instruction set EQUAL OR GREAT bit
        JG,       //Alters program flow to the address in next memory location when only if COMP instruction set GREAT bit
        NOP,      //It does nothing and increases PC register
        OFF       //Stops the CPU and return back
};

enum Limits {
        MIN = 0,
        MAX = 255
};

enum Flags {
        GREAT = 1,
        EQUAL = (1<<1),
        LESS = (1<<2),
        OVERFLOW = (1<<3),
        UNDERFLOW = (1<<4)
};

class CPU{
        char *mem;

        char R1, FLAG, IR, PC, MAR, MBR, R2;
        int temp;
        int counter = 0;

        void run();
        void inc();

public:
        CPU(char *memory) {
                R1 = R2 = FLAG = IR = PC = MAR = MBR = 0;
                mem = memory;
                run();
        }
        ~CPU() {}
        
};

#endif