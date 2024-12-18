#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <argument>\n", argv[0]);
        return 1;
    }

    FILE *secret = fopen("/home/dojo/Desktop/passwd", "rt");
    if (secret == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[32];
    if (fgets(buffer, sizeof(buffer), secret) == NULL) {
        perror("Error reading file");
        fclose(secret);
        return 1;
    }

    printf("%s\n", argv[1]);

    fclose(secret);
    return 0;
}
