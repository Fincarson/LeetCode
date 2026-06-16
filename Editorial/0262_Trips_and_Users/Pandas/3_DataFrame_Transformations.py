import pandas as pd

def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Initial Check
    if trips.empty or users.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])

    # Step 2: Date-based Filtering
    filtered_trips = trips[trips["request_at"].between("2013-10-01", "2013-10-03")]

    # Step 3: Merge with Non-Banned Clients
    trips_with_clients = filtered_trips.merge(
        users.loc[users["banned"] == "No", ["users_id"]],
        left_on="client_id",
        right_on="users_id",
        how="inner",
    )

    # Step 4: Merge with Non-Banned Drivers
    trip_status = trips_with_clients.merge(
        users.loc[users["banned"] == "No", ["users_id"]],
        left_on="driver_id",
        right_on="users_id",
        how="inner",
    )

    # Step 5: Calculate Day-wise Cancellation Rate
    result = trip_status.groupby("request_at").apply(
        lambda group: pd.Series(
            {"Cancellation Rate": round(
                 (group["status"] != "completed").sum() / len(group), 2
                 )
             }
        )
    )

    # Step 6: Format and Return the Result
    if result.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])
    else:
        return result.reset_index().rename(columns={"request_at": "Day"})
