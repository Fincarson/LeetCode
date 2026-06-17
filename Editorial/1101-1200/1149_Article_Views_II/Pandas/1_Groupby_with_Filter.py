import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    # Group by viewer_id and view_date, then count unique articles
    grouped = views.groupby(["viewer_id", "view_date"]).agg({"article_id": "nunique"})

    # Filter out entries with unique article counts less than or equal to 1
    result = grouped[grouped["article_id"] > 1].reset_index()

    # Extract and sort the viewer IDs, drop duplicates and return as a DataFrame
    final_result = (
        result["viewer_id"]
        .sort_values()
        .drop_duplicates()
        .to_frame(name="id")
        .reset_index(drop=True)
    )

    return final_result
