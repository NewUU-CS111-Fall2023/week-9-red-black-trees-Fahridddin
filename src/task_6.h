#include <iostream>

struct Node {
  int data;
  bool color; 
  int blackHeight; 
  Node* left;
  Node* right;
  Node* parent;

  Node(int data, bool color = false, Node* parent = nullptr) : data(data), color(color), blackHeight(0), left(nullptr), right(nullptr), parent(parent) {}
};

class RedBlackTree {
public:
  RedBlackTree() : root(nullptr) {}

  void Insert(int data) {
    Node* newNode = new Node(data);
    insertNode(root, newNode);
    insertFix(newNode);
  }

  void printTreeWithBlackHeight(Node* node) {
    if (node) {
      std::cout << node->data << (node->color ? " (red)" : " (black)") << " - black height: " << node->blackHeight << std::endl;
      if (node->left) {
        printTreeWithBlackHeight(node->left);
      }
      if (node->right) {
        printTreeWithBlackHeight(node->right);
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
      newNode->blackHeight = 1; 
      return;
    }
    if (newNode->data < parent->data) {
      parent->left = newNode;
      newNode->parent = parent;
    } else {
      parent->right = newNode;
      newNode->parent = parent;
    }
    updateBlackHeights(parent, newNode);
  }

  void updateBlackHeights(Node* node, Node* insertedNode) {
    if (node) {
      if (insertedNode->color && node->color) {
        node->blackHeight++;
      }
      updateBlackHeights(node->left, insertedNode);
      updateBlackHeights(node->right, insertedNode);
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

  tree.printTreeWithBlackHeight(tree.root);

  return 0;
}