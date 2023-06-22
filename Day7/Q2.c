#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convertToUpperCase(FILE *source, FILE *destination) {
    char ch;

    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }
}

void convertToLowerCase(FILE *source, FILE *destination) {
    char ch;

    while ((ch = fgetc(source)) != EOF) {
        fputc(tolower(ch), destination);
    }
}

void convertToSentenceCase(FILE *source, FILE *destination) {
    char ch;
    int isFirstCharacter = 1;

    while ((ch = fgetc(source)) != EOF) {
        if (isFirstCharacter) {
            fputc(toupper(ch), destination);
            isFirstCharacter = 0;
        } else {
            fputc(tolower(ch), destination);
            if (ch == '.' || ch == '?' || ch == '!') {
                isFirstCharacter = 1;
            }
        }
    }
}

void copyFile(FILE *source, FILE *destination) {
    char ch;

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp -u/-l/-s source_file destination_file\n");
        return 1;
    }

    FILE *sourceFile, *destinationFile;
    char *option = argv[1];
    char *sourceFileName = argv[2];
    char *destinationFileName = argv[3];

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Unable to create destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (strcmp(option, "-u") == 0) {
        convertToUpperCase(sourceFile, destinationFile);
        printf("File copied and converted to upper case successfully.\n");
    } else if (strcmp(option, "-l") == 0) {
        convertToLowerCase(sourceFile, destinationFile);
        printf("File copied and converted to lower case successfully.\n");
    } else if (strcmp(option, "-s") == 0) {
        convertToSentenceCase(sourceFile, destinationFile);
        printf("File copied and converted to sentence case successfully.\n");
    } else {
        copyFile(sourceFile, destinationFile);
        printf("File copied successfully.\n");
    }

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
