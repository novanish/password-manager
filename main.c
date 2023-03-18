#include "performActions.c"
#include "printActionKeys.c"

int main() {
  char action;

  printf("========================================\n");
  printf("            PASSWORD MANAGER\n");
  printf("========================================\n");

  do {
    print_action_keys();
    scanf(" %c[^\n]", &action);
  } while (!perform_actions(action));

  printf("\nTerminating the program......\n");

  return 0;
}
