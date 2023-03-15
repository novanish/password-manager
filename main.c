#include "performActions.c"
#include "printActionKeys.c"

int main()
{
    char action;

    printf("\nWELCOME!!! to Password Manager\n");

    while (true)
    {
        print_action_keys();
        scanf(" %c[^\n]", &action);

        boolean shouldTerminate = perform_actions(action);
        
        if (shouldTerminate)
            break;
    }

    printf("\nTerminating the program......\n");

    return 0;
}