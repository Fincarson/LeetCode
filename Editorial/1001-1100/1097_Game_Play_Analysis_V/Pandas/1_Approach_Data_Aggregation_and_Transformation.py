import pandas as pd

def custom_round(x, decimals=2):
    offset = 10 ** decimals
    return int(x * offset + 0.5) / offset

def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:

    # Find the minimum event_date for each player, which is the install date
    install_dates = activity.groupby("player_id")["event_date"].min().reset_index()
    install_dates.columns = ["player_id", "install_dt"]

    # Merge the original DataFrame with the install dates to find the next day's activity
    next_day_activity = pd.merge(
        install_dates, activity, on="player_id"
    )
    next_day_activity = next_day_activity[
        next_day_activity["event_date"]
        == next_day_activity["install_dt"] + pd.Timedelta(days=1)
    ]

    # Group by install date and calculate installs and Day 1 Retention
    result = install_dates.groupby("install_dt").size().reset_index(name="installs")
    day1_retention = (
        next_day_activity.groupby("install_dt")
        .size()
        .reset_index(name="next_day_count")
    )

    result = pd.merge(result, day1_retention, on="install_dt", how="left")
    result["next_day_count"].fillna(0, inplace=True)

    # Using the custom round function
    result["Day1_retention"] = result["next_day_count"] / result["installs"]
    result["Day1_retention"] = result["Day1_retention"].apply(
        lambda x: custom_round(x, 2)
    )

    # Keep only the columns install_dt, installs, and Day1_retention
    result = result[["install_dt", "installs", "Day1_retention"]]

    return result
