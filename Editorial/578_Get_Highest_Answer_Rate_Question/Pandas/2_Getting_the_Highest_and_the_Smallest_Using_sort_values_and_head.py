import pandas as pd

def get_the_question(survey_log: pd.DataFrame) -> pd.DataFrame:

   df = survey_log.groupby(
      'question_id', 
      as_index=False
   ).agg(
      rate = ('action', 
      lambda x: (x == 'answer').sum() / (x == 'show').sum())
   )

   df = df.sort_values(
      ['rate', 'question_id'], 
      ascending=[False, True]
   ).head(
      1
   )[['question_id']].rename(
      columns={'question_id': 'survey_log'}
   )
    
   return df
