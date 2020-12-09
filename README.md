# 24.	Найти все ребра, смежные к вершинам с заданной степенью вершины

## Алгоритм:

- 

``` C
int buf_graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            buf_graph[i][j] = graph[i][j];
        }
    }
```
