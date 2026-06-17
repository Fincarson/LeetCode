import pandas as pd
import numpy as np

def binary_tree_nodes(tree: pd.DataFrame) -> pd.DataFrame:
    # Check if each node is a parent (Inner) or not
    tree["Type"] = np.where(
        tree["P"].isnull(), "Root", np.where(tree["N"].isin(tree["P"]), "Inner", "Leaf")
    )

    # Sort the DataFrame by the 'N' column
    return tree.sort_values("N")[["N", "Type"]]
