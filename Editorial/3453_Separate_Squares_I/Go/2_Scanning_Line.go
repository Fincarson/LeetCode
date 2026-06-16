func separateSquares(squares [][]int) float64 {
    var totalArea int64 = 0
    type Event struct {
        y     int
        l     int
        delta int
    }
    events := make([]Event, 0, len(squares)*2)
    
    for _, sq := range squares {
        y, l := sq[1], sq[2]
        totalArea += int64(l) * int64(l)
        events = append(events, Event{y, l, 1})
        events = append(events, Event{y + l, l, -1})
    }
    
    // sort by y-coordinate
    sort.Slice(events, func(i, j int) bool {
        return events[i].y < events[j].y
    })
    
    coveredWidth := 0.0  // sum of all bottom edges under the current scanning line
    currArea := 0.0      // current cumulative area
    prevHeight := 0.0    // height of the previous scanning line
    
    for _, event := range events {
        y, l, delta := event.y, event.l, event.delta
        diff := float64(y) - prevHeight
        // additional area between two scanning lines
        area := coveredWidth * diff
        // if this part of the area exceeds more than half of the total area
        if 2.0*(currArea+area) >= float64(totalArea) {
            return prevHeight + (float64(totalArea) - 2.0*currArea) / (2.0 * coveredWidth)
        }
        // update width: add width at the start event, subtract width at the end event
        coveredWidth += float64(delta * l)
        currArea += area
        prevHeight = float64(y)
    }
    
    return 0.0
}
