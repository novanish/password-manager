#include <ctype.h>
#include "generatePassword.c"

boolean perform_actions(char action)
{
    switch (toupper(action))
    {
    case 'S':
    {
        return false;
    }

    case 'U':
    {
        return false;
    }
    case 'D':
    {
        return false;
    }

    case 'G':
    {
        char *password;
        generate_password(&password);

        printf("Password:- %s", password);

        free(password);
        return false;
    }

    default:
    {
        return true;
    }
    }
}
