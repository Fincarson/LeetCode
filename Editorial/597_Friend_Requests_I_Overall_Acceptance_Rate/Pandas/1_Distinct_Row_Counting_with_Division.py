import pandas as pd

def acceptance_rate(friend_request: pd.DataFrame, request_accepted: pd.DataFrame) -> pd.DataFrame:

    # Dropping duplicate rows to make sure we have distinct rows
    distinct_accepted = request_accepted[['requester_id', 'accepter_id']].drop_duplicates()
    distinct_request = friend_request[['sender_id', 'send_to_id']].drop_duplicates()

    # Counting the rows of distinct data
    accepted_count = len(distinct_accepted)
    request_count = len(distinct_request)

    # Calculate acceptance rate
    if request_count != 0:
        accept_rate = round(accepted_count / request_count, 2)
    else:
        accept_rate = 0

    return pd.DataFrame({"accept_rate": [accept_rate]})
