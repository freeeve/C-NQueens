/* Copyright 2011 Wes Freeman
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_node {
  int x;
  struct list_node *next;
};

struct stack_node {
  struct stack_node *next;
  struct list_node *list;
};

int length(struct list_node *list);

void push_to_list(struct list_node *list, int x);

void copy_list(struct list_node *list, struct list_node **new_list); 

void push_to_stack(struct stack_node **stack, struct list_node *list);

void pop_from_stack(struct stack_node **stack, struct list_node **list);

bool check_diagonals(struct list_node *b, int x);

void print_board(struct list_node *b);

bool contains(struct list_node *b, int x);

void free_list(struct list_node **list);

void print_stack(struct stack_node *stack);

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  int count = 0;

  struct stack_node *stack = NULL;

  // initialize stack with first column values
  int i;
  for(i=0;i<n;i++) {
    struct list_node *list = (struct list_node *) malloc(sizeof(struct list_node));
    list->x = i;
    list->next = NULL;
    push_to_stack(&stack,list);
  }
  
  struct list_node *list = NULL;
  
  // depth first search, pop first list on stack, push all potentials on, rinse/repeat
  while(stack != NULL) {
    //print_stack(stack);
    pop_from_stack(&stack, &list);

    // check for solutions
    if(length(list) == n) {
      count++;
      free_list(&list);
      continue;
    }
    
    // push potentials onto stack
    int i;
    for(i = 0; i < n; i++) {
      if(contains(list, i) == false && check_diagonals(list, i) == false) {
        struct list_node *new_list = NULL;
        copy_list(list, &new_list); 
        push_to_list(new_list, i);

        push_to_stack(&stack, new_list);
      }
    }
    free_list(&list);
  }

  printf("found %d distinct solutions\n",count);
  return 0;
}

void free_list(struct list_node **list) {
  struct list_node *temp = *list;  
  while(*list != NULL) {
    temp = *list;
    *list = (*list)->next;
    free(temp);
  }
  list = NULL;
}

bool contains(struct list_node *list, int x) {
  while(list != NULL) {
    if(list->x == x) return true;
    list = list->next;
  }
  return false;
}

int length(struct list_node *list) {
  int c_count = 0;
  if(list == NULL) return 0;
  struct list_node *temp = list;
  while(temp != NULL) {
    c_count++;
    temp = temp->next;
  }
  return c_count;
}

// put on end of list (copy list depends on that)
void push_to_list(struct list_node *list, int x) {
  struct list_node *new_node = (struct list_node *) malloc(sizeof(struct list_node));
  new_node->x = x; 
  new_node->next = NULL;
  
  while(list->next != NULL) {
    list = list->next; 
  }

  list->next = new_node;
}

void copy_list(struct list_node *source, struct list_node **dest) {
  if(source == NULL) return;

  *dest = (struct list_node *) malloc(sizeof(struct list_node));  
  struct list_node *temp = source; 

  (*dest)->x = temp->x;
  (*dest)->next = NULL;

  temp = temp->next; 

  while(temp != NULL) {
    push_to_list(*dest,temp->x);
    temp = temp->next;
  }
}

void push_to_stack(struct stack_node **stack, struct list_node *list) {
  struct stack_node *new_node = (struct stack_node *) malloc(sizeof(struct stack_node));
  new_node->next = *stack;
  new_node->list = list;

  *stack = new_node;
}

void pop_from_stack(struct stack_node **stack, struct list_node **list) {
  *list = ((*stack)->list);
  struct stack_node *temp = *stack;
  *stack = ((*stack)->next);

  free(temp);
}

bool check_diagonals(struct list_node *b, int x) {
  int len = length(b);
  int u = x + len; 
  int d = x - len;
  while(b != NULL) {
    if(u == b->x || d == b->x) {
      return true;
    }
    u--;
    d++;
    b = b->next;
  }
  return false;
}

void print_stack(struct stack_node *stack) {
  while(stack->next != NULL) {
    struct list_node *temp = stack->list;
    while(temp != NULL) {
      printf(" %d ", temp->x);
      temp = temp->next;
    }
    printf("\n");
    stack = stack->next;
  }
}

void print_board(struct list_node *list) {
}

