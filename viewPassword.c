#include "deletePassword.c"

void view_password() {
  struct Info current_info;
  char email_or_app_name[52];
  boolean hasFound = false;
  boolean matched;

  boolean has_emails = list_emails();

  if (!has_emails) {
    printf("\n\nNo emails and password to view\n\n");
    return;
  }

  getchar();
  printf("\n\nEnter the App name or Email whose password you want to see (max "
         "char 50) => ");
  fgets(email_or_app_name, sizeof(email_or_app_name), stdin);

  FILE *fp = fopen(FILE_NAME, "rb");

  if (fp == NULL) {
    printf("\nNo Emails!!\n");
    return;
  }

  while (fread(&current_info, sizeof(current_info), 1, fp)) {
    matched = strcmp(current_info.email, email_or_app_name) == 0 ||
              strcmp(current_info.app_name, email_or_app_name) == 0;

    if (matched) {
      hasFound = true;
      printf("\nApp name:- %s", current_info.app_name);
      printf("Email:- %s", current_info.email);
      printf("Enter a key to that is used to encode your password for above "
             "email => ");
      int key = get_int();

      char *decoded_password = malloc(strlen(current_info.password));

      strcpy(decoded_password, current_info.password);

      decoder(key, &decoded_password);
      printf("Password:- %s\n\n", decoded_password);

      free(decoded_password);
    }
  }

  if (!hasFound)
    printf("\nThere is no email or app name in record %s\n", email_or_app_name);

  fclose(fp);
}