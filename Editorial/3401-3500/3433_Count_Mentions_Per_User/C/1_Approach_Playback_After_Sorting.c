typedef struct {
    char type[8];
    int timestamp;
    char target[512];
} Event;

int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    if (e1->timestamp != e2->timestamp) {
        return e1->timestamp - e2->timestamp;
    }

    return strcmp(e1->type, "OFFLINE") == 0 ? -1 : 1;
}

int* countMentions(int numberOfUsers, char*** events, int eventsSize,
                   int* eventsColSize, int* returnSize) {
    Event* eventArr = (Event*)calloc(eventsSize, sizeof(Event));
    for (int i = 0; i < eventsSize; i++) {
        strcpy(eventArr[i].type, events[i][0]);
        eventArr[i].timestamp = atoi(events[i][1]);
        strcpy(eventArr[i].target, events[i][2]);
    }

    qsort(eventArr, eventsSize, sizeof(Event), compareEvents);
    int* count = (int*)calloc(numberOfUsers, sizeof(int));
    int* nextOnlineTime = (int*)calloc(numberOfUsers, sizeof(int));

    for (int i = 0; i < eventsSize; i++) {
        int curTime = eventArr[i].timestamp;
        char* type = eventArr[i].type;
        char* target = eventArr[i].target;
        if (strcmp(type, "MESSAGE") == 0) {
            if (strcmp(target, "ALL") == 0) {
                for (int j = 0; j < numberOfUsers; j++) {
                    count[j]++;
                }
            } else if (strcmp(target, "HERE") == 0) {
                for (int j = 0; j < numberOfUsers; j++) {
                    if (nextOnlineTime[j] <= curTime) {
                        count[j]++;
                    }
                }
            } else {
                char* token = strtok(target, " ");
                while (token != NULL) {
                    int idx = atoi(token + 2);
                    count[idx]++;
                    token = strtok(NULL, " ");
                }
            }
        } else {
            int idx = atoi(target);
            nextOnlineTime[idx] = curTime + 60;
        }
    }

    free(eventArr);
    free(nextOnlineTime);
    *returnSize = numberOfUsers;
    return count;
}
