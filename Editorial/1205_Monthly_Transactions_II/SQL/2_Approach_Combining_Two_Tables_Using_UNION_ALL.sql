This step returns the monthly totals of approved transactions. 

| month   | country | approved_count | approved_amount | chargeback_count | chargeback_amount |
| ------- | ------- | -------------- | --------------- | ---------------- | ----------------- |
| 2019-05 | US      | 1              | 1000            | 0                | 0                 |
| 2019-06 | US      | 2              | 8000            | 0                | 0    

Now we can combine the previous output using the function `UNION ALL`. We can put all previous steps in either a CTE or a subquery. From the below output, we can see that there are duplicates in months. 

| month   | country | approved_count | approved_amount | chargeback_count | chargeback_amount |
| ------- | ------- | -------------- | --------------- | ---------------- | ----------------- |
| 2019-05 | US      | 0              | 0               | 1                | 2000              |
| 2019-06 | US      | 0              | 0               | 1                | 1000              |
| 2019-09 | US      | 0              | 0               | 1                | 5000              |
| 2019-05 | US      | 1              | 1000            | 0                | 0                 |
| 2019-06 | US      | 2              | 8000            | 0                | 0                 |

Therefore, the last step is to get the monthly totals again for all calculations at the month and country level in the main query. 

<!-- h4 for sections -->
#### Implementation
