   SELECT 'Senior' AS experience, (SELECT count FROM HiredSeniors) AS accepted_candidates
   UNION
   SELECT 'Junior' AS experience, (SELECT count FROM HiredJuniors) AS accepted_candidates;
