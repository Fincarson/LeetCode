import pandas as pd

def waitlist_analysis(flights: pd.DataFrame, passengers: pd.DataFrame) -> pd.DataFrame:
    passengers = (
        passengers.groupby(by="flight_id")
        .agg(cnt=("passenger_id", "nunique"))
        .reset_index()
    )
    passengers = flights.merge(passengers, on="flight_id", how="left").fillna(0)
    passengers["booked_cnt"] = passengers.apply(lambda row: min(row["cnt"], row["capacity"]), axis=1)
    passengers["waitlist_cnt"] = passengers["cnt"] - passengers["booked_cnt"]
    return passengers.drop(["cnt", "capacity"], axis=1).sort_values(by="flight_id")
