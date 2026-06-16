import pandas as pd

def find_winner(new_york: pd.DataFrame, california: pd.DataFrame) -> pd.DataFrame:
    # Counting the number of excellent students from each university
    ny_excellent_count = new_york[new_york["score"] >= 90].shape[0]
    ca_excellent_count = california[california["score"] >= 90].shape[0]

    # Comparing the counts to determine the winner
    if ny_excellent_count > ca_excellent_count:
        winner = "New York University"
    elif ny_excellent_count < ca_excellent_count:
        winner = "California University"
    else:
        winner = "No Winner"

    # Returning the result as a DataFrame
    return pd.DataFrame({"winner": [winner]})
