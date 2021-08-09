#include <stdio.h>
#include <stdlib.h>
typedef struct n {
  int data;       //数据域
  struct n *next; //指针域
} n;
int main() {
  n *p;
  n *head;
  p = (n *)malloc(sizeof(n));
  p->next = NULL;
  head = p;
  p = (n *)malloc(sizeof(n));
  head->next = p;
}
