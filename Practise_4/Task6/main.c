#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    char hostname[256];
    struct utsname uname_data;

    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Computer Name: %s\n", hostname);
    } else {
        perror("Error getting host name");
    }

    if (uname(&uname_data) == 0) {
        printf("Operating System: %s\n", uname_data.sysname);
        printf("Node Name: %s\n", uname_data.nodename);
        printf("OS Version: %s\n", uname_data.release);
        printf("OS Version: %s\n", uname_data.version);
        printf("Architecture: %s\n", uname_data.machine);
    } else {
        perror("Error getting computer information");
    }

    return 0;
}
