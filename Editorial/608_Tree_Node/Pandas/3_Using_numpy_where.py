import pandas as pd
import numpy as np

def tree_node(tree: pd.DataFrame) -> pd.DataFrame:
    tree["type"] = np.where(
        tree["p_id"].isna(),
        "Root",
        np.where(
            tree["id"].isin(tree["p_id"].unique()) & tree["p_id"].notna(),
            "Inner",
            "Leaf",
        ),
    )
    return tree[["id", "type"]]
