#include <stdio.h>


void print_hex_bytes(const unsigned char *raw_instr, int numOfByte){
    for(int i=0; i<numOfByte; i++){
        printf("%02x ",raw_instr[i]);
    }
    printf("    ");
}


void disassemble(const unsigned char *raw_instr){
    char regis[100][100] = {"%rax","%rcx","%rdx","%rbx","%rsp","%rbp","%rsi","%rdi"};
    int opcode = raw_instr[0];
    int numOfByte = 0;
    // push immediate constant.
    if(opcode == 0x68){

        numOfByte = 5;
        print_hex_bytes(raw_instr, numOfByte);
        printf("pushq $%#x\n", (raw_instr[4] << 24 )+ (raw_instr[3] << 16)+ (raw_instr[2] << 8) + (raw_instr[1]));

    }else if(opcode == 0xff){
        unsigned char secondByte = raw_instr[1];
        if(secondByte == 0x74){ 
            // indirect-dp-scaled-index
            unsigned char thirdByte = raw_instr[2];
            unsigned char scale = thirdByte >> 5; // shift 6bits - 1.
            unsigned char regisI = (thirdByte >> 3) & 7; 
            unsigned char regisB = thirdByte & 7;
            unsigned char hexVal = raw_instr[3];
            numOfByte = 4;
            print_hex_bytes(raw_instr, numOfByte);
            printf("pushq %#x(%s,%s,%d)\n",hexVal,regis[regisB],regis[regisI],scale);
        }else{
            unsigned char secondOpCode = secondByte >> 4;
            unsigned char regisB = secondByte & 7;
            if(secondOpCode == 3){
                //indirect
                numOfByte = 2;
                print_hex_bytes(raw_instr, numOfByte);
                printf("pushq (%s)\n", regis[regisB]);
            }else{
                // indirect-dp
                unsigned char hexVal = raw_instr[2];
                numOfByte = 3;
                print_hex_bytes(raw_instr, numOfByte);
                printf("pushq %#x(%s)\n",hexVal,regis[regisB]);

            }

        }

    }else{
        // push register
        unsigned char regisNum = opcode & 7;
        numOfByte = 1;
        print_hex_bytes(raw_instr, numOfByte);
        printf("pushq %s\n", regis[regisNum]);
    }
}
/*
int main(){
    const unsigned char raw_instr[] = {0x68 ,0x10 ,0x3f ,0x00,0x00};
    const unsigned char raw_instr2[] = {0x53};
    const unsigned char raw_instr3[] = {0xff,0x32}; 
    const unsigned char raw_instr4[] = {0xff,0x70,0x08};
    const unsigned char raw_instr5[] = {0xff,0x74,0x8d ,0xff};
    disassemble(raw_instr);
    disassemble(raw_instr2);
    disassemble(raw_instr3);
    disassemble(raw_instr4);
    disassemble(raw_instr5);
    return 1;
}
*/
