#include "../sources/cpu.h"
#include <iostream>

int main() {
        
        CPU cpu;
        
        char mem[] = {
                LOAD, 10,
                MUL, 3,
                ADD, 70,
                STORE, 0,
                SUB, 20,
                STORE, 0,
                DIV, 10,
                STORE, 0
        };


        std::cout<<"Before execution :\t";        
        for(int i=0; i<sizeof(mem)+1; i++){
                std::cout<<(int)mem[i]<<" ";
        }
        std::cout<<std::endl;

        
        int cycles = cpu.run(mem);
        
        std::cout<<"After "<<cycles<<" cycles :\t";        
        for(int i=0; i<sizeof(mem)+1; i++){
                std::cout<<(int)mem[i]<<" ";
        }
        std::cout<<std::endl;
}