import pandas as pd

def active_businesses(events: pd.DataFrame) -> pd.DataFrame:

    avg = events.groupby('event_type', as_index=False)['occurrences'].mean()

    df = events.merge(avg, on='event_type')

    df = df[df.occurrences_x - df.occurrences_y > 0]

    active_business = df.groupby('business_id', as_index=False)['event_type'].count()

    return active_business[active_business.event_type > 1][['business_id']]
