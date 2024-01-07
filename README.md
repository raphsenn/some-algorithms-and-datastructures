# some-algorithms-and-datastructures-in-cplusplus

## Datastructures

### Graphs

A Graph is an ordered Pair G = (V, E) with V = Set of Vertices, E = Set of Edges.
Let n be the number of Vertices (n = |V|) and m the number of Edges (m = [E|) of G.

For example:
Let V = {v1, v2, v3, ..., v10} and E = {(v1, v2), (v2, v3), (v3, v4), ..., (v9, v10)}.
This includes that n = |V| = |{v1, v2, v3, ..., v10}| = 10,
and m = |E| = |{(v1, v2), (v2, v3), (v3, v4), ..., (v9, v10)| = 9.

#### Undirected graph

<table>
  <thead>
    <tr>
      <th>Method</th>
      <th>Runtime</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>create_adjacency_list</td>
      <td>&#920;(m + n)</td>
    </tr>
    <tr>
      <td>create_adjacency_matrix</td>
      <td>&#920;($\ n^2$)</td>
    </tr>
    <tr>
      <td>get_adjacency_list</td>
      <td>&#920;(1)</td>
    </tr>
    <tr>
      <td>get_adjacency_matrix</td>
      <td>&#920;(1)</td>
    </tr>
    <tr>
      <td>edge_in_edges(edge)</td>
      <td>&#927;(m)</td>
    </tr>
    <tr>
      <td>get_vertices</td>
      <td>&#920;(1)</td>
    </tr>
    <tr>
      <td>get_edges</td>
      <td>&#920;(1)</td>
    </tr>
    <tr>
      <td>get_out_degree(vertex)</td>
      <td>&#920;(1)</td>
    </tr>
    <tr>
      <td>get_in_degree(vertex)</td>
      <td>&#920;(m)</td>
    </tr>
    <tr>
      <td>get_adjacency_list_as_string</td>
      <td>&#920;(m + n)</td>
    </tr>
    <tr>
      <td>get_adjacency_matrix_as_string</td>
      <td>&#920;($n^{2}$)</td>
    </tr>
    <tr>
      <td>print</td>
      <td>&#920;(m + n)</td>
    </tr>

  </tbody>
</table>

#### Directed graph

<table>
  <thead>
    <tr>
      <th>Method</th>
      <th>Runtime</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>create_adjacency_list</td>
      <td>&#920;(m + n)</td>
    </tr>
    <tr>
      <td>create_adjacency_matrix</td>
      <td>&#920;($\ n^2$)</td>
    </tr>
    <tr>
      <td>get_adjacency_list</td>
      <td>&#920;(1)</td>
    </tr>
    <tr>
      <td>get_adjacency_matrix</td>
      <td>&#920;(1)</td>
    </tr>
    <tr>
      <td>edge_in_edges(edge)</td>
      <td>&#927;(m)</td>
    </tr>
    <tr>
      <td>get_vertices</td>
      <td>&#920;(1)</td>
    </tr>
    <tr>
      <td>get_edges</td>
      <td>&#920;(1)</td>
    </tr>
    <tr>
      <td>get_out_degree(vertex)</td>
      <td>&#920;(1)</td>
    </tr>
    <tr>
      <td>get_in_degree(vertex)</td>
      <td>&#920;(m)</td>
    </tr>
    <tr>
      <td>get_adjacency_list_as_string</td>
      <td>&#920;(m + n)</td>
    </tr>
    <tr>
      <td>get_adjacency_matrix_as_string</td>
      <td>&#920;($n^{2}$)</td>
    </tr>
    <tr>
      <td>print</td>
      <td>&#920;(m + n)</td>
    </tr>

  </tbody>
</table>


### Inverted Index

#### Inverted Index with BM25 Algorithm

## Algorithms

### Sorting algorithms

<table>
  <thead>
    <tr>
      <th>Algorithm</th>
      <th>Runtime</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>MinSort</td>
      <td>&#920;($n^{2}$)</td>
    </tr>
    <tr>
      <td>MergeSort</td>
      <td>&#920;(nlog(n))</td>
    </tr>
      </tbody>
</table>

### Heaps algorithm


