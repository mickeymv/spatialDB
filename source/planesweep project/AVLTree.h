 #include <algorithm>
#include <iostream>
 
/* AVL node */
template <class T>
class AVLnode {
public:
    T key;
    int balance;
    AVLnode *left, *right, *parent;
 
    AVLnode(T k, AVLnode *p) : key(k), balance(0), parent(p),
                        left(NULL), right(NULL) {}
 
    ~AVLnode() {
        delete left;
        delete right;
    }
};
 
/* AVL tree */
template <class T>
class AVLTree {
public:
    AVLTree(void);
    ~AVLTree(void);
    bool insert(T key);
    void deleteKey(const T key);
    void printBalance();
    void inOrder();
    AVLnode<T>* FindKey( const T val);

private:
    AVLnode<T> *root;
    AVLnode<T>* rotateLeft          ( AVLnode<T> *a );
    AVLnode<T>* rotateRight         ( AVLnode<T> *a );
    AVLnode<T>* rotateLeftThenRight ( AVLnode<T> *n );
    AVLnode<T>* rotateRightThenLeft ( AVLnode<T> *n );
    void rebalance                  ( AVLnode<T> *n );
    int height                      ( AVLnode<T> *n );
    void setBalance                 ( AVLnode<T> *n );
    void printBalance               ( AVLnode<T> *n );
    void clearNode                  ( AVLnode<T> *n );
    void inOrder					( AVLnode<T> *n	);
};
 

/* AVL class definition */
template <class T>
void AVLTree<T>::rebalance(AVLnode<T> *n) {
    setBalance(n);
 
    if (n->balance == -2) {
        if (height(n->left->left) >= height(n->left->right))
            n = rotateRight(n);
        else
            n = rotateLeftThenRight(n);
    }
    else if (n->balance == 2) {
        if (height(n->right->right) >= height(n->right->left))
            n = rotateLeft(n);
        else
            n = rotateRightThenLeft(n);
    }
 
    if (n->parent != NULL) {
        rebalance(n->parent);
    }
    else {
        root = n;
    }
}
 
template <class T>
AVLnode<T>* AVLTree<T>::rotateLeft(AVLnode<T> *a) {
    AVLnode<T> *b = a->right;
    b->parent = a->parent;
    a->right = b->left;
 
    if (a->right != NULL)
        a->right->parent = a;
 
    b->left = a;
    a->parent = b;
 
    if (b->parent != NULL) {
        if (b->parent->right == a) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }
 
    setBalance(a);
    setBalance(b);
    return b;
}
 
template <class T>
AVLnode<T>* AVLTree<T>::rotateRight(AVLnode<T> *a) {
    AVLnode<T> *b = a->left;
    b->parent = a->parent;
    a->left = b->right;
 
    if (a->left != NULL)
        a->left->parent = a;
 
    b->right = a;
    a->parent = b;
 
    if (b->parent != NULL) {
        if (b->parent->right == a) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }
 
    setBalance(a);
    setBalance(b);
    return b;
}
 
template <class T>
AVLnode<T>* AVLTree<T>::rotateLeftThenRight(AVLnode<T> *n) {
    n->left = rotateLeft(n->left);
    return rotateRight(n);
}
 
template <class T>
AVLnode<T>* AVLTree<T>::rotateRightThenLeft(AVLnode<T> *n) {
    n->right = rotateRight(n->right);
    return rotateLeft(n);
}
 
template <class T>
int AVLTree<T>::height(AVLnode<T> *n) {
    if (n == NULL)
        return -1;
    return 1 + std::max(height(n->left), height(n->right));
}
 
template <class T>
void AVLTree<T>::setBalance(AVLnode<T> *n) {
    n->balance = height(n->right) - height(n->left);
}
 
template <class T>
void AVLTree<T>::printBalance(AVLnode<T> *n) {
    if (n != NULL) {
        printBalance(n->left);
        std::cout << n->balance << " ";
        printBalance(n->right);
    }
}
 
 template <class T>
 void AVLTree<T>::inOrder(AVLnode<T> *n) {
 if ( n != NULL ) {
       inOrder(n->left);
       //std::cout << n->balance << " ";
       std::cout << n->key << " ";
       inOrder(n->right);
    }
   
}
 template <class T>
AVLTree<T>::AVLTree(void) : root(NULL) {}
 
template <class T>
AVLTree<T>::~AVLTree(void) {
    delete root;
}
 
template <class T>
bool AVLTree<T>::insert(T key) {
    if (root == NULL) {
        root = new AVLnode<T>(key, NULL);
    }
    else {
        AVLnode<T>
            *n = root,
            *parent;
 
        while (true) {
            if (n->key == key)
                return false;
 
            parent = n;
 
            bool goLeft = n->key > key;
            n = goLeft ? n->left : n->right;
 
            if (n == NULL) {
                if (goLeft) {
                    parent->left = new AVLnode<T>(key, parent);
                }
                else {
                    parent->right = new AVLnode<T>(key, parent);
                }
 
                rebalance(parent);
                break;
            }
        }
    }
 
    return true;
}

template <class T>
 AVLnode<T>* AVLTree<T>::FindKey(const T val) {
     if ( root != NULL ) {
		 AVLnode<T> *n = root;
    	 
		 while(n) {
			 if(n->key == val)
				 return n;			
			 if(n->key > val)
				 n = n->left;
			 else
				 n = n->right;
			 }
		 }
    return(NULL);   
}

template <class T>
void AVLTree<T>::deleteKey(const T delKey) {
    if (root == NULL)
        return;
 
    AVLnode<T>
        *n       = root,
        *parent  = root,
        *delNode = NULL,
        *child   = root;
 
    while (child != NULL) {
        parent = n;
        n = child;
        child = delKey >= n->key ? n->right : n->left;
        if (delKey == n->key)
            delNode = n;
    }
 
    if (delNode != NULL) {
        delNode->key = n->key;
 
        child = n->left != NULL ? n->left : n->right;
 
        if (root->key == delKey) {
            root = child;
        }
        else {
            if (parent->left == n) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
 
            rebalance(parent);
        }
    }
}

template <class T>
void AVLTree<T>::inOrder() {
	inOrder(root);
	std::cout << std::endl;
}
 
template <class T>
void AVLTree<T>::printBalance() {
    printBalance(root);
    std::cout << std::endl;
}