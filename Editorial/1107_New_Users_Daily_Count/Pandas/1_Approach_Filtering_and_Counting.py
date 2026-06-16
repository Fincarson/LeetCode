import pandas as pd

def new_users_daily_count(traffic: pd.DataFrame) -> pd.DataFrame:

    df = traffic[traffic.activity == 'login'].drop_duplicates()

    first_login = df.groupby('user_id', as_index=False)['activity_date'].min()


    first_login = first_login[
        first_login.activity_date.between(
            pd.to_datetime("2019-06-30") - timedelta(days=90), "2019-06-30"
        )
    ]

    final = first_login.groupby("activity_date", as_index=False)["user_id"].count()

    return final.rename(
        columns={"activity_date": "login_date", "user_id": "user_count"}
    )
