import pandas as pd

def tree_node(tree: pd.DataFrame) -> pd.DataFrame:
    # Find the root node(s)
    root = tree.loc[tree['p_id'].isna(), ['id']]
    root['type'] = 'Root'
    
    # Find the leaf nodes
    leaf = tree.loc[
        ~tree['id'].isin(tree.loc[tree['p_id'].notna(), 'p_id']) & 
        tree['p_id'].notna(), 
        ['id']
    ]
    leaf['type'] = 'Leaf'
    
    # Find the inner nodes
    inner = tree.loc[
        tree['id'].isin(tree.loc[tree['p_id'].notna(), 'p_id']) & 
        tree['p_id'].notna(), 
        ['id']
    ]
    inner['type'] = 'Inner'
    
    # Concatenate the DataFrames and sort by 'id'
    result = pd.concat([root, leaf, inner]).sort_values(by='id')
    
    return result
