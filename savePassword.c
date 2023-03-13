#include "fileName.c"
#include "generatePassword.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Info {
  char app_name[32];
  char email[52];
  char password[52];
};

void save_password() {
  struct Info info;
  int should_generate;
  FILE *fp = fopen(FILE_NAME, "ab");

  if (fp == NULL) {
    printf("ERROR!!! While opening file to save password");
    exit(0);
  }

  printf("\n\nFill up the form to save your password and email\n");

  getchar();
  printf("App name (max char 30) => ");
  fgets(info.app_name, sizeof(info.app_name), stdin);
  //   strupr(info.app_name);

  printf("Email (max char 50) => ");
  fgets(info.email, sizeof(info.email), stdin);
  //   strlwr(info.email);

  printf("You want to Generate or type password (1/0) => ");
  scanf("%d", &should_generate);

  if (should_generate) {
    char *password;
    generate_password(&password);
    printf("\nGenerated Password:- %s\n", password);
    strcpy(info.password, password);
    free(password);
  } else {
    getchar();
    printf("Password (max char 50) => ");
    fgets(info.password, sizeof(info.password), stdin);
  }

  printf("Enter a key to encode your password (key shouldn't be less than zero "
         "and greater than 100)=> ");
  int key = get_int();

  char *encode_password = malloc(strlen(info.password));
  strcpy(encode_password, info.password);
  encoder(key, &encode_password);
  strcpy(info.password, encode_password);
  free(encode_password);

  fwrite(&info, sizeof(struct Info), 1, fp);

  fclose(fp);
}
