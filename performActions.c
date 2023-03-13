#include "deletePassword.c"
#include <ctype.h>

boolean perform_actions(char action) {
  switch (toupper(action)) {
  case 'S': {
    save_password();
    return false;
  }

  case 'U': {
    return false;
  }

  case 'D': {
    delete_password();
    return false;
  }

  case 'L': {
    list_emails();
    return false;
  }

  case 'G': {
    char *password;
    generate_password(&password);

    printf("Password:- %s", password);

    free(password);
    return false;
  }

  default: {
    return true;
  }
  }
}
