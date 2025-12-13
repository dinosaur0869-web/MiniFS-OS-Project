#include <stdio.h>
#include <string.h>

int main() {
  char input[256];

  printf("Welcome to MiniFS(by MCU OS class team 8)\n");
  
  while (1) {
    printf("MiniFS > ");
    if (!fgets(input, sizeof(input), stdin)) break;

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "exit") == 0) {
      printf("MiniFS shutdown.\n");
      break;
    }

    printf("You entered: %s\n", input);
  }

  return 0;
}
