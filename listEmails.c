#include "savePassword.c"
#include <stdio.h>

boolean list_emails() {
  struct Info current_info;

  FILE *fp = fopen(FILE_NAME, "rb");

  int count = 0;

  if (fp == NULL) {
    printf("\n\nNo Emails to list\n\n");
    return false;
  }

  while (fread(&current_info, sizeof(struct Info), 1, fp)) {
    printf("\nApp name:- %s", current_info.app_name);
    printf("Email:- %s\n", current_info.email);
    count++;
  }

  fclose(fp);

  if (count == 0)
    printf("\n\nNo Emails to list\n\n");

  return count != 0;
}