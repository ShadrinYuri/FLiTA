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

    printf("\n");


//    a-b;a-c;b-c;
//
    printf("Enter connection\n");
    char *str = (char*) malloc(100 * sizeof(char));
    scanf("%s", str);
    int k = 0;
    char *first_name = (char*) malloc(20 * sizeof(char));

    strcpy(first_name, strtok(str, "-"));
    while(first_name != NULL)
    {

        int index_first_name = -1;
        char *second_name = (char*) malloc(20 * sizeof(char));
        int index_second_name = -1;

        //if (k != 0)
            //strcpy(first_name, strtok(NULL, "-"));
        //else
            //strcpy(first_name, strtok(str, "-"));
        strcpy(second_name, strtok(NULL, ";"));
        // if (first_name == NULL)
        //     break;
        printf("%s\n", first_name);
        printf("%s\n", second_name);

        //k += strlen(first_name) + strlen(first_name) + 2;
        //printf("%d\n", k);
        for( int i = 0; i < n; i++)
        {
            if(strcmp(name[i], first_name) == 0)
                index_first_name = i;
            if(strcmp(name[i], second_name) == 0)
                index_second_name = i;
        }

        printf("%d\n", index_first_name);
        printf("%d\n", index_second_name);
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
        printf("sdsds\n");
        free(first_name);
        free(second_name);
        char *first_name = (char*) malloc(20 * sizeof(char));
        strcpy(first_name, strtok(NULL, "-"));
        printf("%s\n", first_name);
        printf("sdsdsand\n");
    }
    printf("and\n");
//
    _Bool goriz = 1;
    for (int i = 0; i < n; i++){
        _Bool vertic = 0;
        for (int j = 0; j < n; j++){
            if (graph[i][j] > 0)
                vertic = 1;

            if (graph[j][i] > 0)
                vertic = 1;
        }
        if (vertic == 0)
            goriz = 0;
    }
    if (!goriz){
        printf("Unrelated graph\n");
    }
    else {
        printf("Related graph\n");
    }

    for (int i = 0; i < n; i++){
        printf("#%d %10s: ", i + 1, name[i]);
            for (int k = 0; k < n; k++){
                printf("%d ", graph[i][k]);
            }
            printf("\n");
    }



    char* arr = (char*) calloc(500, sizeof(char));

    if(fl == 2){
        strcat(arr, "digraph G {");
        for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (graph[i][j] > 0){
                for (int a = 0; a < graph[i][j]; a++){
                    strcat(arr, name[i]);
                    strcat(arr, "->");
                    strcat(arr, name[j]);
                    strcat(arr, ";");
                }
            }
        }
    }
    }
    else {
        strcat(arr, "graph G {");
        for (int i = 0; i < n; i++){
            strcat(arr, name[i]);
            strcat(arr, ";");
        }
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if (graph[i][j] > 0){
                    for (int a = 0; a < graph[i][j]; a++){
                        strcat(arr, name[i]);
                        strcat(arr, "--");
                        strcat(arr, name[j]);
                        strcat(arr, ";");
                    }
                }
            }
        }
        }

    strcat(arr, "}");

    FILE* f = fopen("graph.dot", "w");
    fprintf(f, "%s\n", arr);
    fclose(f);

    char* term = (char*) calloc(500, sizeof(char));

    strcat(term, "echo \"");
    strcat(term, arr);

    strcat(term, "\" | dot -Tpng >./graph_pikcha.png");
    printf("%s\n", term);
    system(term);
    free(term);
    free(arr);

    return 0;
}
