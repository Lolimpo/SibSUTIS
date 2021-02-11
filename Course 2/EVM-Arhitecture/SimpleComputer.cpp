#include "SCLib.h"

int memory[100];
int flagRegister;

int sc_memoryInit()
{
    for(int i = 0; i < 100; i++)
        memory[i] = 0;
    return 0;
}

int sc_memorySet(int address, int value)
{
    if ((address < 0 || address >= 100) & (value < 0 || value > 65535))
    {
        sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
        //cout << dec << "\nOUT_OF_MEMORY_BOUNDS on address:" << address << endl;
        return 0;
    }
    memory[address] = value;
    return 0;
}

int sc_memoryGet(int address, int * value)
{
    int index = memory[address];
    if(address < 0 || address >= 100)
    {
        sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
        //cout << "\nOUT_OF_MEMORY_BOUNDS\n on" << address << endl;
        return 0;
    }
    else
        *value = index;
    return 0;
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
            flagRegister = flagRegister | (1 << (regist - 1));
            return 0;
        }
        else if(value == 0)
        {
            flagRegister = flagRegister & (~(1 << (regist - 1)));
            return 0;
        }
		else
		{
        	sc_regSet(WRONG_FLAG, 1);
        	//cout << "Wrong flag value" << endl;
        	return 0;
		}
    }
    else
    {
        sc_regSet(WRONG_FLAG, 1);
        //cout << "Wrong flag" << endl;
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
        //cout << "Wrong register" << endl;
        return 0;
    }
}

int sc_commandEncode(int command, int operand, int * value)
{
    if(!(check_command(command)) || operand < 0 || operand > 127)
    {
        return -1;
    }
    *value = (command << 7) | operand;
    return 0;
}

int sc_commandDecode(int value, int * command, int * operand)
{
    if((value >> 14) != 0x0)
    {
        return 0;
    }
    *command = value >> 7;
	  *operand = value & 0x7F;
	  if(!(check_command(*command)))
	  {
		    *command = 0;
		    *operand = 0;
		    return -1;
	}
	return 0;
}

bool check_command(int command)
{
	switch(command)
	{
		case 0xa:
			return true;
			break;
		case 0xb:
			return true;
			break;
		case 0x14:
			return true;
			break;
		case 0x15:
			return true;
			break;
		case 0x1e:
			return true;
			break;
		case 0x1f:
			return true;
			break;
		case 0x20:
			return true;
			break;
		case 0x21:
			return true;
			break;
		default:
			return false;
	}
}
