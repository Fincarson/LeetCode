import pandas as pd
​
def activity_participants(friends: pd.DataFrame, activities: pd.DataFrame) -> pd.DataFrame:
    df = friends.groupby('activity', as_index=False)['id'].count()
    
    max_min = df.agg({'id': ['max', 'min']})
    
    df = df[~df['id'].isin(max_min['id'])][['activity']]
    
    return df
