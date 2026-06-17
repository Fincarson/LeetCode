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
