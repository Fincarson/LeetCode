import pandas as pd

def user_activities(sessions: pd.DataFrame) -> pd.DataFrame:
    df = sessions.sort_values(
        ["user_id", "session_type", "session_start", "session_end"]
    )
    df = df.loc[
        (df["user_id"] == df["user_id"].shift(-1))
        & (df["session_type"] == df["session_type"].shift(-1))
        & (
            df["session_end"]
            >= df["session_start"].shift(-1) - pd.Timedelta(12, unit="H")
        )
    ]
    return df[["user_id"]].drop_duplicates()
