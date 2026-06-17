final_result = distinct_viewer_ids.sort_values("viewer_id").rename(columns={"viewer_id": "id"}).reset_index(drop=True)
