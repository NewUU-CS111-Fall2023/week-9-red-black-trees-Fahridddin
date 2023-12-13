#include <iostream>

struct Node {
  int data;
  bool color; 
  int childrenCount; 
  Node* left;
  Node* right;
  Node* parent;

  Node(int data, bool color = false, Node* parent = nullptr) : data(data), color(color), childrenCount(0), left(nullptr), right(nullptr), parent(parent) {}
};

class RedBlackTree {
public:
  RedBlackTree() : root(nullptr) {}

  void Insert(int data) {
    Node* newNode = new Node(data);
    insertNode(root, newNode);
    insertFix(newNode);
  }

  void printTreeWithChildren(Node* node) {
    if (node) {
      std::cout << node->data << (node->color ? " (red)" : " (black)") << " - children: " << node->childrenCount << std::endl;
      if (node->left) {
        printTreeWithChildren(node->left);
      }
      if (node->right) {
        printTreeWithChildren(node->right);
      }
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
    updateChildrenCount(parent);
  }
  void updateChildrenCount(Node* node) {
    if (node) {
      node->childrenCount = 1;
      if (node->left) {
        node->childrenCount += node->left->childrenCount;
      }
      if (node->right) {
        node->childrenCount += node->right->childrenCount;
      }
    }
  }
};

int main() {
  int N;
  std::cin >> N;

  RedBlackTree tree;
  for (int i = 0; i < N; ++i) {
    int data;
    std::cin >> data;
    tree.Insert(data);
  }

  tree.printTreeWithChildren(tree.root);

  return 0;
}