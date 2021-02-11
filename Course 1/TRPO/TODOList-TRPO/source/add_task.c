#include "todolib.h"

bool add_task(char input_string[100])
{
	if(strcmp(input_string,"\n") != 0)
	{
		list = fopen("Todo-List.txt", "a+");
		fprintf(list, "%s", input_string);
		fclose(list);
		system("clear");
		return true;
	}
	else
		return false;
}

