
import pandas as pd

def active_businesses(events: pd.DataFrame) -> pd.DataFrame:

    df = events.groupby('event_type', as_index=False).apply(lambda x: x[x['occurrences'] > x['occurrences'].mean()])

    df = df.groupby('business_id', as_index=False).filter(lambda x: x['business_id'].count() > 1)

    return df[['business_id']].drop_duplicates()
