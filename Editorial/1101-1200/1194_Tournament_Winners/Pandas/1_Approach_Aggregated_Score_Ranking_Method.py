import pandas as pd

def tournament_winners(
    players_df: pd.DataFrame, matches_df: pd.DataFrame
) -> pd.DataFrame:
    # Aggregate scores for each player when they are the first player
    scores_as_first_player = matches_df.groupby("first_player")["first_score"].sum()

    # Aggregate scores for each player when they are the second player
    scores_as_second_player = matches_df.groupby("second_player")["second_score"].sum()

    # Combine the scores from both roles (first and second player)
    total_scores = scores_as_first_player.add(
        scores_as_second_player, fill_value=0
    ).reset_index(name="total_score")

    # Merge the total scores with the players DataFrame
    players_with_scores = players_df.merge(
        total_scores, left_on="player_id", right_on="index"
    )

    # Sort by total score (descending) and player_id (ascending) for tie-breaking
    players_with_scores.sort_values(
        ["total_score", "player_id"], ascending=[False, True], inplace=True
    )

    # Select the top player from each group
    winners = players_with_scores.groupby("group_id").head(1)[["group_id", "player_id"]]

    return winners
