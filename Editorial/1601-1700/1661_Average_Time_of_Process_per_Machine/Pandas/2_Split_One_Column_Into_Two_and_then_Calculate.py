import pandas as pd

def get_average_time(activity: pd.DataFrame) -> pd.DataFrame:
    
    start_df = activity[activity['activity_type'] == 'start']
    
    end_df = activity[activity['activity_type'] == 'end']
    
    merge_df = end_df.merge(start_df, on = ['machine_id', 'process_id'])
    
    df = merge_df.assign(processing_time = merge_df['timestamp_x'] - merge_df['timestamp_y']).groupby(['machine_id'], as_index=False)['processing_time'].mean().round(3)

    return df
