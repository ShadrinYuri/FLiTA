#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int fl;
    printf("Choose graph - 1 or digraph - 2\n");
    scanf("%d", &fl);

    printf("Count: ");
    int n;
    scanf("%d",&n);



    int graph[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Fill the names of elements\n");
    char *name[n];

    for (int i = 0; i < n; i++)
    {
        printf("# ");
        char *sname = (char*) malloc(20 * sizeof(char));
        scanf("%s", sname);
        name[i] = sname;
    }

    printf("Enter connection\n");
    char *str = (char*) malloc(100 * sizeof(char));
    scanf("%s", str);
    char *first_name;
    first_name = strtok(str, "-");
    while(first_name != NULL)
    {

        int index_first_name = -1;
        char *second_name;
        int index_second_name = -1;

        second_name = strtok(NULL, ";");

        for( int i = 0; i < n; i++)
        {
            if(strcmp(name[i], first_name) == 0)
                index_first_name = i;
            if(strcmp(name[i], second_name) == 0)
                index_second_name = i;
        }

        if ((index_first_name != -1) && (index_second_name != -1))
        {
            if (fl == 1)
            {
                graph[index_first_name][index_second_name] = 1;
                graph[index_second_name][index_first_name] = 1;
            }
            else
            {
                graph[index_first_name][index_second_name] = 1;
            }
        }

        first_name = strtok(NULL, "-");
    }

    int buf_graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            buf_graph[i][j] = graph[i][j];
        }
    }

    printf("Enter the degree of the vertex\n");
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

    char* arr = (char*) calloc(500, sizeof(char));

    if(fl == 2)
    {
        strcat(arr, "digraph G {");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] > 0)
                {
                    strcat(arr, name[i]);
                    strcat(arr, "->");
                    strcat(arr, name[j]);
                    strcat(arr, ";");
                }
            }
        }
    }
    else
    {
        strcat(arr, "graph G {");
        for (int i = 0; i < n; i++)
        {
            strcat(arr, name[i]);
            strcat(arr, ";");
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (graph[i][j] > 0)
                {
                    strcat(arr, name[i]);
                    strcat(arr, "--");
                    strcat(arr, name[j]);
                    strcat(arr, ";");
                }
            }
        }
    }

    strcat(arr, "}");

    FILE* f = fopen("graph.dot", "w");
    fprintf(f, "%s\n", arr);
    fclose(f);

    free(arr);

    return 0;
}
