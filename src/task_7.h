#include <iostream>

struct Node {
  int data;
  bool color;
  int height; 
  Node* left;
  Node* right;
  Node* parent;

  Node(int data, bool color = false, Node* parent = nullptr) : data(data), color(color), height(0), left(nullptr), right(nullptr), parent(parent) {}
};

class RedBlackTree {
public:
  // Constructor
  RedBlackTree() : root(nullptr) {}

  // Insert a new node
  void Insert(int data) {
    Node* newNode = new Node(data);
    insertNode(root, newNode);
    insertFix(newNode);
  }

  // Print the tree recursively
  void printTree(Node* node) {
    if (node) {
      std::cout << node->data << (node->color ? " (red)" : " (black)") << std::endl;
      if (node->left) {
        printTree(node->left);
      }
      if (node->right) {
        printTree(node->right);
      }
    }
  }

  void search(int data) {
    Node* foundNode = searchNode(data);
    if (foundNode) {
      std::cout << data << " is found, its height is " << foundNode->height << std::endl;
    } else {
      std::cout << data << " is not found" << std::endl;
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
      newNode->height = 1; 
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

  int searchValue;
  std::cin >> searchValue;
  tree.search(searchValue);

  return 0;
}