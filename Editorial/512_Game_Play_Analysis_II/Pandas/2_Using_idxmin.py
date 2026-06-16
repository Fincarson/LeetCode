import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Find the index of the first login date for each player
    idx = activity.groupby('player_id')['event_date'].idxmin()
    
    # Step 2: Use the index to get the corresponding rows from the original DataFrame
    result = activity.loc[idx][['player_id', 'device_id']]

    # Step 3: Return the result
    return result
