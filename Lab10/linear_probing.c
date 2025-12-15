#include <stdio.h>
#define MAX 100
int main(){
    int ht[MAX];
    int N, m;
    int i, key, index;
    for (i = 0; i < MAX; i++)
        ht[i] = -1;
    printf("Enter size of hash table (m): ");
    scanf("%d", &m);
    printf("Enter number of employee keys (N): ");
    scanf("%d", &N);
    printf("Enter %d keys (4-digit integers):\n", N);
    for (i = 0; i < N; i++){
        scanf("%d", &key);
        index = key % m;
        if (ht[index] != -1){
            printf("Collision detected for key %d at index %d. Probing...\n", key, index);
            int start = index;
            while (ht[index] != -1)
            {
                index = (index + 1) % m;
                if (index == start){
                    printf("Hash table is full. Cannot insert key %d\n", key);
                    break;
                }
            }
        }
        if (ht[index] == -1){
            ht[index] = key;
            printf("Inserted key %d at index %d\n", key, index);
        }
    }
    printf("\nFinal Hash Table:\n");
    for (i = 0; i < m; i++){
        printf("Index %2d : ", i);
        if (ht[i] == -1) printf("Empty\n");
        else  printf("%d\n", ht[i]);
    }
    return 0;
}
