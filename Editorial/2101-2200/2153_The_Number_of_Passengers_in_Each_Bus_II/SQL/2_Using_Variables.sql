    SELECT 
      bus_id, 
      passengers_cnt 
    FROM 
      (
        SELECT 
          bus_id, 
          capacity, 
          eligible_passengers, 
          @boarded_passengers := LEAST(
            capacity, eligible_passengers - @accumulated_boarding
          ) AS passengers_cnt, 
          @accumulated_boarding := @accumulated_boarding + @boarded_passengers 
        FROM 
          OrderedBusArrivals, 
          (
            SELECT 
              @accumulated_boarding := 0, 
              @boarded_passengers := 0
          ) AS Initialization
      ) AS FinalResult 
    ORDER BY 
      bus_id;
