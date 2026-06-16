
In the subquery, we have a rank for each `question_id` based on their answer rate and the `question_id` itself. 

| question_id | rnk |
| ----------- | --- |
| 285         | 1   |
| 369         | 2   |

Lastly, we select the first `question_id` in the main query and update the column name as requested by the final output.
