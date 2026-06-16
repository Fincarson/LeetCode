df = activity.groupby('player_id')['event_date'].min().reset_index()
