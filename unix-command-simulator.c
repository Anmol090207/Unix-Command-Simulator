#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <io.h>
#include <windows.h>

/* ---------------- pwd ---------------- */
void do_pwd(void)
{
    char buf[512];
    if (_getcwd(buf, sizeof(buf)) == NULL) {
        perror("pwd");
    } else {
        printf("%s\n", buf);
    }
}

/* ---------------- ls ---------------- */
void do_ls(void)
{
    char path[256];

    printf("Enter path (press enter for current dir): ");
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = '\0';

    if (strlen(path) == 0) {
        strcpy(path, "*");
    } else {
        strcat(path, "\\*");
    }

    WIN32_FIND_DATA fd;
    HANDLE h = FindFirstFile(path, &fd);

    if (h == INVALID_HANDLE_VALUE) {
        perror("ls");
        return;
    }

    do {
        if (strcmp(fd.cFileName, ".") != 0 &&
            strcmp(fd.cFileName, "..") != 0) {

            if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                printf("[DIR] %s\n", fd.cFileName);
            else
                printf("      %s\n", fd.cFileName);
        }
    } while (FindNextFile(h, &fd));

    FindClose(h);
}

/* ---------------- mkdir ---------------- */
void do_mkdir(void)
{
    char name[256];

    printf("Enter directory name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    if (strlen(name) == 0) {
        printf("mkdir: missing operand\n");
        return;
    }

    if (_mkdir(name) != 0) {
        perror("mkdir");
    } else {
        printf("Directory created: %s\n", name);
    }
}

/* ---------------- rm ---------------- */
void do_rm(void)
{
    char name[256];

    printf("Enter file/directory to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    if (strlen(name) == 0) {
        printf("rm: missing operand\n");
        return;
    }

    if (_unlink(name) == 0) {
        printf("Removed file: %s\n", name);
    }
    else if (_rmdir(name) == 0) {
        printf("Removed directory: %s\n", name);
    }
    else {
        perror("rm");
    }
}

/* ---------------- cd ---------------- */
void do_cd(void)
{
    char path[256];

    printf("Enter directory path: ");
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = '\0';

    if (strlen(path) == 0) {
        printf("cd: missing operand\n");
        return;
    }

    if (_chdir(path) != 0) {
        perror("cd");
    } else {
        printf("Changed directory to: %s\n", path);
    }
}

/* ---------------- menu ---------------- */
void show_menu(void)
{
    char cwd[512];
    _getcwd(cwd, sizeof(cwd));

    printf("\n================================\n");
    printf(" UNIX Command Simulator (Windows)\n");
    printf(" Current Dir: %s\n", cwd);
    printf("================================\n");
    printf("1. pwd\n");
    printf("2. ls\n");
    printf("3. mkdir\n");
    printf("4. rm\n");
    printf("5. cd\n");
    printf("6. exit\n");
    printf("--------------------------------\n");
    printf("Enter your choice: ");
}

/* ---------------- main ---------------- */
int main(void)
{
    char input[16];
    int running = 1;

    while (running) {
        show_menu();

        fgets(input, sizeof(input), stdin);
        int choice = atoi(input);

        printf("\n");

        switch (choice) {
            case 1: do_pwd(); break;
            case 2: do_ls(); break;
            case 3: do_mkdir(); break;
            case 4: do_rm(); break;
            case 5: do_cd(); break;
            case 6:
                printf("Exiting...\n");
                running = 0;
                break;
            default:
                printf("Invalid choice. Please enter 1-6.\n");
        }
    }

    return 0;
}
