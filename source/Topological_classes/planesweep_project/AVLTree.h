#include <algorithm>
#include <iostream>

/* AVL node */
template<class T>
class AVLnode {
public:
    T key;
    int balance;
    AVLnode *left, *right, *parent;

    AVLnode(T k, AVLnode *p) : key(k), balance(0), parent(p),
                               left(NULL), right(NULL) { }

    ~AVLnode() {
        delete left;
        delete right;
    }
};

/* AVL tree */
template<class T>
class AVLTree {
public:
    AVLTree(void);

    ~AVLTree(void);

    bool insert(T key);

    void deleteKey(const T key);

    void printBalance();

    void inOrder();

    int sizeOfAVL();

    void getElements(T **result);

    AVLnode<T> *FindKey(const T val);

    AVLnode<T> *getPred(const T val);

    AVLnode<T> *getSucc(const T val);

private:
    AVLnode<T> *root;

    AVLnode<T> *rotateLeft(AVLnode<T> *a);

    AVLnode<T> *rotateRight(AVLnode<T> *a);

    AVLnode<T> *rotateLeftThenRight(AVLnode<T> *n);

    AVLnode<T> *rotateRightThenLeft(AVLnode<T> *n);


    void rebalance(AVLnode<T> *n);

    int height(AVLnode<T> *n);

    void setBalance(AVLnode<T> *n);

    void printBalance(AVLnode<T> *n);

    void clearNode(AVLnode<T> *n);

    void inOrder(AVLnode<T> *n);

    void inOrder1(AVLnode<T> *n, T **result, int *count);

};

