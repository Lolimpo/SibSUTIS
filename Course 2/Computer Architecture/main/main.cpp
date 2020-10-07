#include "CALib.h"

int main()
{
    int value;
    int command = 0x33;
    int operand = 0x33;
    //system("CLS");
    sc_memoryInit();
    sc_regInit();

    sc_memorySave("data");
    cout << "Initial Memory:" << endl;
    sc_memoryLoad("data");

    sc_memorySet(20, 15);
    sc_memorySet(-1, 60);
    sc_memorySet(10, 1000000);

    sc_memorySave("data");
    cout << "Changed Memory:" << endl;
    sc_memoryLoad("data");

    cout << "\nValue on register 1:" << endl;
    sc_regGet(1, &value);
    cout << value << endl;
    cout << "Checking value on register -1:" << endl;
    sc_regGet(-1, &value);

    sc_commandEncode(command, operand, &value);
    cout << "Value got after encoding: " << value << endl;
    sc_commandDecode(value, &command, &operand);
    cout << "Command and operand decoded from value: " << command << ", " << operand << endl;
    return 0;
}
