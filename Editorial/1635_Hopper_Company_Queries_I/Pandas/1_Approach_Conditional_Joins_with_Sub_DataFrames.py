import pandas as pd

def hopper_company(drivers: pd.DataFrame, rides: pd.DataFrame, accepted_rides: pd.DataFrame) -> pd.DataFrame:
    # Approach: Subquery Constraint Tables, Left Join on months after
    # months list for series creation
    months = pd.DataFrame([num + 1 for num in range(12)], columns=["month"])

    # convert join_date to datetime
    drivers['join_date'] = pd.to_datetime(drivers['join_date'])

    # driver table - calculate active drivers that joined in 2020 or before
    driver = drivers[drivers['join_date'] < '2021-01-01']

    # utilize .apply() lambda function
    # -> if year is 2020 -> return 1, else return month
    driver['join_date'] = driver['join_date'].apply(lambda x: 1 if x.year != 2020 else x.month)

    # grab count of each active driver per month
    driver_count = driver.groupby('join_date').size().reset_index(name='active_drivers')

    # join driver with months to create driver_count, aggregate over months
    driver_months = months.merge(driver_count, how='left', left_on='month', right_on='join_date').fillna(0)
    driver_months['active_drivers'] = driver_months['active_drivers'].cumsum()
    
    # join rides with accepted rides -> left join rides
    all_rides = accepted_rides.merge(rides, how='left', on='ride_id')

    # convert requested_at to type datetime
    all_rides['requested_at'] = pd.to_datetime(all_rides['requested_at'])

    # filter for requested year in 2020 and driver_id is currently a driver
    all_rides = all_rides[(all_rides['requested_at'] > '2019-12-31') & (all_rides['requested_at'] < '2021-01-01')]
    all_rides = all_rides[all_rides['driver_id'].isin(driver['driver_id'])]

    # convert requested_at back to string & convert to month only using apply()
    all_rides['requested_at'] = all_rides['requested_at'].apply(lambda x: 1 if x.year != 2020 else x.month)

    # create accepted_rides by left joining driver months & all rides
    accepted_rides = driver_months.merge(all_rides, how='left', left_on='month', right_on='requested_at')

    # gather count of accepted rides by month
    accepted_rides = accepted_rides.groupby('month')['requested_at'].count().reset_index(name='accepted_rides')
  
    # merge result with accepted_rides - RIGHT JOIN
    result = driver_months.merge(accepted_rides, how='right', on='month')

    # grab necessary columns, clear NaNs, apply as int
    result = result[['month', 'active_drivers', 'accepted_rides']].fillna(0).astype(int)
    
    return result
