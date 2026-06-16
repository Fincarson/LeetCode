import pandas as pd

def leetflex_banned_accnts(log_info: pd.DataFrame) -> pd.DataFrame:
    # Approach: .merge(cross) and filter
    df = log_info.merge(log_info, how="cross")

    # Filter rows that have same account_id, different ip_address, and overlapped logged in times.
    df = df[df['account_id_x'] == df['account_id_y']]
    df = df[df['ip_address_x'] != df['ip_address_y']]
    df = df[(df['login_x'] <= df['logout_y']) & (df['login_y'] <= df['logout_x'])]
    
    # Drop duplicates on account_id
    df = df.drop_duplicates('account_id_x')

    # Rename output column
    df = df.rename(columns={'account_id_x': 'account_id'})

    return df[['account_id']]
