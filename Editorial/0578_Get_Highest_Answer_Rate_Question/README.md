# 578. Get Highest Answer Rate Question

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/get-highest-answer-rate-question/)  
`Database`

**Problem Link:** [LeetCode 578 - Get Highest Answer Rate Question](https://leetcode.com/problems/get-highest-answer-rate-question/)

## Problem

Table: SurveyLog

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| action      | ENUM |
| question_id | int  |
| answer_id   | int  |
| q_num       | int  |
| timestamp   | int  |
+-------------+------+
This table may contain duplicate rows.
action is an ENUM (category) of the type: "show", "answer", or "skip".
Each row of this table indicates the user with ID = id has taken an action with the question question_id at time timestamp.
If the action taken by the user is "answer", answer_id will contain the id of that answer, otherwise, it will be null.
q_num is the numeral order of the question in the current session.
```

The answer rate for a question is the number of times a user answered the question by the number of times a user showed the question.

Write a solution to report the question that has the highest answer rate. If multiple questions have the same maximum answer rate, report the question with the smallest question_id.

The result format is in the following example.

### Example 1

```text
Input:
SurveyLog table:
+----+--------+-------------+-----------+-------+-----------+
| id | action | question_id | answer_id | q_num | timestamp |
+----+--------+-------------+-----------+-------+-----------+
| 5  | show   | 285         | null      | 1     | 123       |
| 5  | answer | 285         | 124124    | 1     | 124       |
| 5  | show   | 369         | null      | 2     | 125       |
| 5  | skip   | 369         | null      | 2     | 126       |
+----+--------+-------------+-----------+-------+-----------+
Output:
+------------+
| survey_log |
+------------+
| 285        |
+------------+
Explanation:
Question 285 was showed 1 time and answered 1 time. The answer rate of question 285 is 1.0
Question 369 was showed 1 time and was not answered. The answer rate of question 369 is 0.0
Question 285 has the highest answer rate.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 578. Get Highest Answer Rate Question

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Getting the Highest and the Smallest Using sort_values() and nsmallest() | Pandas |
| Getting the Highest and the Smallest Using sort_values() and head() | Pandas |
| Getting the Highest and the Smallest Using RANK() | SQL, Bash |

## Approach 1: Getting the Highest and the Smallest Using sort_values() and nsmallest()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def get_the_question(survey_log: pd.DataFrame) -> pd.DataFrame:

   df1 = survey_log[survey_log['action'] == 'show'].groupby('question_id', as_index=False).agg(show_cnt=('timestamp', 'count'))

   df2 = survey_log[survey_log['action'] == 'answer'].groupby('question_id', as_index=False).agg(answer_cnt=('timestamp', 'count'))

   df = df1.merge(df2, on='question_id', how='left').fillna(0)

   df['rate'] = df.answer_cnt/df.show_cnt

   df = df[df['rate'] == df['rate'].max()].groupby('rate')['question_id'].nsmallest(1).to_frame().rename(columns={'question_id': 'survey_log'})

   return df
```

</details>

<br>

## Approach 2: Getting the Highest and the Smallest Using sort_values() and head()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
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
```

</details>

<br>

## Approach 1: Getting the Highest and the Smallest Using RANK()

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH answer_rate AS
   (
   SELECT question_id, 
   SUM(CASE WHEN action = 'answer' THEN 1 ELSE 0 END) / SUM(CASE WHEN action = 'show' THEN 1 ELSE 0 END) AS rate
   FROM surveylog
   GROUP BY question_id
   )

Now we have the answer rate (`rate`) for each `question_id`. 

| question_id | rate |
| ----------- | ---- |
| 285         | 1    |
| 369         | 0    |

In the subquery, we want to identify the question that has the maximum answer rate. We cannot simply applying `MAX()` here since we only want to return one `question_id` if there are multiple ones that have the maximum answer rate. In this case, we `RANK()` the `question_id`s by the answer rate in a descending order and the `question_id` itself in an ascending order, so the first value in the sorted list is the `question_id` that we are looking for.
```

</details>

<details>
<summary><strong>Bash</strong></summary>

```bash

In the subquery, we have a rank for each `question_id` based on their answer rate and the `question_id` itself. 

| question_id | rnk |
| ----------- | --- |
| 285         | 1   |
| 369         | 2   |

Lastly, we select the first `question_id` in the main query and update the column name as requested by the final output.
```

</details>
