#include "updatePassword.c"
#include <ctype.h>

boolean perform_actions(char action) {
  switch (toupper(action)) {
  case 'S': {
    getchar();
    save_password();
    return false;
  }

  case 'U': {
    update_password();
    return false;
  }

  case 'V': {
    view_password();
    return false;
  }

  case 'D': {
    boolean has_emails = list_emails();

    if (!has_emails) {
      printf("\n\nNo Emails to Delete\n\n");
      return false;
    }

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
