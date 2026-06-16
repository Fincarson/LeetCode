import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Find the earliest event_date for each player
    min_event_dates = activity.groupby('player_id')['event_date'].min().reset_index()
    
    # Step 2: Merge the earliest event_dates with the original dataset to get the device_ids for those dates
    result = pd.merge(activity, min_event_dates, on=['player_id', 'event_date'])
    
    # Step 3: Keep only the required columns in the result
    result = result[['player_id', 'device_id']]
    
    # Step 4: Return the result
    return result
