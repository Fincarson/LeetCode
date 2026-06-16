import pandas as pd

def shortest_distance(point2_d: pd.DataFrame) -> pd.DataFrame:
    df = point2_d.merge(point2_d, how='cross')
    
    # Filter df so no same points are calculated
    df = df[(df['x_x'] != df['x_y']) | (df['y_x'] != df['y_y'])]
    
    # Calculate shortest given the distance formula
    df['shortest'] = ((df['x_y'] - df['x_x']).pow(2) + (df['y_y'] - df['y_x']).pow(2)).pow(1/2)
    
    # Round each value in shortest
    df['shortest'] = df['shortest'].apply(lambda x: round(x, 2))

    # Find shortest, remove duplicates and return
    df = df[df['shortest'] == df['shortest'].min()].drop_duplicates('shortest')
    
    return df[['shortest']]
