#ifndef COMMAND_H
#define COMMAND_H

void execute_command(char *input);

void cmd_ls(char *path);
void cmd_mkdir(char *path);
void cmd_touch(char *path);

#endif
