#include <iostream>
struct Node {
  int data;
  bool color; 
  Node* left;
  Node* right;
  Node* parent;

  Node(int data, bool color = false, Node* parent = nullptr) : data(data), color(color), left(nullptr), right(nullptr), parent(parent) {}
};

class RedBlackTree {
public:
  RedBlackTree() : root(nullptr) {}
  void Insert(int data) {
    Node* newNode = new Node(data);
    insertNode(root, newNode);
    insertFix(newNode);
  }
  void Delete(int data) {
    Node* nodeToDelete = searchNode(data);
    if (nodeToDelete) {
      deleteNode(nodeToDelete);
      deleteFix(nodeToDelete->parent);
    } else {
      std::cout << "Node not found!" << std::endl;
    }
  }
  void printTree(Node* node) {
    if (node) {
      std::cout << node->data << (node->color ? " (red)" : " (black)");
      if (node->left) {
        std::cout << " L: " << node->left->data;
      }
      if (node->right) {
        std::cout << " R: " << node->right->data;
      }
      std::cout << std::endl;
      printTree(node->left);
      printTree(node->right);
    }
  }

private:
  Node* root;
  Node* searchNode(int data) {
    Node* current = root;
    while (current) {
      if (data == current->data) {
        return current;
      } else if (data < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    return nullptr;
  }
  void insertNode(Node* parent, Node* newNode) {
    if (!parent) {
      root = newNode;
      return;
    }
    if (newNode->data < parent->data) {
      parent->left = newNode;
      newNode->parent = parent;
    } else {
      parent->right = newNode;
      newNode->parent = parent;
    }
  }
  void deleteNode(Node* nodeToDelete) {
    if (!nodeToDelete->left && !nodeToDelete->right) {
      Node* parent = nodeToDelete->parent;
      if (parent->left == nodeToDelete) {
        parent->left = nullptr;
      } else {
        parent->right = nullptr;
      }
      delete nodeToDelete;
    } else if (nodeToDelete->left && !nodeToDelete->right) {
      Node* replacement = nodeToDelete->left;
      replacement->parent = nodeToDelete->parent;
      if (nodeToDelete->parent->left == nodeToDelete) {
        nodeToDelete->parent->left = replacement;
      } else {
        nodeToDelete->parent->right = replacement;
      }
      delete nodeToDelete;
    } else if (!nodeToDelete->left && nodeToDelete->right) {
      Node* replacement = nodeToDelete->right;
      replacement->parent = nodeToDelete->parent;
      if (nodeToDelete->parent->left == nodeToDelete) {
        nodeToDelete->parent->left = replacement;
      } else {
        nodeToDelete->parent->right = replacement;
      }
      delete nodeToDelete;
    } else {
      Node* successor = getMin(nodeToDelete->right);
      nodeToDelete->data = successor->data;
      deleteNode(successor);
    }
  }
  Node* getMin(Node* node) {
    while (node->left) {
      node = node->left;
    }
    return node;
  }
  void insertFix(Node* newNode) {
    while (newNode->parent && newNode->parent->color) {
      if (newNode->parent == newNode->parent->parent->left