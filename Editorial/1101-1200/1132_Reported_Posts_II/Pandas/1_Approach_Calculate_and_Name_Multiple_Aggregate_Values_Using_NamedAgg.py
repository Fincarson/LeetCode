import pandas as pd
​
def reported_posts(actions: pd.DataFrame, removals: pd.DataFrame) -> pd.DataFrame:

    spam = actions[actions['extra'] == 'spam'].drop_duplicates(['action_date', 'post_id'])

    removed_spam = spam.merge(removals, on='post_id', how='left')

    df = removed_spam.groupby("action_date", as_index=False).agg(
        removed_spam=('remove_date', 'count'), 
        total_spam=('remove_date', 'size')
    )
    
    df = df.assign(average_daily_percent = df['removed_spam']*100/df['total_spam'])

    avg = df.agg({'average_daily_percent': ['mean']}).round(2)

    return avg
