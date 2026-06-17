import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    # Self join on viewer_id and view_date, but ensure different articles
    merged_views = views.merge(views, on=["viewer_id", "view_date"])
    distinct_articles = merged_views[
        merged_views["article_id_x"] < merged_views["article_id_y"]
    ]

    # Extract unique viewer IDs who viewed more than one article on the same date
    result = (
        distinct_articles[["viewer_id"]]
        .drop_duplicates()
        .rename(columns={"viewer_id": "id"})
    )

    return result.sort_values("id").reset_index(drop=True)
