#include "viewPassword.c"
#include <stdio.h>

void update_password() {
  boolean has_emails = list_emails();

  if (!has_emails) {
    printf("\n\nNo emails to update\n\n");
    return;
  }

  delete_password();
  save_password();
}