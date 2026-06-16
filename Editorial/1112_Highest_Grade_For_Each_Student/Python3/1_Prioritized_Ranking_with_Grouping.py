result = sorted_df.groupby("student_id").head(1).reset_index(drop=True)
