#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename Type, typename Vector>class RedBlackNode {
public:
  Type key;
  // key to index a value
  Vector value;
  // values for a key
  RedBlackNode * left;
  // left child
  RedBlackNode * right;
  // right child
  RedBlackNode * parent;
  // node's parent
  bool red;
  // is node red
  bool visited;
  // is node visited, useful when searching
  RedBlackNode(Type key, Type init_value):key(key), left(NULL), right(NULL), parent(NULL), red(true), visited(false) {
    // set up bare bones node
    value.push_back(init_value);
  }
  RedBlackNode(Type key, Type init_value, bool red):key(key), left(NULL), right(NULL), parent(NULL), red(red), visited(false) {
    // set up bare bones node
    value.push_back(init_value);
  }
  RedBlackNode(Type key, Type init_value, RedBlackNode * left, RedBlackNode * right, RedBlackNode * parent, bool red, bool visited):key(key), left(left), right(right), parent(parent), red(red), visited(visited) {
    // set up node
    value.push_back(init_value);
  }
};

template<class Node, typename Str>class RedBlackTree {
public:
  RedBlackTree():root(NULL) {}
  ~RedBlackTree() {
    make_empty(root);
    delete root;
  }
  void insert(Str key, Str value) {
    // insert key and value
    insert(key, value, root);
  }
  void remove(Str key) {
    // remove node from tree
    remove(key, root);
  }
  Node * find(Str key) {
    // find a node givem a key
    return find(key, root);
  }
  Node * get_root() {
    // get root
    return root;
  }
  void visited(Str key, bool flag = true) {
    // mark node as visited
    Node * found = find(key, root);

    if(found) found->visited = flag;
  }
  bool is_visited(Str key, bool def = true) {
    // see if node is visited
    Node * found = find(key, root);

    return (found) ? found->visited : def;    
  }
  template<typename Visitor>void walk(Visitor * visitor) {
    // walk the tree preorder
    walk(visitor, root);
  }
private:
  Node * root;
  void insert(Str key, Str value, Node * & root) {
    // insert key and value to the tree
    Node * inserted = new Node(key, value), * walk = root;
    if(!root) {
      root = inserted;
    } else {
      while(true) {
        if(key == walk->key) {
          walk->value.push_back(value);
          return;
        } else if(key < walk->key) {
          if(!walk->left) {
            walk->left = inserted;
            break;
          } else walk = walk->left;
        } else {
          if(!walk->right) {
            walk->right = inserted;
            break;
          }
          else walk = walk->right;
        }
      }
      inserted->parent = walk;
    }
    insert_case1(inserted, root);
  }
  void insert_case1(Node * inserted, Node * & root) {
    // there is only root
    if(!inserted->parent) inserted->red = false;
    else {
      insert_case2(inserted, root);
    }
  }
  void insert_case2(Node * inserted, Node * & root) {
    // parent is black, single child
    if(!is_red(inserted->parent)) return;
    else {
      insert_case3(inserted, root);
    }
  }
  void insert_case3(Node * inserted, Node * & root) {
    // parent and uncle are red, flip colors
    Node * my_uncle = uncle(inserted), * my_grandparent = grandparent(inserted);
    if(!my_uncle || !my_grandparent) return;
    // if there is no uncle or grandparent don't do anything
    if(is_red(my_uncle)) {
      inserted->parent->red = false;
      my_uncle->red = false;
      my_grandparent->red = true;
      insert_case1(my_grandparent, root);
    } else {
      insert_case4(inserted, root);
    }
  }
  void insert_case4(Node * inserted, Node * & root) {
    // put things in right place, do rotations
    Node * my_grandparent = grandparent(inserted);
    if(!my_grandparent) return;
    if(inserted == inserted->parent->right && inserted->parent == my_grandparent->left) {
      rotate_with_right_child(inserted->parent, root); // todo rotate with right ch
      inserted = inserted->left;
    } else if(inserted == inserted->parent->left && inserted->parent == my_grandparent->right) {
      rotate_with_left_child(inserted->parent, root); // todo rotate with left ch
      inserted = inserted->right;
    }
    insert_case5(inserted, root);
  }
  void insert_case5(Node * inserted, Node * & root) {
    // adjust colors and do rotations again
    Node * my_grandparent(inserted);
    if(!my_grandparent) return;
    inserted->parent->red = false;
    my_grandparent->red = true;
    if(inserted == inserted->parent->left && inserted->parent == my_grandparent->left) {
      rotate_with_left_child(my_grandparent, root);
    } else if(inserted == inserted->parent->right && inserted->parent == my_grandparent->right) {
      rotate_with_right_child(my_grandparent, root);
    }
  }
  void remove(Str key, Node * & root) {
    // remove node from tree
    Node * there = find(key, root), * child, * predecessor;
    if(!there) return;
    if(there->left && there->right) {
      predecessor = max_key(there->left);
      if(!predecessor) return;
      there->key = predecessor->key;
      there->value = predecessor->value;
      there = predecessor;
    }
    if(!there->left || !there->right) {} else return;
    child = (!there->right) ? there->left : there->right;
    if(!is_red(there)) {
      there->red = is_red(child);
      delete_case1(there, root);
    }
    replace(there, child, root);
    if(!there->parent && child) child->red = false;
    // child is root
    delete there;
  }
  void delete_case1(Node * removed, Node * & root) {
    // there's just root, nothing to do
    if(!removed->parent) return;
    else delete_case2(removed, root);
  }
  void delete_case2(Node * removed, Node * & root) {
    // node and brother are red, flip colors, make them black and parent red
    Node * my_brother = brother(removed);
    if(!my_brother) return;
    if(is_red(my_brother)) {
      removed->parent->red = true;
      my_brother->red = false;
      if(removed == removed->parent->left) rotate_with_right_child(removed->parent, root);
      else rotate_with_left_child(removed->parent, root);
    }
    delete_case3(removed, root);
  }
  void delete_case3(Node * removed, Node * & root) {
    // brother has black children, make him red
    Node * my_brother = brother(removed);
    if(!my_brother) return;
    if(!is_red(removed->parent) && !is_red(my_brother) && !is_red(my_brother->left) && !is_red(my_brother->right)) {
      my_brother->red = true;
      delete_case1(removed->parent, root);
    } else delete_case4(removed, root);
  }
  void delete_case4(Node * removed, Node * & root) {
    // same like previous, but parent is red
    Node * my_brother = brother(removed);
    if(!my_brother) return;
    if(is_red(removed->parent) && !is_red(my_brother) && !is_red(my_brother->left) && !is_red(my_brother->right)) {
      my_brother->red = true;
      removed->parent->red = false;
    } else delete_case5(removed, root);
  }
  void delete_case5(Node * removed, Node * & root) {
    // brother has red child, make child black
    Node * my_brother = brother(removed);
    if(!my_brother) return;
    if(removed == removed->parent->left && !is_red(my_brother) && is_red(my_brother->left) && !is_red(my_brother->right)) {
      my_brother->red = true;
      my_brother->left->red = false;
      rotate_with_left_child(my_brother, root);
    } else if(removed == removed->parent->right && !is_red(my_brother) && is_red(my_brother->right) && !is_red(my_brother->left)) {
      my_brother->red = true;
      my_brother->right->red = false;
      rotate_with_right_child(my_brother, root);
    }
    delete_case6(removed, root);
  }
  void delete_case6(Node * removed, Node * & root) {
    // make parent black
    Node * my_brother = brother(removed);
    if(!my_brother) return;
    my_brother->red = is_red(removed->parent);
    removed->parent->red = false;
    if(removed == removed->parent->left) {
      if(!is_red(my_brother->right)) return;
      my_brother->right->red = false;
      rotate_with_right_child(removed->parent, root);
    } else {
      if(!is_red(my_brother->left)) return;
      my_brother->left->red = false;
      rotate_with_left_child(removed->parent, root);
    }
  }
  void rotate_with_right_child(Node * & inserted, Node * & root) {
    // rotate with right child
    Node * return_node = inserted->right;
    replace(inserted, return_node, root);
    inserted->right = return_node->left;
    return_node->left = inserted;
    inserted->parent = return_node;
    inserted = return_node;
  }
  void rotate_with_left_child(Node * & inserted, Node * & root) {
    // rotate with left child
    Node * return_node = inserted->left;
    replace(inserted, return_node, root);
    inserted->left = return_node->right;
    return_node->right = inserted;
    inserted->parent = return_node;
    inserted = return_node;
  }
  void replace(Node * prev_child, Node * current_child, Node * & root) {
    // replace child
    if(!prev_child->parent) root = current_child;
    else {
      if(prev_child == prev_child->parent->left) prev_child->parent->left = current_child;
      else prev_child->parent->right = current_child;
    }
    if(current_child) current_child->parent = prev_child->parent;
  }
  bool is_red(Node * inserted) {
    // see if node is red
    return (inserted) ? inserted->red : false;
  }
  Node * uncle(Node * inserted) {
    // get uncle
    if(!inserted) return NULL;
    if(!inserted->parent) return NULL;
    if(!inserted->parent->parent) return NULL;
    return brother(inserted->parent);
  }
  Node * brother(Node * inserted) {
    // get brother
    if(!inserted) return NULL;
    if(!inserted->parent) return NULL;
    return (inserted == inserted->parent->left) ? inserted->parent->right : inserted->parent->left;
  }
  Node * grandparent(Node * inserted) {
    // grandparent
    if(!inserted) return NULL;
    if(!inserted->parent) return NULL;
    if(!inserted->parent->parent) return NULL;
    return inserted->parent->parent;
  }
  Node * max_key(Node * inserted) {
    // get max key
    if(!inserted) return NULL;
    while(inserted->right) inserted = inserted->right;
    return inserted;
  }
  Node * min_key(Node * inserted) {
    // get min key
    if(!inserted) return NULL;
    while(inserted->left) inserted = inserted->left;
    return inserted;
  }
  void make_empty(Node * & root) {
    // make tree empty
    if(root) {
      make_empty(root->left);
      make_empty(root->right);
      delete root;
    }
    root = NULL;
  }
  Node * find(Str key, Node * & root) {
    // find a node given a key
    Node * to_look = root;
    while(to_look) {
      if(key == to_look->key) return to_look;
      if(key < to_look->key) to_look = to_look->left;
      else to_look = to_look->right;
    }
    return NULL;
  }
  template<typename Visitor>void walk(Visitor * visitor, Node * & root) {
    // walk the tree preorder
    if(root) {
      walk(visitor, root->left);
      visitor->visit(root);
      walk(visitor, root->right);
    }
  }
};
// Every node is either black or red
// Every leaf is black
// If a node is red both children are black
// Every path from node to leaf contains same number of black nodes
// Based on 2, 4 (2, 3, 4) tree
// logn time

