SELECT activity
FROM user_by_activity
WHERE user_cnts NOT IN (SELECT MAX(user_cnts) FROM user_by_activity)
AND user_cnts NOT IN (SELECT MIN(user_cnts) FROM user_by_activity)
