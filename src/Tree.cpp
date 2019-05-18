/* 
    TODO : Add the ability to remove nodes
    TODO : Memory Cleanup
    TODO : Add a contains bool to see if a number exists inside the binary tree
*/
#include <iostream>
#include <string>

// Used to import random numbers
#include <cstdlib>

using namespace std;

int main();

template <typename Type>
void print(Type input){
    cout<<input<<endl;

}



// template <typename Comparable>

class BinaryTree{
public:
    BinaryTree(int element){
        root = nullptr;
        subNode* node = new subNode;
        node->element = element;
        node->right = nullptr;
        node->left = nullptr;
        root = node;
    };
    ~BinaryTree(){};

    void printTreeLeft();
    void printTreeRight();
    void insertNode(int & elm);
    void findMax();
    void findMin();
    void print2D();
    void contains(int & elm);
    void size();


private:
    struct subNode
    {   
        int element;
        subNode* left;
        subNode* right;
    };

    subNode *root;
    /* 
        4 cases to handle:
        * If the tree doesn't exist, that should never happen the way I set up the code
        * if the element is smaller than the root node
        * if the element is bigger than the root node
        * Finally, if it is none of the cases above, it is going to be a duplicate and so ignore it.
    */
    void insertNode(int & elm, subNode * & t){
        if(t == nullptr){
            t = new subNode{elm, nullptr, nullptr};
        }else if(elm < t->element){
            insertNode(elm, t->left);
        }else if(t->element < elm){
            insertNode(elm, t->right);
        }else{
            // Otherwise it must be a duplicate
        }
    }

    void print2D(const std::string& prefix, subNode * & t, bool isLeft){
        if(t != nullptr){
            cout << prefix;
            cout << (isLeft ? "├──" : "└──" );

            // print the value of the node
            cout << t->element << endl;

            // enter the next tree level - left and right branch
            print2D( prefix + (isLeft ? "│   " : "    "), t->left, true);
            print2D( prefix + (isLeft ? "│   " : "    "), t->right, false);
        }
    }

    void contains(int & elm, subNode * & t){
        if(t->element == elm){
            print("true");
        }else if(t != nullptr){
            contains(elm, t->left);
            contains(elm, t->right);
        }
    }



};


int main(){
    BinaryTree tree(4);
    
    // Create Random numbers
    print("Random Numbers");
    for(int i = 0; i < 1000; i++){
        int num = (rand()%1000)+1;
        tree.insertNode(num);
    }
    int num = 3;
    tree.insertNode(num);

    // Prints the left most branch of the tree
    print("left ");
    tree.printTreeLeft();

    // Prints the right most branch of the tree
    print("right ");
    tree.printTreeRight();

    // Prints the max value
    print("MAX");
    tree.findMax();
    
    // Prints the min value
    print("MIN");
    tree.findMin();

    // Print the 2D visualization of the tree.
    tree.print2D();

    // Tells you if the tree contains a given number
    // tree.contains(num);

    return 0;
}

void BinaryTree::insertNode(int & elm){
    insertNode(elm, root);
}

/* 
    * Prints the nodes in the left branch of the tree
*/
void BinaryTree::printTreeLeft(){
    subNode* start = root;
    print(start->element);
    while(start->left != nullptr){
        start = start->left;
        print(start->element);
    }
}

/* 
    * Prints the nodes in the right branch of the tree
*/
void BinaryTree::printTreeRight(){
    subNode* start = root;
    print(start->element);
    while(start->right != nullptr){
        start = start->right;
        print(start-> element);
    }
}

/* 
    * Finds the max value in the tree
    * The max value in a bianary search tree is the leaf in the right most branch of the tree
    * This due to the way nodes are insearted into the tree 
*/
void BinaryTree::findMax(){
    subNode* start = root;
    while(start->right !=nullptr){
        start = start->right;
    }
    print(start->element);
}

/* 
    * Find the min value in the tree
    * The min value in a Binary Search tree is the  leaf in the left most branch of the tree, again due to the way nodes are inserted
*/
void BinaryTree::findMin(){
    subNode* start = root;
    while(start->left !=nullptr){
        start = start->left;
    }
    print(start->element);
}

// * Prints a 2d representation of the tree
void BinaryTree::print2D(){
    print2D("",root, false);
}

// * Checks if a element exists in a tree
void BinaryTree::contains(int & elm){
    contains(elm, root);
}

