
import pandas as pd

def binary_tree_nodes(tree: pd.DataFrame) -> pd.DataFrame:
    tree["Type"] = "Inner"
    tree.loc[~tree.N.isin(tree.P), "Type"] = "Leaf"
    tree.loc[tree.P.isnull(), "Type"] = "Root"
    return tree[["N", "Type"]].sort_values("N")
