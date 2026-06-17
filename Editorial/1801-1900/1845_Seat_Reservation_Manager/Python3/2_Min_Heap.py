class SeatManager:
    def __init__(self, n):
        # Set marker to the first unreserved seat.
        self.marker = 1

        # Min heap to store all unreserved seats.
        self.available_seats = []

    def reserve(self):
        # If min-heap has any element in it, then,
        # get the smallest-numbered unreserved seat from the min heap.
        if self.available_seats:
            seat_number = heapq.heappop(self.available_seats)
            return seat_number

        # Otherwise, the marker points to the smallest-numbered seat.
        seat_number = self.marker
        self.marker += 1
        return seat_number

    def unreserve(self, seat_number):
        # Push unreserved seat in the min heap.
        heapq.heappush(self.available_seats, seat_number)
