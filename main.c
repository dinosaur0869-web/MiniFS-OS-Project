#include <stdio.h>
#include <string.h>
#include "command.h"
#include "fs.h"

int main() {
  fs_init();
  char input[256];

  printf("Welcome to MiniFS(by MCU OS class team 8)\n");
  
  while (1) {
        printf("MiniFS > ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("MiniFS shutdown.\n");
            break;
        }

        execute_command(input);
    }

  return 0;
}
