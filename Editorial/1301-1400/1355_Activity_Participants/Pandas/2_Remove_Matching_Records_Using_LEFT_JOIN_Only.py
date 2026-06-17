import pandas as pd
​
def activity_participants(friends: pd.DataFrame, activities: pd.DataFrame) -> pd.DataFrame:
    df = friends.groupby('activity', as_index=False)['id'].count()
    
    max_min = df.agg({'id': ['max', 'min']})
    
    df = df.merge(max_min, on='id', how='left', indicator=True)
    
    df2= df[df['_merge']=='left_only'][['activity']]
   
    return df2
