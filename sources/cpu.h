#ifndef CPU_H 

#define CPU_H 1

enum InstructionSet {
        LOAD = 1,
        STORE,
        ADD,
        SUB,
        MUL,
        DIV,
        COMP,
        JMP,
        JL,
        JLE,
        JE,
        JGE,
        JG,
        NOP,
        OFF
};

enum Limits {
        MIN = 0,
        MAX = 255
};

enum Flags {
        GREAT = (1<<0),
        EQUAL = (1<<1),
        LESS = (1<<2),
        OVERFLOW = (1<<3),
        UNDERFLOW = (1<<4)
};

class CPU{
        char *mem;

        char ACC, FLAG, IR, PC;
        int temp;

        void load();
        void store();
        void add();
        void sub();
        void div();
        void mul();
        void jmp();
        void jl();
        void jle();
        void je();
        void jge();
        void jg();
        void comp();
        void fault(); //Reserved

public:
        CPU() {
                ACC = FLAG = IR = PC = 0;
        }
        ~CPU() {}
        int run(char *memory);
};

#endif