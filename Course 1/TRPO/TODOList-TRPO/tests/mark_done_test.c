#include "todolib.h"

bool mark_done(int done_str)
{
    char str[50][100];
    int i = 0;
    FILE * done;
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
    int str_count = i;
    i = 0;
    if ((done_str <= str_count) && (done_str != 0))
    {
        done = fopen("Done-List.txt", "at");
        fprintf(done, "%s", str[done_str-1]);
        str[done_str - 2][100] = 0;
        list = fopen("Todo-List.txt", "w");
        while (i < str_count)
        {
            if(str[i] != 0)
                fprintf(list, "%s", str[i]);
            i++;
        }
        fclose(list);
        fclose(done);
        return true ;
    }
    else
        return false;
}
