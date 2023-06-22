#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[3];
    float temperature;
    int humidity;
    int light;
    char time[9];
};

void extractData(FILE *file, struct LogEntry logEntries[], int *entryCount) {
    char line[100];
    char *token;

    *entryCount = 0;
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        
        logEntries[*entryCount].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[*entryCount].sensorNo, token);

        token = strtok(NULL, ",");
        logEntries[*entryCount].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[*entryCount].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[*entryCount].light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[*entryCount].time, token);

        (*entryCount)++;
    }
}

void displayData(struct LogEntry logEntries[], int entryCount) {
    printf("Log Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry No: %d\n", logEntries[i].entryNo);
        printf("Sensor No: %s\n", logEntries[i].sensorNo);
        printf("Temperature: %.1f\n", logEntries[i].temperature);
        printf("Humidity: %d\n", logEntries[i].humidity);
        printf("Light: %d\n", logEntries[i].light);
        printf("Time: %s\n", logEntries[i].time);
        printf("-------------------------------\n");
    }
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    struct LogEntry logEntries[MAX_ENTRIES];
    int entryCount;

    extractData(file, logEntries, &entryCount);

    displayData(logEntries, entryCount);

    fclose(file);

    return 0;
}
