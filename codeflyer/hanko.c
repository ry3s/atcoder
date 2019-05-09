#include <stdio.h>

int main(void) {
     int h, w, n, m;
     int i, j, k;
     int s, t;
     char **a;
     char **sheet;
     int sum = 0;
     
     scanf("%d %d %d %d", &h, &w, &n, &m);

     a = (char *)malloc(sizeof(char *) * n);
     sheet = (char *)malloc(sizeof(char *) * h);
     for (i=0;i<n;i++) {
          a[i] = malloc(sizeof(char) * m);
     }
     for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
               scanf("%c ", &a[i][j]);
               
          }
     }
     for (i=0;i<h;i++) {
               sheet[i] = malloc(sizeof(char) * w);
     }
     for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
               sheet[i][j] = '.';
          }
     }
     

     for (s = 0; s < (h - n + 1); s++) {
          for (t = 0; t < (w - m + 1); t++) {
               for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                         if (a[i][j] == '#'
                             && sheet[s+i][t+j] == '.' ) {
                              sheet[s+i][t+j] = '#';
                              sum += 1;
                         }
                    }
               }
                              
          }
     }
     printf("%d", sum);

     for (i=0;i<n;i++) {
          free(a[i]);

     }
     for (i=0;i<h;i++) {
          free(sheet[i]);

     }
     return 0;
}
