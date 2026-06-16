import pandas as pd

def type_of_triangle(triangles: pd.DataFrame) -> pd.DataFrame:
    triangles["triangle_type"] = "Scalene"

    triangles.loc[
        (triangles["A"] == triangles["B"]) & (triangles["A"] == triangles["C"]),
        "triangle_type",
    ] = "Equilateral"

    triangles.loc[
        (
            (triangles["A"] == triangles["B"])
            | (triangles["A"] == triangles["C"])
            | (triangles["C"] == triangles["B"])
        )
        & (triangles["triangle_type"] != "Equilateral"),
        "triangle_type",
    ] = "Isosceles"

    triangles.loc[
        (triangles["A"] >= triangles["B"] + triangles["C"])
        | (triangles["B"] >= triangles["A"] + triangles["C"])
        | (triangles["C"] >= triangles["B"] + triangles["A"]),
        "triangle_type",
    ] = "Not A Triangle"

    return triangles[["triangle_type"]]
