#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a,b,i;
void *sum(void *threadid)
{
  int *tid = (int *)threadid;
  printf("Toplam : %d (Thread ID, %d)\n",a+b, *tid);
  pthread_exit(NULL);
}
void *subtraction(void *threadid)
{
  int *tid = (int *)threadid;
  printf("Fark : %d (Thread ID, %d)\n",a-b, *tid);
  pthread_exit(NULL);
  }
void *multiply(void *threadid)
{
  int *tid = (int *)threadid;
  printf("Carpim : %d (Thread ID, %d)\n",a*b, *tid);
  pthread_exit(NULL);
}
void *division(void *threadid)
{
  int *tid = (int *)threadid;
  printf("Bolum : %.1f (Thread ID, %d)\n",(float)a/b, *tid);
  pthread_exit(NULL);
}
int main()
{
  printf("ilk rakami giriniz : ");
  scanf("%d", &a);
  printf("ikinci rakami giriniz : ");
  scanf("%d", &b);
  pthread_t threads[4];
  int rc;
  for (i = 0; i < 4; ++i)
  {
    switch (i)
    {
      case 0:
        rc = pthread_create(&threads[i], NULL, sum, (void *)&i);
        if (rc) {
          printf("Thread olusturulamadi, uygulama sonlandiriliyor!, %d\n", rc);
          exit(-1);
        }
        break;

      case 1:
        rc = pthread_create(&threads[i], NULL, subtraction, (void *)&i);
        if (rc) {
          printf("Thread olusturulamadi, uygulama sonlandiriliyor!, %d\n", rc);
          exit(-1);
        }
        break;

      case 2:
        rc = pthread_create(&threads[i], NULL, multiply, (void *)&i);
        if (rc) {
          printf("Thread olusturulamadi, uygulama sonlandiriliyor!, %d\n", rc);
          exit(-1);
        }
        break;

      case 3:
        rc = pthread_create(&threads[i], NULL, division, (void *)&i);
        if (rc) {
          printf("Thread olusturulamadi, uygulama sonlandiriliyor!, %d\n", rc);
          exit(-1);
        }
        break;
    }

  }
}
