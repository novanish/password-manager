#include "listEmails.c"
#include <stdio.h>

void delete_password() {
  struct Info current_info;
  char email_or_app_name[52];
  boolean has_found = false;
  boolean matched;

  getchar();
  printf("\n\nEnter App name or Email (max char 50) => ");
  fgets(email_or_app_name, sizeof(email_or_app_name), stdin);

  FILE *fp = fopen(FILE_NAME, READ);
  FILE *temp = fopen(TEMP_FILE_NAME, WRITE);

  if (temp == NULL) {
    printf("\nError while deleting\n");
    fp != NULL ? fclose(fp) : (1);
    return;
  }

  if (fp == NULL) {
    printf("\nNo Emails!!\n");
    fclose(temp);
    return;
  }

  while (fread(&current_info, sizeof(current_info), 1, fp)) {
    matched = strcmp(current_info.email, email_or_app_name) == 0 ||
              strcmp(current_info.app_name, email_or_app_name) == 0;

    if (matched && !has_found) {
      has_found = true;
    } else {
      fwrite(&current_info, sizeof(struct Info), 1, temp);
    }
  }

  if (!has_found)
    printf("\nThere is no email or app name in record %s\n", email_or_app_name);

  fclose(fp);
  fclose(temp);

  remove(FILE_NAME);
  rename(TEMP_FILE_NAME, FILE_NAME);
}