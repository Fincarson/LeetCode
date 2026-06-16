import pandas as pd

def market_analysis(users: pd.DataFrame, orders: pd.DataFrame, items: pd.DataFrame) -> pd.DataFrame:

    orders["rank"] = orders.groupby("seller_id")["order_date"].rank()

    orders_and_items = orders.merge(items, on = 'item_id')
    
    second_item = orders_and_items[orders_and_items['rank'] == 2]

    users_and_second_item = users.merge(second_item, left_on = 'user_id', right_on = 'seller_id', how = 'left')

    users_and_second_item['2nd_item_fav_brand'] = (users_and_second_item['favorite_brand'] == users_and_second_item['item_brand']).apply(lambda x: 'yes' if x else 'no')

    final_output = users_and_second_item[['user_id', '2nd_item_fav_brand']].rename(columns= {'user_id': 'seller_id'})

    return final_output
