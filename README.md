> This repository records various algorithms to be used in problem solving.

> Each algorithm is implemented in C++.

<br>

## Contents
---

## 📂 Graph

1. **MST (Minimum Spanning Tree)**
   - Kruskal, Prim
   - Finds the minimum cost to connect all nodes without cycles.
   - Used in network design, clustering, etc.

2. **BFS / DFS**
   - Breadth-First Search, Depth-First Search
   - Fundamental graph traversal techniques.

3. **SCC (Strongly Connected Components)**
   - Tarjan’s Algorithm
   - Finds maximal subgraphs where every vertex is reachable from every other vertex.
   - Used in 2-SAT and DAG condensation.

4. **2-SAT**
   - Satisfiability check for boolean expressions with 2 variables per clause.
   - Solved via SCC (implication graph).

5. **Topological Sort**
   - Orders nodes in DAG respecting dependencies.
   - Common in scheduling problems.

6. **Articulation Point & Bridge**
   - Finds critical vertices and edges whose removal increases connected components.
   - Used in network reliability.

7. **Bipartite Matching**
   - Maximum matching in bipartite graphs using DFS or Flow.
   - Useful for team assignment, stable marriage, etc.

8. **Max Flow / Min Cut**
   - Edmonds-Karp, Dinic
   - Solves flow capacity problems and partitioning.
   - Basis for many matching and cut problems.

9. **Eulerian Path / Circuit**
   - Visits all edges exactly once.
   - Used in route planning, postman problems.

---

## 📂 Tree

1. **DFS / BFS on Tree**
   - Basic traversal adapted for tree structures.

2. **Tree Diameter**
   - Finds the longest path between any two nodes in a tree.
   - Uses two BFS traversals.

3. **LCA (Lowest Common Ancestor)**
   - Binary Lifting
   - Finds the deepest common ancestor of two nodes.
   - Useful in tree path queries.

4. **Heavy-Light Decomposition**
   - Decomposes tree into chains for efficient segment tree usage.
   - Supports path queries like max, sum, etc.

5. **Tree DP**
   - DP applied to hierarchical structures.
   - Used for subtree size, coloring, etc.

---

## 📂 Math

1. **GCD / LCM / POW**
   - Euclidean algorithm, fast exponentiation.
   - Modular arithmetic base.

2. **Extended GCD**
   - Solves ax + by = gcd(a, b)
   - Used for modular inverse, CRT.

3. **Combination**
   - nCr computation with precomputed factorials.
   - Uses Fermat's Little Theorem.

4. **Prime**
   - Prime sieving (Sieve of Eratosthenes), Miller-Rabin test.
   - Also includes Pollard’s Rho for factorization.

5. **Fibonacci Matrix**
   - Computes nth Fibonacci in O(log n) using matrix exponentiation.

6. **Geometry**
   - Includes CCW, intersection, convex hull, polygon area.
   - Core template for computational geometry.

---

## 📂 String

1. **KMP**
   - Pattern matching algorithm with prefix table.
   - O(N+M) complexity.

2. **Z-algorithm**
   - Computes length of longest prefix from each position.
   - Fast string comparison base.

3. **Rabin-Karp**
   - Hash-based pattern search.
   - Good for multiple patterns or substring uniqueness.

4. **Aho-Corasick**
   - Multi-pattern matching using trie + failure links.
   - Used in dictionary string search.

5. **Suffix Array + LCP**
   - Lexicographical ordering of suffixes.
   - Enables fast substring comparison, counting.

6. **Trie**
   - String prefix tree.
   - Used for dictionary, autocomplete, and prefix matching.

---

## 📂 Data Structure

1. **Disjoint Set (Union-Find)**
   - Merges and finds representative sets efficiently.
   - Used in Kruskal’s MST, connectivity check.

2. **Fenwick Tree**
   - Efficient prefix sum structure.
   - Smaller, simpler than segment tree for point updates.

3. **Segment Tree**
   - Supports range query + update.
   - Can be extended with lazy propagation.

4. **Monotonic Queue**
   - Maintains min/max in a sliding window.
   - Used in optimization problems.

5. **Sliding Window**
   - Fixed or dynamic window for array/string traversal.
   - Used in substring, sum problems.

6. **Mo's Algorithm**
   - Offline query optimization on arrays.
   - √N decomposition + sorting trick.

7. **Two Pointer**
   - Linear scan technique using two indices.
   - Used in subarray, pair sum problems.

---

## 📂 Technique

1. **Bitmask DP**
   - Encodes visited or chosen states as bitmask.
   - Used in TSP, subset DP.

2. **Knapsack (배낭 문제)**
   - 0/1 Knapsack DP with value and weight.
   - Used in resource optimization problems.

3. **Coordinate Compression**
   - Compresses large coordinate ranges to small indices.
   - Used with segment trees, BIT, etc.

---

<br>

## Teamnotes
- 2024-10 / ICPC 2024 / WhereIsWoongJae / with 김현서, 방재현


