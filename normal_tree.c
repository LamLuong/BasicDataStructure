#include <stdio.h>
#include <stdlib.h>

struct _Node {
  int value;
  struct _Node* first_left_child;
  struct _Node* next_neighbor;
};

typedef struct _Node Node;

Node * AddChildNode(Node *node, int val);
Node* GetNodeByPreOrder(Node* node, int input_val);

void PreOrderTraversal(Node *node);

int main(int argc, char* argv[]) {
  Node *root = (Node*)malloc(sizeof(Node));
  root->value = 5;
  
  Node* node_1 = AddChildNode(root, 7);
  Node* node_2 = AddChildNode(root, 8);
  Node* node_3 = AddChildNode(root, 2);
  Node* node_4 = AddChildNode(root, 12);
  
  AddChildNode(node_1, 112);
  Node* node_1_1 = AddChildNode(node_1, 147);
  AddChildNode(node_1_1, 14);
  AddChildNode(node_1_1, 113);
  
  AddChildNode(node_2, 72);
  
  AddChildNode(node_3, 89);
  AddChildNode(node_3, 99);
  Node* node_3_1 = AddChildNode(node_3, 109);
  AddChildNode(node_3_1, 74);
  AddChildNode(node_3_1, 63);
  AddChildNode(node_3_1, 69);
  AddChildNode(node_3_1, 72);
  
  AddChildNode(node_4, 12);
  AddChildNode(node_4, 69);
  AddChildNode(node_4, 27);
  
  PreOrderTraversal(root);
  printf("\n");
  //Node* node_a = GetNodeByPreOrder()
  
  return 0;
}

Node* GetNodeByPreOrder(Node* node, int input_val) {
  if (!node)
    return node;

  while (node) {
    if (node->value == input_val) {
      return node;
    }

    Node* check_child_node = GetNodeByPreOrder(node->first_left_child, input_val);

    if (!check_child_node)
      return check_child_node;

    node = node->next_neighbor;
  }

  return NULL;
}

Node *AddChildNode(Node *node, int val) {
  if (node == NULL) {
    printf("Parent node could not be null.\n");
    return NULL;
  }
  
  Node *new_node = (Node*)malloc(sizeof(Node));
  new_node->value = val;
  
  if (!node->first_left_child) {
    node->first_left_child = new_node;
    return new_node;
  }
  
  Node *current_child_node = node->first_left_child;
  while (current_child_node->next_neighbor) {
    current_child_node = current_child_node->next_neighbor;
  }
  
  current_child_node->next_neighbor = new_node;
  return new_node;
}

void PreOrderTraversal(Node *node) {
  if (!node)
    return;
    
  while (node) {
    printf("%d, ", node->value);
    PreOrderTraversal(node->first_left_child);   
    node = node->next_neighbor;
  }
}






