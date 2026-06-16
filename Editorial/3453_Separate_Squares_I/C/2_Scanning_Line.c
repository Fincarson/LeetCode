typedef struct {
    int y;
    int l;
    int delta;
} Event;

int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    return e1->y - e2->y;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    long long totalArea = 0;
    Event* events = malloc(2 * squaresSize * sizeof(Event));
    int eventCount = 0;

    for (int i = 0; i < squaresSize; i++) {
        int y = squares[i][1];
        int l = squares[i][2];
        totalArea += (long long)l * l;
        events[eventCount++] = (Event){y, l, 1};
        events[eventCount++] = (Event){y + l, l, -1};
    }

    // sort by y-coordinate
    qsort(events, eventCount, sizeof(Event), compareEvents);

    double coveredWidth =
        0.0;  // sum of all bottom edges under the current scanning line
    double currArea = 0.0;    // current cumulative area
    double prevHeight = 0.0;  // height of the previous scanning line

    for (int i = 0; i < eventCount; i++) {
        int y = events[i].y;
        int l = events[i].l;
        int delta = events[i].delta;

        int diff = y - (int)prevHeight;
        // additional area between two scanning lines
        double area = coveredWidth * diff;
        // if this part of the area exceeds more than half of the total area
        if (2LL * (currArea + area) >= totalArea) {
            double result = prevHeight +
                            (totalArea - 2.0 * currArea) / (2.0 * coveredWidth);
            free(events);
            return result;
        }
        // update width: add width at the start event, subtract width at the end
        // event
        coveredWidth += delta * l;
        currArea += area;
        prevHeight = y;
    }

    free(events);
    return 0.0;
}
