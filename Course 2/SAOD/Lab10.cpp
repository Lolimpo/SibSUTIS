#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

void IntoOmega(int i, char *Mantis)
{
	int power;
	for (power = 0; pow(2, power) <= i; power++);
	if (power > 2)
	{
		IntoOmega(power - 1, Mantis);
	}
	itoa(i, Mantis, 2);
	for(int f = 0; f < power; f++)
		cout << Mantis[f];
	cout << " ";
}

int main(void)
{
	int I, Mant = 0, ind, SaveLength = 0;
	double power, ForOmega;
	cin >> I;
	char Len[15], t;
	char Mantis[30];
	for(int i = 0; i <= I; i++)
	{
		cout << i << " ";
		for (power = 0; pow(2, power) <= i ; power++);
		for (int f = 0; f < 4; f++)
		    Len[f] = 'k';
		for (int f = 0; f < power-1; f++)
		    Mantis[f] = 'k';
		itoa(power, Len, 2);
		for (int f = 0; f < 4; f++)
			if (Len[f] != '1' && Len[f] != '0')
				Len[f] = 'k';
		for(int f = 0; f < 4; f++)
		        if (Len[f] == 'k')
		           for (int z = f; z > 0; z--)
                   {
                       t = Len[z];
                       Len[z] = Len[z - 1];
                       Len[z - 1] = t;
                   }
		for(int f = 0; f < 4; f++)
		    if (Len[f] == 'k')
		        Len[f] = '0';

		itoa(i - pow(2, power-1), Mantis, 2);
		for (int f = 0; f < power - 1; f++)
			if (Mantis[f] != '1' && Mantis[f] != '0')
				Mantis[f] = 'k';
		for(int f = 0; f < power-1; f++)
		    if (Mantis[f] == 'k')
		        for (int z = f; z > 0; z--)
                {
                    t = Mantis[z];
                    Mantis[z] = Mantis[z - 1];
                    Mantis[z - 1] = t;
                }
        for(int f = 0; f < power-1; f++)
		    if (Mantis[f] == 'k')
		        Mantis[f] = '0';

		cout << Len[0] << Len[1] << Len[2] << Len[3] << " ";
		for(int f = 0; f < power-1; f++)
			cout << Mantis[f];

		printf("\t\t");
		if(i < 2)
			printf("\t");

		Len[0] = 1;
		for(int f = 0; f < power; f++)
		{
			Len[f] = '0';
			Len[f + 1] = ' ';
			Len[f + 2] = '1';
		}

		for (int f = 0; f < power-1; f++)
		    Mantis[f] = 'k';
		itoa(i - pow(2, power-1), Mantis, 2);
		for (int f = 0; f < power - 1; f++)
			if (Mantis[f] != '1' && Mantis[f] != '0')
				Mantis[f] = 'k';
		for(int f = 0; f < power-1; f++)
		    if (Mantis[f] == 'k')
		        for (int z = f; z > 0; z--)
                {
                    t = Mantis[z];
                    Mantis[z] = Mantis[z - 1];
                    Mantis[z - 1] = t;
                }
        for(int f = 0; f < power-1; f++)
		    if (Mantis[f] == 'k')
		        Mantis[f] = '0';
		if (i != 1)
			cout << " ";
		for(int f = 1; f < power+2; f++)
			cout << Len[f];
		cout << " ";
		for(int f = 0; f < power-1; f++)
			cout << Mantis[f];
		if(i < 4)
			printf("\t");
		printf("\t");
		IntoOmega(i, Mantis);
		cout << "\n";
	}
	return 0;
}
