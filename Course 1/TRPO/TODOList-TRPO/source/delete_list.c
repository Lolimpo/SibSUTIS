#include "todolib.h"

void delete_list()
{
	char str[100];
	system("clear");
	list = fopen("Todo-List.txt","r");
	if((list == NULL) || (fgets(str, sizeof(str), list) == NULL))
        printf("You have no current plans");
	else
	{
        fclose(list);
        list = fopen("Todo-List.txt", "w+");
        fclose(list);
        printf("Your task list is now empty!\n");
	}
}