void printOptions(){
  cout<<"1 : Insert\n";
  cout<<"2 : Find\n";
  cout<<"3 : Erase\n";
  cout<<"4 : Exit\n";

}
int main() {
  RedBlackTree<RedBlackNode<string, vector<string> >, string> * tree = new RedBlackTree<RedBlackNode<string, vector<string> >, string>();  
  int opt = -1;
  printOptions();
  while(opt != 4){
    cout<<"Enter option : ";
    cin>>opt;
    switch(opt){
      case 1:{
        string k,v;
        cout<<"Enter key and value : ";
        cin>>k>>v;
        tree->insert(k,v);
        break;
      }
      case 2:{
        RedBlackNode<string, vector<string> > * found;
        string k,v;
        cout<<"Enter key to find : ";
        cin>>k;
        found = tree->find(k);
        v = (found) ? found->value[0] : "Key Not found";
        cout<<v<<endl;
        break;
      }
      case 3:{
        string k,v;
        cout<<"Enter key to erase : ";
        cin>>k;
        RedBlackNode<string, vector<string> > * found;
        found = tree->find(k);
        v = (found) ? found->value[0] : "Key Not Found";
        if(v == "Key Not Found") cout<<"Key Not Found\n";
        else 
          tree->remove(k);
      }
      case 4:{
        break;
      }
    }
  }

  // funny thing infinite loop without balance
  delete tree;
  return 0;
}
