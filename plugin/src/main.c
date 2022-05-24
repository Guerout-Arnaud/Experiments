#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>


int (**command_list)(void *) = NULL;
void **handle_list = NULL;

// typedef int (*some_func)(char *param);
char *lib_path = "lib/";

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    (void)envp;

    int command_list_len = 0;

    DIR *d = opendir(lib_path);

    if (d == NULL)
    {
        printf("Error opening directory\n");
        return (-1);
    }
    for (struct dirent *dir = readdir(d); dir != NULL; dir = readdir(d))
    {
        int len = strlen(dir->d_name);
        if (len < 7 /*strlen("libA.so")*/) {
            continue;
        }

        printf("EXTENSION: %s\n", &dir->d_name[len-3]);
        if (strncmp(&dir->d_name[len-3], ".so", 3) != 0) {
            continue;
        }

        printf("FILE: %s\n", dir->d_name);

        char *file_path = calloc(strlen(lib_path) + strlen(dir->d_name) + 1, sizeof(*file_path));
        strncpy(file_path, lib_path, strlen(lib_path));
        strncpy(&file_path[strlen(lib_path)], dir->d_name, strlen(dir->d_name));

        handle_list = realloc(handle_list, sizeof(*handle_list) * command_list_len + 1);
        handle_list[command_list_len] = dlopen(file_path, RTLD_LAZY);

        free(file_path);


        command_list = realloc(command_list, sizeof(*command_list) * command_list_len + 1);
        command_list[command_list_len] = dlsym(handle_list[command_list_len], "command");

        command_list_len++;
        // int (*command)(void *) = dlsym(handle, "command");

    }
    closedir(d);

    for (int i = 0; i < command_list_len; i++) {
        command_list[i](NULL);
        dlclose(handle_list[i]);

    }
    return (0);

    // Initialize the shared library.
    // dlopen("libshared.so", RTLD_LAZY);

    // return 0;
}