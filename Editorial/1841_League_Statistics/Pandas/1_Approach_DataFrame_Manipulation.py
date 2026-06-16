import pandas as pd

def league_statistics(teams: pd.DataFrame, matches: pd.DataFrame) -> pd.DataFrame:
    # Merging the teams with matches twice for home and away
    home_matches = pd.merge(matches, teams, left_on="home_team_id", right_on="team_id")
    away_matches = pd.merge(matches, teams, left_on="away_team_id", right_on="team_id")

    # Calculating points, goals for, and goals against for home and away matches
    home_matches["points"] = home_matches.apply(
        lambda x: 3
        if x["home_team_goals"] > x["away_team_goals"]
        else (1 if x["home_team_goals"] == x["away_team_goals"] else 0),
        axis=1,
    )
    home_matches["goal_for"] = home_matches["home_team_goals"]
    home_matches["goal_against"] = home_matches["away_team_goals"]

    away_matches["points"] = away_matches.apply(
        lambda x: 3
        if x["away_team_goals"] > x["home_team_goals"]
        else (1 if x["home_team_goals"] == x["away_team_goals"] else 0),
        axis=1,
    )
    away_matches["goal_for"] = away_matches["away_team_goals"]
    away_matches["goal_against"] = away_matches["home_team_goals"]

    # Concatenating the home and away results
    total_matches = pd.concat([home_matches, away_matches])

    # Grouping by team and calculating aggregates
    result = (
        total_matches.groupby("team_name")
        .agg(
            {
                "team_id": "count",
                "points": "sum",
                "goal_for": "sum",
                "goal_against": "sum",
            }
        )
        .rename(columns={"team_id": "matches_played"})
    )

    # Calculating goal difference
    result["goal_diff"] = result["goal_for"] - result["goal_against"]

    # Sorting the result
    result = result.sort_values(
        by=["points", "goal_diff", "team_name"], ascending=[False, False, True]
    )

    return result.reset_index()
