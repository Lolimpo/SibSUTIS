#include "SCLib.h"

int CU(void)
{
	int operand, command, value, InputValue, accumulator;
	uint16_t tempAccum;
	sc_memoryGet(cell, &value);
	if(sc_commandDecode(value, &command, &operand) == -1)
	{
		sc_regSet(INCORRECT_COMMAND, 1);
		return -1;
	}

	if(command >= 0x30 && command <= 0x33)
		return ALU(command, operand) == 0 ? 0 : -1;

	switch(command)
	{
		case 0x10:
			alarm(0);
			rk_mytermregime(1, 1, 1, 1, 1);
			cin >> InputValue;
			rk_mytermregime(0, 0, 1, 0, 1);
			if(sc_memorySet(operand, InputValue) == -1)
			{
				sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
				return -1;
			}
			printflags();
		  printmemory(cell);
		  printBig(cell);
			PrintOperation();
			printBig(cell);
			break;
		case 0x11:
			if(sc_memoryGet(operand, &value) == -1)
			{
				sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
				return -1;
			}
			cout << value;
			break;
		case 0x20:
			if(sc_memoryGet(operand, &value) == -1)
			{
				sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
				return -1;
			}
			value &= 0x7FFF;
			accumulator = value;
			changeAccumulator(accumulator);
			break;
		case 0x21:
			if(sc_memorySet(operand, Accumulator) == -1)
			{
				sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
				return -1;
			}
			printflags();
		  printmemory(cell);
		  printBig(cell);
			PrintOperation();
			printBig(cell);
			break;
		case 0x40:
			ChangeMemAddress(operand - 1);
			break;
		case 0x41:
			if (Accumulator < 0)
				ChangeMemAddress(operand - 1);
			break;
		case 0x42:
			if (Accumulator == 0)
				ChangeMemAddress(operand - 1);
			break;
		case 0x43:
			return -1; //Programms end
		case 0x69:
			if (sc_memoryGet(operand, &value) == -1)
			{
				sc_regSet(MemoryOverFlow, 1);
				return -1;
			}
			Accumulator %= 16;
			tempAccum = (uint16_t) value << Accumulator;
			value >>= 16 - Accumulator;
			Accumulator = value | tempAccum;
			PrintAccumulator();
			break;
		default:
			return -1;
	}*/
	return 0;
}

int ALU(int command, int operand)
{/*
	int value;
	if (sc_memoryGet(operand, &value) == -1)
	{
		sc_regSet(MemoryOverFlow, 1);
		return -1;
	}
	switch(command)
	{
		case 0x30:
			Accumulator += value;
			if (Accumulator > 32767 || Accumulator < -32767)
			{
				sc_regSet(FlagAccumulatorOvervlow, 1);
				return -1;
			}
			break;
		case 0x31:
			Accumulator -= value;
			if (Accumulator > 32767 || Accumulator < -32767)
			{
				sc_regSet(FlagAccumulatorOvervlow, 1);
				return -1;
			}
			break;
		case 0x33:
			Accumulator *= value;
			if (Accumulator > 32767 || Accumulator < -32767)
			{
				sc_regSet(FlagAccumulatorOvervlow, 1);
				return -1;
			}
			break;
		case 0x32:
			if (value == 0)
			{
				sc_regSet(FlagZeroDivision, 1);
				return -1;
			}
			Accumulator /= value;
			break;
		default:
			return -1;
	}
	PrintAccumulator();*/
	return 0;
}
