#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void differenceBetweenTimePeriod(struct Time t1, struct Time t2, struct Time *diff) {
    if (t2.seconds > t1.seconds) {
        --t1.minutes;
        t1.seconds += 60;
    }
    
    diff->seconds = t1.seconds - t2.seconds;
    
    if (t2.minutes > t1.minutes) {
        --t1.hours;
        t1.minutes += 60;
    }
    
    diff->minutes = t1.minutes - t2.minutes;
    diff->hours = t1.hours - t2.hours;
}

int main() {
    struct Time startTime, endTime, difference;
    
    printf("Enter start time:\n");
    printf("Hours: ");
    scanf("%d", &(startTime.hours));
    printf("Minutes: ");
    scanf("%d", &(startTime.minutes));
    printf("Seconds: ");
    scanf("%d", &(startTime.seconds));
    
    printf("Enter end time:\n");
    printf("Hours: ");
    scanf("%d", &(endTime.hours));
    printf("Minutes: ");
    scanf("%d", &(endTime.minutes));
    printf("Seconds: ");
    scanf("%d", &(endTime.seconds));
    
    differenceBetweenTimePeriod(startTime, endTime, &difference);
    
    printf("Time difference: %d:%d:%d\n", difference.hours, difference.minutes, difference.seconds);
    
    return 0;
}
