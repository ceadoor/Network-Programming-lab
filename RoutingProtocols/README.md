# Routing Protocols

## 1. Distance Vector Routing Algorithm

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/RoutingProtocols/10.distancevector.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/raw/master/RoutingProtocols/10.distancevector.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/RoutingProtocols/README.md#output)

## Output

![output_image](/.github/out_img/p_10_out.png)

# Theory

A distance-vector routing (DVR) protocol requires that a router inform its neighbors of topology changes periodically. Historically known as the old ARPANET routing algorithm (or known as **Bellman-Ford algorithm**).

Bellman Ford Basics – Each router maintains a Distance Vector table containing the distance between itself and ALL possible destination nodes. Distances,based on a chosen metric, are computed using information from the neighbors’ distance vectors.

```
Information kept by DV router -
Each router has an ID
Associated with each link connected to a router,
there is a link cost (static or dynamic).
Intermediate hops

Distance Vector Table Initialization -
Distance to itself = 0
Distance to ALL other routers = infinity number.
```

## Distance Vector Algorithm

- A router transmits its distance vector to each of its neighbors in a routing packet.
- Each router receives and saves the most recently received distance vector from each of its neighbors.
- A router recalculates its distance vector when:
  - It receives a distance vector from a neighbor containing different information than before.
  - It discovers that a link to a neighbor has gone down.

```
Dx(y) = Estimate of least cost from x to y
C(x,v) = Node x knows cost to each neighbor v
Dx = [Dx(y): y ∈ N ] = Node x maintains distance vector
Node x also maintains its neighbors' distance vectors –
    For each neighbor v, x maintains Dv = [Dv(y): y ∈ N ]
```

Note:

    From time-to-time, each node sends its own distance vector estimate to neighbors.
    When a node x receives new DV estimate from any neighbor v, it saves v’s distance vector and it updates its own DV using B-F equation:

    Dx(y) = min { C(x,v) + Dv(y)} for each node y ∈ N

Reference:

- https://www.geeksforgeeks.org/computer-network-routing-protocols-set-1-distance-vector-routing/

- http://www.thelearningpoint.net/computer-science/c-program-distance-vector-routing-algorithm-using-bellman-ford-s-algorithm
