# 📅 Daily Log – 23 May 2025

## ✅ Problems Solved

### - [Minesweeped](../../Topic-wise/Graph/Minesweeped.cpp)
- **Approach**: Used **BFS** with a queue.
- **Learning**: Initially got stuck by not using a direction array for `(x, y)` movement.
- **Complexity**:
  - **Time**: O(n * m), where `n = rows` and `m = columns`
  - **Space**: O(n * m)

## 🧠 Key Takeaways
- Revisited BFS traversal for grid-based problems.
- Importance of direction arrays to simplify code and avoid bugs.

## ⏱ Time Spent
- ~1.15 minutes

<br><br>


### - [Max area of Island](../../Topic-wise/Graph/Max-Area-of-island.cpp)
- **Approach**: Used **DFS** with a recursion.
- **Learning**: Same as of Minesweeped.
- **Complexity**:
  - **Time**: O(n * m), where `n = rows` and `m = columns`
  - **Space**: O(n * m)

## 🧠 Key Takeaways
- Questions changes but the core concept remain same

## ⏱ Time Spent
- ~14 minutes

<br><br>

### - [Max num of fish](../../Topic-wise/Graph/Max-num-of-fish.cpp)
- **Approach**: Used **DFS** with a recursion.
- **Learning**: Same as of Max area of Island.
- **Complexity**:
  - **Time**: O(n * m), where `n = rows` and `m = columns`
  - **Space**: O(n * m)

## 🧠 Key Takeaways
- Questions changes but the core concept remain same

## ⏱ Time Spent
- ~5 minutes
<br><br>


### - [count unreacble pair of nodes](../../Topic-wise/Graph/count-unreachable-pairs-of-nodes-in-an-undirected-graph.cpp)
- **Approach**: Used **DFS** with a recursion or stack.
- **Learning**: using the total no. of isolated concept and the total possible multiplicaiton of every pair in the temp vector, which contains the total no. of isolated islands
- **Complexity**:
  - **Time Complexity**: `O(V + E + k^2)`  , V = number of vertices , E = no. of edges , k = no. of isolated components
  - **Space Complexity**: `O(V+E)`


## 🧠 Key Takeaways
- used the suffix sum concpet to calculate the ans instead of nested loops, reducing the T.C from `O(n^2)` to `O(n)`. But the best one is using the running space appoarch which don't used any extra space unlike suffix sum.

## ⏱ Time Spent
- ~12 minutes