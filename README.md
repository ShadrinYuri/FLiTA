# 24.	Найти все ребра, смежные к вершинам с заданной степенью вершины

## Алгоритм:

- создание копии исходного графа

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
- нахождение вершины с заданной степенью вершины и вывод смежных ребер

``` C
    int deg;
    scanf("%d", &deg);
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += buf_graph[i][j];
        }

        if (sum == deg)
        {
            for (int j = 0; j < n; j++)
            {
                if ((buf_graph[i][j] != 0) && (buf_graph[j][i] != 0))
                {
                    printf("%s - %s\n", name[i], name[j]);
                    buf_graph[i][j] = 0;
                }
            }
        }
    }
```
## Структурная схема алгоритма:
![Alt-текст](https://github.com/igorkorobenko/FLITA_4dz/blob/main/str_scheme.png "структурная схема")

## Результат работы:
![Alt-текст](https://github.com/ShadrinYuri/FLiTA/blob/master/result.png "результат работы")

## Отображение графа:
![Alt-текст](https://github.com/ShadrinYuri/FLiTA/blob/master/graph.png "отображение графа")
