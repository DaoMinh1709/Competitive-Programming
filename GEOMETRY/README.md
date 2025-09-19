This folder contains C++ solutions to computational geometry problems, including convex hulls, polygon checks, and geometric constructions.

## Files
- **ConvexHull.cpp** – Implements Graham scan to compute the convex hull of a set of points, outputs hull size, area, and vertices.
- **PARALELL.cpp** – Groups points based on slope ratios; checks if they can be partitioned into `k` parallel sets.
- **FOXCHICK.cpp** – Builds convex hull and checks if given query points lie inside or on the hull.
- **HALF.cpp** – Sorts points angularly and outputs two points dividing the hull roughly in half.
- **BOMB.cpp** – Computes convex hull perimeter and adds circular buffer (radius `R`) to simulate explosion/shield radius.

## Techniques Used
- Convex Hull (Graham scan / Andrew’s monotone chain)  
- Orientation test (cross product, CCW)  
- Binary search for point-in-polygon test  
- String/ratio grouping for parallel lines  
- Perimeter and area calculation with added circular arcs  
