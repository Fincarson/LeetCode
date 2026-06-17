import pandas as pd

def count_occurrences(files: pd.DataFrame) -> pd.DataFrame:
    bull_count = files[
        files["content"].str.contains(r"(\s+bull\s+)", regex=True, case=False)
    ]["file_name"].nunique()
    bear_count = files[
        files["content"].str.contains(r"(\s+bear\s+)", regex=True, case=False)
    ]["file_name"].nunique()

    data = {"word": ["bull", "bear"], "count": [bull_count, bear_count]}

    result_df = pd.DataFrame(data)

    return result_df
