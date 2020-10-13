#include <iostream>
#include <unistd.h>
#include <cstring>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

char PATH[10000];
char NAME[40];

void findFile()
{
    FILE* file = fopen(PATH, "r");
    int temple;
    if(file == NULL)
    {
        cout << "Error" << endl;
    }
    fscanf(file, "%d%s", &temple, NAME);
    cout << NAME << endl;
    fclose(file);
}

int checkNumber(char* str)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(!isdigit(str[i]))
            return  0;
    }
    return  1;
}

int main(int argc, char *argv[])
{
    DIR *dir;
    char *userName = (char *) calloc(100, sizeof(char));
    int counter = 0;
    int files_size = 0;
    struct stat st;
    read(0, userName, 128);
    write(1, "Hello, ", 7);
    write(1, userName, strlen(userName));
    dir = opendir("/tmp");
    while(readdir(dir))
    {
        counter++;
        lstat("/tmp", &st);
        files_size += st.st_size;
    }
    cout << "Files in directory /tmp: " << counter << "\nTotal size: " << files_size << endl;
    closedir(dir);
    DIR* dir1 = opendir("/proc");
    struct dirent* file;
    while(file = readdir(dir1))
    {
        if(checkNumber(file -> d_name))
        {
            PATH[0] = '\0';
            strcat(PATH, "/proc/");
            strcat(PATH, file -> d_name);
            strcat(PATH, "/stat");
            findFile();
        }
    }
    closedir(dir1);
    return 0;
}
