import pandas as pd

def count_seniors_and_juniors(candidates: pd.DataFrame) -> pd.DataFrame:
    # Constants
    BUDGET = 70000

    # Separate seniors and juniors and sort by salary
    seniors = candidates[candidates["experience"] == "Senior"].sort_values(by="salary")
    juniors = candidates[candidates["experience"] == "Junior"].sort_values(by="salary")

    # Calculate cumulative salaries
    seniors["cumulative_salary"] = seniors["salary"].cumsum()
    juniors["cumulative_salary"] = juniors["salary"].cumsum()

    # Determine how many seniors can be hired
    seniors_hired = seniors[seniors["cumulative_salary"] <= BUDGET]
    remaining_budget = BUDGET - seniors_hired["salary"].sum()

    # Determine how many juniors can be hired with the remaining budget
    juniors_hired = juniors[juniors["cumulative_salary"] <= remaining_budget]

    # Prepare the result
    result = pd.DataFrame(
        {
            "experience": ["Senior", "Junior"],
            "accepted_candidates": [len(seniors_hired), len(juniors_hired)],
        }
    )

    return result
