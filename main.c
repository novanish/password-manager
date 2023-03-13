#include "performActions.c"
#include "printActionkeys.c"

int main()
{
    char action;

    printf("\nWELCOME!!! to Password generator and saver\n");

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