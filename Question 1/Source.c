#include <stdio.h>
#include <stdlib.h>


typedef enum TypeTag {
/* Define the TypeTag enum to represent the different types of operations
 *  that can be performed on the values in the Node struct. These include
 * addition, subtraction, multiplication, division, and the Fibonacci sequence. 
 */
    ADD, SUB, MUL, DIV, FIBO
} TypeTag;


typedef struct Node {
 /* Define the Node struct to represent a node in an arithmetic expression tree.
  * It contains the type of operation to be performed on its two values (TypeTag),
  * the first value (value1), the second value (value2), and the result of the operation
  * (result)
  */ 
    TypeTag type;
    int value1;
    int value2;
    int result;
} Node;


Node* makeValue(int value) {
    /* Create a new Node struct that represents a single value The node is allocated dynamically
     * using malloc()and initialized with the given value. The type of the node is set to -1, which
     * indicates that it is not an operator node.
     */
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = -1;
    node->value1 = value;
    return node;
}


Node* makeAdd(int leftValue, int rightValue) {
    /**
    * Allocates memory for a new Node struct representing an addition operation
    * with the specified left and right operand values.
    * 
    * @param leftValue the value of the left operand
    * @param rightValue the value of the right operand
    * @return a pointer to the newly created Node struct
    */
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = ADD;
    node->value1 = leftValue;
    node->value2 = rightValue;
    return node;
}

Node* makeSub(int leftValue, int rightValue) {
    /**
     *  Allocates memory for a new Node struct with type set to SUB
     * 
     * @param leftValue an integer representing the left operand
     * @param rightValue an integer representing the right operand
     * @return a pointer to a newly created Node struct
     */
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = SUB;
    node->value1 = leftValue;
    node->value2 = rightValue;
    return node;
}


Node* makeMul(int leftValue, int rightValue) {
    /**
     * Creates a new node representing the multiplication of two values.
     * 
     * @param leftValue The value on the left side of the multiplication.
     * @param rightValue The value on the right side of the multiplication.
     * @return A pointer to the new node.
     */
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = MUL;
    node->value1 = leftValue;
    node->value2 = rightValue;
    return node;
}

Node* makeDiv(int leftValue, int rightValue) {
    /**
    * Creates a new node representing a division operation with the specified left and right
    * operand values. Allocates memory for the new node on the heap.
    * 
    * @param leftValue: the value of the left operand
    * @param rightValue: the value of the right operand
    * @return a pointer to the newly created Node struct
    */
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = DIV;
    node->value1 = leftValue;
    node->value2 = rightValue;
    return node;
}


Node* makeFibo(int n) {
    /**
     * Allocates memory for a new Node struct with type set to FIBO and value1 set to n.
     * The second parameter is unused, but included for consistency with other functions.
     * Returns a pointer to the newly created Node.
     * 
     * @param n: the value of the input parameter to the Fibonacci function
     * @return a pointer to a newly created Node struct
     */
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = FIBO;
    node->value1 = n;
    return node;
}

Node* (*makeFunc(TypeTag type))(int, int) {
    /**
     * Returns a function pointer to one of the make functions based on the given TypeTag.
     * 
     * @param type: the TypeTag value to determine the appropriate make function.
     * @return a function pointer to the corresponding make function.
     */
    Node* (*func)(int, int) = NULL;
    switch (type) {
    case ADD:
        func = makeAdd;
        break;
    case SUB:
        func = makeSub;
        break;
    case MUL:
        func = makeMul;
        break;
    case DIV:
        func = makeDiv;
        break;
    case FIBO:
        func = makeFibo;
        break;
    default:
        break;
    }
    return func;
}

int calc(Node* node) {
    /**
     * Calculates the result of the arithmetic operation represented by the given Node.
     *
     * @param node: pointer to the Node struct representing the arithmetic operation to be calculated.
     * @return the result of the arithmetic operation as an integer value.
     */
    if (node == NULL) return 0;

    switch (node->type) {
    case ADD:
        node->result = node->value1 + node->value2;
        break;
    case SUB:
        node->result = node->value2 - node->value1;
        break;
    case MUL:
        node->result = node->value1 * node->value2;
        break;
    case DIV:
        node->result = node->value1 / node->value2;
        break;
    case FIBO: {
        int n1 = 0, n2 = 1, n3 = 0, i, number;
        number = node->value1;
        if(number < 0 )
            number = number * -1;
        for (i = 2; i < number; ++i)
        {
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        node->result = n3;
        break;

    }
    default:
        node->result = 0;
        break;
    }
    return node->result;
}


int main() {
    Node* add = (*makeFunc(ADD))(10, 6);
    Node* mul = (*makeFunc(MUL))(5, 4);
    Node* sub = (*makeFunc(SUB))(calc(mul), calc(add));
    Node* fibo = (*makeFunc(FIBO))(calc(sub), NULL);

    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

    while (1) {

    }
    return 0;
}