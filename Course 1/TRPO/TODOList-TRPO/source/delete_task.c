#include "todolib.h"

bool delete_task(int del_num)
{
    int i = 0;
    char str[50][100];
    char strc[100];
    char *estr;
    system("clear");
    list = fopen("Todo-List.txt", "r");
    if ((list == NULL) || ((estr = fgets(strc, sizeof(strc), list)) == NULL))
    {
        printf("You have no current plans \n");
    }
    else
    {
		rewind(list);
        while(!feof(list))
        {
            estr = fgets(strc, sizeof(strc), list);
            if(estr != NULL)
                printf("%s", strc);
        }
        fclose(list);
    }
    list = fopen("Todo-List.txt", "r");
    if (list != NULL)
    {
        while(!feof(list))
        {
            fgets(str[i], sizeof(str), list);
            i++;
        }
    }
    fclose(list);
    list = fopen("Todo-List.txt", "w");
    int str_count = i;
    i = 0;
    if ((del_num <= str_count) && (del_num != 0))
    {
        str[del_num - 2][100] = 0;
        while (i < str_count)
        {
             if (str[i] != 0)
                fprintf(list, "%s", str[i]);
             i++;
        }
        fclose(list);
        return true;
    }
    else
        return false;
}
