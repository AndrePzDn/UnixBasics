#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b);
int add1(int* a, int* b);
void add2(int* x, int* y, int* z);

int main(int argc, char** argv) {
  int x = 4;
  int y = 5;

  int z = x + y;

  if (x == 4) {
    printf("x = %d\n", x);
  }

  for (int i = 0; i < y; i++) {
    printf("i = %d\n", i); 
  }

  int b = add(x, y);
  printf("b = %d\n", b);

  int *ptr = &x;

//   printf("ptr = %d\n", ptr);

  *ptr = 6;

  printf("ptr = %d\n", *ptr);
  printf("x = %d\n", x);

  int c = add1(&x, &y);
  printf("c = %d\n", c);

  int r = 0;
  add2(&x, &y, &r);
  printf("r = %d\n", r);

  char* str = "Hola Mundo";
  char* ptr1 = malloc(10 * sizeof(char));
  memcpy(ptr1, str, 10);
  printf("ptr1 = %s\n", ptr1);
  free(ptr1);

  return 0;
}

int add(int x, int y) {
  return x + y;
}

int add1(int* x, int* y) {
  return *x + *y;
}

void add2(int* x, int* y, int* z) {
  *z = *x + *y;
}
