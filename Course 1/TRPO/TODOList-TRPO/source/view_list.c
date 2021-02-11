#include "todolib.h"

void view_list_current()
{
    char str[100];
    char *estr;
    system("clear");
    puts("Your decided jobs:");
    list = fopen("Todo-List.txt", "r");
    if (list == NULL || (estr = fgets(str, sizeof(str), list)) == NULL)
        printf("You have no current plans \n");
    else
    {
		rewind(list);
        while(!feof(list))
        {
            estr = fgets(str, sizeof(str), list);
            if(estr != NULL)
                printf("%s", str);
        }
        fclose(list);
    }
}
void view_list_done()
{
    char str[100];
    char *estr;
    puts("Your completed tasks:");
    list = fopen("Done-List.txt", "r");
    if (list == NULL || (estr = fgets(str, sizeof(str), list)) == NULL)
        printf("You haven't done any jobs");
    else
    {
		rewind(list);
        while(!feof(list))
        {
            estr = fgets(str, sizeof(str), list);
            if(estr != NULL)
                printf("%s", str);
        }
        fclose(list);
    }
    puts("\n");
}
