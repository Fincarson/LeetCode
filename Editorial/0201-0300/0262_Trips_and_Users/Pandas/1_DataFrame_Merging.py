import pandas as pd

def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:

    # Step 1: Preliminary Check
    if trips.empty or users.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])

    # Step 2: Prepare Data for Client Merge
    renamed_users_for_clients = users.rename(
        columns={"users_id": "client_id", "banned": "client_banned"}
    )

    # Step 3: Client Merge
    trips_with_clients = trips.merge(
        renamed_users_for_clients, on="client_id", how="left"
    )

    # Step 4: Prepare Data for Driver Merge
    renamed_users_for_drivers = users.rename(
        columns={"users_id": "driver_id", "banned": "driver_banned"}
    )

    # Step 5: Driver Merge
    full_trips = trips_with_clients.merge(
        renamed_users_for_drivers, on="driver_id", how="left"
    )

    # Step 6: Filtering
    filtered_trips = full_trips[
        (full_trips["client_banned"] == "No")
        & (full_trips["driver_banned"] == "No")
        & (full_trips["request_at"].between("2013-10-01", "2013-10-03"))
    ]

    # Step 7: Calculate Cancellation Rate
    result = filtered_trips.groupby("request_at").apply(
        lambda group: pd.Series(
            {
                "Cancellation Rate": round(
                    (group["status"] != "completed").sum() / len(group), 2
                )
            }
        )
    )

    # Step 8: Result Presentation
    if result.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])
    else:
        return result.reset_index().rename(columns={"request_at": "Day"})
