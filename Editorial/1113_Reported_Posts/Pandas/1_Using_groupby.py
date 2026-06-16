
import pandas as pd

def reported_posts(actions: pd.DataFrame) -> pd.DataFrame:
    # Filter the 'actions' table to include only actions on the specified date (July 4, 2019).
    actions = actions[actions['action_date'] == '2019-07-04']
    
    # Filter further to include only 'report' actions.
    actions = actions[actions['action'] == 'report']

    # Group the filtered data by the 'extra' column (report reasons) and count the unique 'post_id's.
    report_counts = actions.groupby('extra')['post_id'].nunique().reset_index()
    
    # Rename the columns for clarity.
    report_counts = report_counts.rename(columns={
        'extra': 'report_reason',
        'post_id': 'report_count'
    })

    return report_counts
