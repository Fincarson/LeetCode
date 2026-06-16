import pandas as pd

def longest_winning_streak(matches: pd.DataFrame) -> pd.DataFrame:
    matches = matches.sort_values(by=["player_id", "match_day"])
    matches["not_win"] = matches["result"].apply(lambda x: 0 if x == "Win" else 1)
    matches["group_id"] = matches.groupby("player_id")["not_win"].cumsum()
    df = (
        matches.groupby(["player_id", "group_id"])
        .agg(streak=("result", lambda x: (x == "Win").sum()))
        .reset_index()
    )
    df = df.groupby("player_id")["streak"].max().reset_index()

    return df[["player_id", "streak"]].rename(columns={"streak": "longest_streak"})
