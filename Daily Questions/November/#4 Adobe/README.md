# Asked by Adobe

## Question

`You are given a tree with an even number of nodes. Consider each connection between a parent and child node to be an "edge". You would like to remove some of these edges, such that the disconnected subtrees that remain each have an even number of nodes.`

`For example, suppose your input was the following tree:`

```text
   1
  / \ 
 2   3
    / \ 
   4   5
  / | \
 6  7  8
```

`In this case, removing the edge (3, 4) satisfies our requirement.`

`Write a function that returns the maximum number of edges you can remove while still satisfying this requirement.`
