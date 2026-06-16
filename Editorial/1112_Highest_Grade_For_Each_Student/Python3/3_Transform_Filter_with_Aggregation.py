result = (
    filtered.groupby("student_id")
    .apply(lambda group: group.nsmallest(1, "course_id"))
    .reset_index(drop=True)
)
