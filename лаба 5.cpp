#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    srand(time(NULL));
	setlocale(0, "");
    int N;
    int s = 0, f;
    printf("Количество вершин: ");
    scanf("%d", &N);
    int CountOfVertex = N;
    int *d = new int[N];
    int **Arr = new int *[N];
	int *c = new int[N];
    for (int i = 0; i < N; i++) {
        Arr[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < CountOfVertex; j++) {
            if (i == j) {
                Arr[i][j] = 0;
            } else if (i != j) {
                Arr[i][j] = rand() % 2;
                Arr[j][i] = Arr[i][j];
}
        }
    }

for (int i = 0; i < N; i++) {
        for (int j = 0; j < CountOfVertex; j++) {
            if (Arr[i][j] != 0) {
                s = s + 1;
            }
            printf("%d ", Arr[i][j]);
        }
        d[i] = s;
        s = 0;
        printf("\n");
    }
    printf("\n");
	printf(" Изолированные вершины: ");
	f=0;
    for (int i = 0; i < N; i++) {
		if (d[i] == 0) {
		printf("%d ", i + 1);
		f++;
	}
	}
	if(f==0)
			printf("нет");
	
		f=0;
printf("\n Концевые вершины: ");
for (int i = 0; i < N; i++) {
        if (d[i] == 1) {
			f++;
		printf("%d ", i + 1);
		}
}
if(f==0)
			printf("нет");
	f=0;
printf("\n Доминирующие вершины: ");
	for (int i = 0; i < N; i++) {
        if (d[i] == N - 1) {
			f++;
            printf("%d ", i + 1);
        }
    }
	if(f==0)
			printf("нет");


    int kol=0;
    for (int i = 0; i < N; i++) {
		kol=0;
        for (int j = 0; j < CountOfVertex; j++) {
            if (Arr[i][j] != 0) {
                kol++;
            }
        }
		c[i]=kol;

    }
	 printf("\n Степень вершины:  ");
	for (int i = 0; i < N; i++) {
    printf(" %d", i+1);
	}
	printf("\n                    ");
	for (int i = 0; i < N; i++) {
    printf("%d ",c[i]);
	}
	printf("\n");
	int r=0;
 for (int i = 0; i < N; i++) {
        for (int j = 0; j < CountOfVertex; j++) {
		 if (Arr[i][j] != 0) {
r++;
}	
		}
 }
	printf(" Размер графа: %d", r/2);
	getchar();
		getchar();
}
