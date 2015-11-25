#import "AVLTree.h"


int main(void)
{
    AVLtree<int> t;
 
    std::cout << "Inserting integer values 1 to 10" << std::endl;
    for (int i = 1; i <= 100; ++i)
        t.insert(i);
 
    std::cout << "Printing tree \n: ";
//     t.printBalance();
	t.inOrder();
}
