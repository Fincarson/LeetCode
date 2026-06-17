import pandas as pd

def find_cutoff_score(schools: pd.DataFrame, exam: pd.DataFrame) -> pd.DataFrame:

    df = schools.merge(exam, how='cross') 

    filtered_df = df[df.capacity >= df.student_count]

    min_scores = filtered_df.groupby('school_id')['score'].min().reset_index()

    result = min_scores.merge(schools, how='right')

    result['score'] = result['score'].fillna(-1)

    return result[['school_id', 'score']]
