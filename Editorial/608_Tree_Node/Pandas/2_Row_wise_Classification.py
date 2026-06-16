import pandas as pd

def tree_node(tree: pd.DataFrame) -> pd.DataFrame:
    # Get the ID of the root node
    root_id = tree.loc[tree['p_id'].isnull(), 'id'].values[0]

    # Get the list of IDs that are parents (to find inner nodes later)
    parent_ids = tree['p_id'].dropna().unique()

    # Define a function to apply to each row to determine the type
    def get_type(row):
        if row['id'] == root_id:
            return 'Root'
        elif row['id'] in parent_ids:
            return 'Inner'
        else:
            return 'Leaf'

    # Apply the function to each row
    tree['type'] = tree.apply(get_type, axis=1)
    
    # Create a new DataFrame with the required columns and sort it by 'id'
    result = tree[['id', 'type']].sort_values(by='id')
    
    return result
