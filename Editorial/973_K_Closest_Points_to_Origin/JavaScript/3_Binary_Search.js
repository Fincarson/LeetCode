var kClosest = function(points, k) {
    // Precompute the Euclidean distance for each point
    let distances = points.map(euclideanDistance)
    // Create a reference array of point indices
    let remaining = points.map((_, i) => i)
    // Define the initial binary search range
    let low = 0, high = Math.max(...distances)
    
    // Perform a binary search of the distances
    // to find the k closest points
    let closest = []
    while (k) {
        let mid = low + (high - low) / 2
        let [closer, farther] = splitDistances(remaining, distances, mid)
        if (closer.length > k) {
            // If more than k points are in the closer distances
            // then discard the farther points and continue
            remaining = closer
            high = mid
        } else {
            // Add the closer points to the answer array and keep
            // searching the farther distances for the remaining points
            k -= closer.length
            closest.push(...closer)
            remaining = farther
            low = mid
        }
    }
    
    // Return the k closest points using the reference indices
    return closest.map(i => points[i])
};

var splitDistances = function(remaining, distances, mid) {
    // Split the distances around the midpoint
    // and return them in separate arrays
    let closer = [], farther = []
    for (let index of remaining) {
        if (distances[index] <= mid) {
            closer.push(index)
        } else {
            farther.push(index)
        }
    }
    return [closer, farther]
};

// Calculate and return the squared Euclidean distance
const euclideanDistance = ([x,y]) => x ** 2 + y ** 2
