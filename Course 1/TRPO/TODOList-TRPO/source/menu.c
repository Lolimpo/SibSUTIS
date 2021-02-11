#include "todolib.h"

int menu()
{
    int m;
    char input_string[100];
    int done_str, del_num;
    while(1)
    {
        puts("1. View your TODO-List");
        puts("2. Add new task");
        puts("3. Mark task as done");
        puts("4. Delete tasks");
        puts("0. Exit program");
        puts("What would you like to do next?");
        scanf("%d%*c",&m);
        switch(m)
        {
            case 1:
                view_list_current();
                view_list_done();
                break;
            case 2:
				system("clear");
				printf("Enter your job:");
				fgets(input_string, sizeof(input_string), stdin);
                add_task(input_string);
                break;
            case 3:
                system("clear");
                view_list_current();
                printf("Which job had you done?");
                scanf("%d", &done_str);
                mark_done(done_str);
                break;
            case 4:
                system("clear");
                puts("1. Delete 1 task");
                puts("2. Delete all current tasks");
                puts("0. Return to main menu");
                scanf("%d%*c", &m);
                switch(m)
                {
                    case 1:
                        view_list_current();
                        printf("Which job would you like to delete?");
                        scanf("%d", &del_num);
                        delete_task(del_num);
                        break;
                    case 2:
                        delete_list();
                        break;
                    default:
                        system("clear");
                        menu();
                        break;
                }
            case 0:
                return 0;
            default :
                puts("No such command");
        }
    }
}
