#ifndef _CALIB_H_
#define _CALIB_H_

#include <iostream>
#include <cstdlib>
#include <fstream>

#define OUT_OF_MEMORY_BOUNDS 1
#define WRONG_FLAG 2
#define INCORRECT_COMMAND 3

using namespace std;

int memory[100];
int flagRegister;

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int * value);
int sc_memorySave(char * filename);
int sc_memoryLoad(char * filename);
int sc_regInit();
int sc_regSet(int regist, int value);
int sc_regGet(int regist, int * value);
int sc_commandEncode(int command, int operand, int * value);
int sc_commandDecode(int value, int * command, int * operand);

int sc_memoryInit()
{
    for(int i = 0; i < 100; i++)
        memory[i] = 0;
    return 0;
}

int sc_memorySet(int address, int value)
{
    if (address < 0 || address >= 100)
    {
        sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
        cout << dec << "\nOUT_OF_MEMORY_BOUNDS on address:" << address << endl;
        return 0;
    }
    memory[address] = value;
    return 0;
}

int sc_memoryGet(int address, int * value)
{
    int index;
    if(address < 0 || address >= 100)
    {
        sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
        cout << "\nOUT_OF_MEMORY_BOUNDS\n on" << address << endl;
        return 0;
    }

    else
        index = *value;
    return index;
}

int sc_memorySave(char * filename)
{
    ofstream addressData(filename, ios::out | ios::binary);
    addressData.write((char *)memory, sizeof(memory));
    addressData.close();
    return 0;
}

int sc_memoryLoad(char * filename)
{
    ifstream addressData(filename, ios::in | ios::binary);
    addressData.read((char *)&memory, sizeof(memory));
    for(int i = 0; i < 100; i++)
    {
        cout << dec <<"Address[" << i << "] = ";
        cout << hex << showbase << memory[i] << endl;
    }
    return 0;
}

int sc_regInit()
{
    flagRegister = 0;
    return 0;
}

int sc_regSet(int regist, int value)
{
    if(regist > 0 && regist < 6)
    {
        if(value == 1)
        {
            flagRegister = flagRegister | (1 << (1 - regist));
            return 0;
        }
        else if(value == 0)
        {
            flagRegister = flagRegister & (~(1 << (1 - regist)));
            return 0;
        }
        sc_regSet(WRONG_FLAG, 1);
        cout << "Wrong flag value" << endl;
        return 0;
    }
    else
    {
        sc_regSet(WRONG_FLAG, 1);
        cout << "Wrong flag" << endl;
        return 0;
    }
}

int sc_regGet(int regist, int * value)
{
    if(regist > 0 && regist < 6)
    {
        *value = (flagRegister >> (regist - 1)) & 0x1;
        return 0;
    }
    else
    {
        sc_regSet(WRONG_FLAG, 1);
        cout << "Wrong register" << endl;
        return 0;
    }
}

int sc_commandEncode(int command, int operand, int * value)
{
    if(command < 0 || command > 127 || operand < 0 || operand > 127)
    {
        sc_regSet(INCORRECT_COMMAND, 1);
        return 0;
    }
    *value = (command << 7) | operand;
    return 0;
}

int sc_commandDecode(int value, int * command, int * operand)
{
    if(value >> 15 != 0x0)
    {
        sc_regSet(INCORRECT_COMMAND, 1);
        return 0;
    }
    *command = value >> 7;
	*operand = value & 0x7F;
	return 0;
}
#endif // _CALIB_H_
