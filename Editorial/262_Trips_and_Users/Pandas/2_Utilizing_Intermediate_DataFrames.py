import pandas as pd

def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Data Verification
    # Check if either `trips` or `users` DataFrames are empty.
    # If so, return a DataFrame with columns "Day" and "Cancellation Rate" without any data.
    if trips.empty or users.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])

    # Step 2: Isolating Banned Users
    # Using boolean indexing on the `users` DataFrame, extract the IDs (`users_id`) of users who are banned.
    banned_users_ids = users[users["banned"] == "Yes"]["users_id"]

    # Step 3: Filtering Relevant Trip Data
    # Remove rows from `trips` DataFrame that have `client_id` or `driver_id` matching the IDs of banned users.
    # Retain rows in the `trips` DataFrame that have `request_at` dates within the range of '2013-10-01' to '2013-10-03'.
    selected_trips = trips[
        (~trips["client_id"].isin(banned_users_ids))
        & (~trips["driver_id"].isin(banned_users_ids))
        & (trips["request_at"].between("2013-10-01", "2013-10-03"))
    ]

    # Step 4: Aggregating Data
    # Group the data in the `selected_trips` DataFrame based on the `request_at` column.
    # For each group, calculate the cancellation rate by determining the ratio of non-completed trips to the total number of trips, rounding to two decimal places.
    aggregated_result = selected_trips.groupby("request_at").apply(
        lambda group: pd.Series(
            {
                "Cancellation Rate": round(
                    (group["status"] != "completed").sum() / len(group), 2
                )
            }
        )
    )

    # Step 5: Result Compilation
    # If the `aggregated_result` DataFrame isn't empty, reset its index and rename the `request_at` column to 'Date'.
    # If it's empty, return a DataFrame with columns "Date" and "Cancellation Rate" without any data.
    if aggregated_result.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])
    else:
        return aggregated_result.reset_index().rename(columns={"request_at": "Day"})
