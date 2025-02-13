// gcc implementacao_01.c -o main.exe
//  .\main.exe   Este ".\" só preciso no PowerShell, porque o PowerShell não executa diretamente arquivos no diretório atual sem o ".\" por questões de segurança.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void getMetadadosGrafo(FILE *ptr, int *n, int *m);
void lerArestas(FILE *ptr, int *aresta);
int main()
{
    FILE *file = fopen("teste.txt", "r");
    int num_vertice;
    int num_aresta;

    if (!file)
    {
        printf("Erro ao abrir o arquivo");
    }
    getMetadadosGrafo(file, &num_vertice, &num_aresta);
    int *aresta = (int *)calloc(num_aresta * 2, sizeof(int));
    lerArestas(file, aresta);
    puts("concluiu lida de arestas");
    fclose(file);
    return 0;
}

void getMetadadosGrafo(FILE *ptr, int *n, int *m)
{
    fscanf(ptr, "%d %d", n, m);
}

void lerArestas(FILE *ptr, int *aresta)
{
    int i = 0;
    while (fscanf(ptr, "%d %d", aresta[i], aresta[i + 1]) == 2)
    {
        printf("Aresta: %d - %d", aresta[i], aresta[i + 1]);
        i += 2;
    }
}
