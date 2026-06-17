import pandas as pd

def number_of_passengers(buses: pd.DataFrame, passengers: pd.DataFrame) -> pd.DataFrame:
    # Sort buses by their arrival times to process in chronological order
    buses_sorted = buses.sort_values(by='arrival_time')

    # Iterate over each bus to calculate the number of passengers it can pick up
    for i, bus in buses_sorted.iterrows():
        # For the first bus, count all passengers arrived up to its arrival time
        if i == 0:
            available_passengers = passengers[passengers['arrival_time'] <= bus.arrival_time].shape[0]
        else:
            # For subsequent buses, count passengers arrived after the previous bus and before this bus
            arrived_after_previous_bus = passengers['arrival_time'] > buses_sorted.at[i - 1, 'arrival_time']
            arrived_before_current_bus = passengers['arrival_time'] <= bus.arrival_time
            available_passengers = passengers[arrived_after_previous_bus & arrived_before_current_bus].shape[0]
            available_passengers += buses_sorted.at[i - 1, 'leftover']

        # Determine how many passengers board this bus based on its capacity
        if available_passengers <= bus.capacity:
            buses_sorted.at[i, 'passengers_cnt'] = available_passengers
            buses_sorted.at[i, 'leftover'] = 0
        else:
            buses_sorted.at[i, 'passengers_cnt'] = bus.capacity
            buses_sorted.at[i, 'leftover'] = available_passengers - bus.capacity

    # Return the result with bus ID and the count of passengers picked up by each bus
    return buses_sorted[['bus_id', 'passengers_cnt']].sort_values(by='bus_id')
