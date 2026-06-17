import pandas as pd

def get_the_question(survey_log: pd.DataFrame) -> pd.DataFrame:

   df1 = survey_log[survey_log['action'] == 'show'].groupby('question_id', as_index=False).agg(show_cnt=('timestamp', 'count'))

   df2 = survey_log[survey_log['action'] == 'answer'].groupby('question_id', as_index=False).agg(answer_cnt=('timestamp', 'count'))

   df = df1.merge(df2, on='question_id', how='left').fillna(0)

   df['rate'] = df.answer_cnt/df.show_cnt

   df = df[df['rate'] == df['rate'].max()].groupby('rate')['question_id'].nsmallest(1).to_frame().rename(columns={'question_id': 'survey_log'})

   return df
