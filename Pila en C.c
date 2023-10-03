#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definición de la estructura de la pila
typedef struct Stack {
    Node* top;
} Stack;

// Función para crear una nueva pila vacía
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        perror("Error al crear la pila");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

// Función para verificar si la pila está vacía
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Función para empujar un elemento a la pila
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Error al agregar un elemento a la pila");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Función para sacar un elemento de la pila
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Función para obtener el elemento en la cima de la pila sin sacarlo
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

// Función para imprimir los elementos de la pila
void printStack(Stack* stack) {
    Node* current = stack->top;
    printf("Elementos de la pila: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Función principal
int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Elemento en la cima de la pila: %d\n", peek(stack));

    printf("Elementos de la pila:\n");
    printStack(stack);

    printf("Elemento desapilado: %d\n", pop(stack));
    printf("Elementos de la pila después de desapilar:\n");
    printStack(stack);

    free(stack); // Liberar la memoria de la pila

    return 0;
}
