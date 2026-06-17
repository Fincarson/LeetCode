import pandas as pd

def get_total_distance(users: pd.DataFrame, rides: pd.DataFrame) -> pd.DataFrame:

    total_distance = rides.groupby('user_id', as_index=False).distance.sum()

    df = users.merge(total_distance, on='user_id', how='left').fillna(0).sort_values('user_id').rename(columns={'distance': 'traveled distance'})

    return df
