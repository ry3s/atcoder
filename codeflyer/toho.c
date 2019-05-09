#include <stdio.h>

int main(void) {
     int n, d;
     int *x;
     int i, j, k;
     int sum = 0;

     scanf("%d %d", &n, &d);

     x = (int *)malloc(n * sizeof(int));
     for (i = 0; i < n; i++) {
          scanf("%d", &x[i]);
     }

     for (i = 0; i < n; i++) {
          for (j = i+1; j < n; j++) {
               for (k = j+1; k < n; k++) {
                    if (abs((x[i] - x[j])) <= d
                        && abs((x[j] - x[k])) <= d
                        && abs((x[i] - x[k])) > d) {
                         sum += 1;
                    }
               }
          }
     }

     printf("%d\n", sum);
     free(x);
     return 0;
}
               
