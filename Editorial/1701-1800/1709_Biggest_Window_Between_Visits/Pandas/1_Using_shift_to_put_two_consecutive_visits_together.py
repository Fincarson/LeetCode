import pandas as pd

def biggest_window(user_visits: pd.DataFrame) -> pd.DataFrame:

    user_visits.sort_values(by=['user_id', 'visit_date'], inplace=True)

    user_visits['next_visit'] = user_visits.groupby(['user_id']).shift(periods=-1, fill_value='2021-01-01')

    user_visits['window'] = (user_visits.next_visit - user_visits.visit_date).dt.days

    biggest_window = user_visits.groupby(['user_id'], as_index=False).window.max()

    return biggest_window.rename(columns = {'window': 'biggest_window'})
