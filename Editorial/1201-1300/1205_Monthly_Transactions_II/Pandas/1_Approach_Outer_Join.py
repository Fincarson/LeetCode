import pandas as pd
​
def monthly_transactions(transactions: pd.DataFrame, chargebacks: pd.DataFrame) -> pd.DataFrame:

    df = transactions.merge(chargebacks, left_on='id', right_on='trans_id', how='left')

    df['month_chargeback'] = df['trans_date_y'].dt.strftime('%Y-%m')

    df['month_transaction'] = df['trans_date_x'].dt.strftime('%Y-%m')

    df1 = df[df['state'] == 'approved'].groupby(
        ['month_transaction', 'country'], as_index=False
        ).agg(
            approved_count=('amount', 'count'),
            approved_amount=('amount', 'sum')
        ).rename(columns={'month_transaction': 'month'})

    df2 = df.groupby(
        ["month_chargeback", "country"], as_index=False
        ).agg(
            chargeback_count=('amount', 'count'), 
            chargeback_amount=('amount', 'sum')
        ).rename(columns={'month_chargeback': 'month'})
        
    df3 = df1.merge(df2, how='outer', on=['month', 'country']).fillna(0)

    return df3
