final_result = (
    distinct_viewers
    .sort_values()
    .to_frame(name="id")
    .reset_index(drop=True)
)
