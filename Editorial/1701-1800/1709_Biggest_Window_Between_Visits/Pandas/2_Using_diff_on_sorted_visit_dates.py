import pandas as pd

def biggest_window(user_visits: pd.DataFrame) -> pd.DataFrame:

    today = user_visits[['user_id']].drop_duplicates()

    today['visit_date'] = pd.to_datetime('2021-01-01')

    df = pd.concat([user_visits, today]).sort_values(by=['user_id', 'visit_date'])

    df['window'] = df.groupby('user_id').visit_date.diff().dt.days

    biggest_window = df.groupby(['user_id'], as_index=False).window.max()

    return biggest_window.rename(columns = {'window': 'biggest_window'})
