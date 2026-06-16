import pandas as pd

def same_day_calls(calls: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Create a unified view of calls
    # Each call is represented twice, from both caller's and recipient's perspectives.
    unified_calls = pd.concat(
        [
            calls,
            calls.rename(
                columns={"caller_id": "recipient_id", "recipient_id": "caller_id"}
            ),
        ],
        ignore_index=True,
    )

    # Step 2: Extract the date part from call_time to identify the call day
    unified_calls["call_day"] = unified_calls["call_time"].dt.date

    # Step 3: Identify the first (earliest) and last (latest) calls of each day for each user
    # Group by call_day and caller_id, then find the index of the min/max call_time
    first_call_indices = unified_calls.groupby(["call_day", "caller_id"])[
        "call_time"
    ].idxmin()
    last_call_indices = unified_calls.groupby(["call_day", "caller_id"])[
        "call_time"
    ].idxmax()

    first_calls = unified_calls.loc[first_call_indices]
    last_calls = unified_calls.loc[last_call_indices]

    # Step 4: Merge first and last calls to find users whose first and last calls are with the same recipient
    merged_calls = first_calls.merge(
        last_calls, on=["caller_id", "recipient_id", "call_day"]
    )

    # Step 5: Prepare the final output
    # Select unique caller_id and rename to user_id
    result = (
        merged_calls[["caller_id"]]
        .rename(columns={"caller_id": "user_id"})
        .drop_duplicates()
    )

    return result
