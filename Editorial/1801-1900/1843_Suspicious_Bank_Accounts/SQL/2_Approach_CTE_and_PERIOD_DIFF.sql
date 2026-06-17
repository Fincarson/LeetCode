      SELECT 
        Income1.account_id 
      FROM 
        MonthlyIncome Income1, 
        MonthlyIncome Income2 
      WHERE 
        Income1.account_id = Income2.account_id
        AND PERIOD_DIFF(Income1.income_month, Income2.income_month) = 1
      GROUP BY 
        Income1.account_id 
      ORDER BY 
        Income1.account_id;
