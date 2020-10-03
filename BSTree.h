#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include<iomanip>
using namespace std;

template <class DataType>
class BSTree
{
    private:
        struct node;
        typedef node *nodePtr;

        struct node
        {
            DataType element;
            nodePtr right;
            nodePtr left;
        };
        int count;
        nodePtr root;
        nodePtr newNode(DataType data)
        {
            nodePtr temp = new node;
        
            temp->element = data;
        
            temp->left = NULL;
            temp->right = NULL;
        
            return temp;
        }
        void insert(DataType y, node* t)
        {
            if(y < t->element)
            {
                
                if(t->left == NULL)
                {
                    t->left = newNode(y);
                }
                else
                {
                    insert(y, t->left);
                }
            }
            else
            {
                if(t->right == NULL)
                {
                    t->right = newNode(y);
                } 
                else
                {
                    insert(y, t->right);
                }
            }
        }
        nodePtr recurcopy(const nodePtr ct)
        {
            if (ct == NULL)
            {
		        return NULL;
            }
            nodePtr nn = newNode(ct->element);
            nn->left = recurcopy(ct->left);
            nn->right = recurcopy(ct->right);
            return nn;
        }
        void printInOrder(nodePtr n)
        {
            if(n ==NULL)
            {
                return;
            }
            printInOrder(n->left);
            cout<<n->element<<" ";
            printInOrder(n->right);
        }
        void printPreOrder(nodePtr n)
        {
            if(n ==NULL)
            {
                return;
            }
            cout<<n->element<<" ";
            printInOrder(n->left);
            printInOrder(n->right);
        }
        nodePtr deleteNode(nodePtr rt, DataType val)
        {
            if(val < rt->element)
            {
                rt->left = deleteNode(root->left, val);
            }
            else if(val > rt->element)
            {
                rt->right = deleteNode(rt->right, val);
            }
            else
            {
                if(rt->left == NULL)
                {
                    nodePtr temp = rt->right;
                    free(rt);
                    return temp;
                }
                else if(rt->right == NULL)
                {
                    nodePtr temp = rt->left;
                    free(rt);
                    return temp;
                }
                nodePtr min = rt->right;
                while(min->left!=NULL)
                {
                    min = min->left;
                }
                nodePtr temp = min;
                rt->element = temp->element;
                rt->right = deleteNode(rt->right,temp->element);
            }
            return rt;
            
        }
        void deleteTree(nodePtr r)
        {
            if(r == NULL)
            {
                return;
            }
            deleteTree(r->left);
            deleteTree(r->right);
            free(r);
        }

        void printTreeHelper(int depth, nodePtr cur) const
        {
            const int spacing = 4;
            if(cur != NULL)
            {
                if(depth == 0)
                {
                    cout << cur->element;
                }
                else
                {
                    cout << setw(spacing*depth) <<" "<< cur->element;
                }
                cout << endl;
                printTreeHelper(depth+1, cur->right);
                printTreeHelper(depth+1, cur->left);
                
            }
            else
            {
                cout << setw(spacing*depth) <<" " << "****" << endl;
            }
            
        }
        public:
            BSTree()
            {
                root = NULL;
                count = 0;
            }
            BSTree(const BSTree<DataType> &copyTree)
            {
                root = recurcopy(copyTree.root);
            }
            const BSTree& operator =(const BSTree& rhs)
            {
                root = recurcopy(rhs.root);
                BSTree temp;
                temp.root = root;
                return temp;
            }
            ~BSTree()
            {

            }
            void insert(DataType x)
            { 
                
                if(root == NULL)
                {
                    root = newNode(x);
                    
                }
                else
                {
                    insert(x, root);
                }

            }
            bool printTree() const
            {
                if(root == NULL)
                    return false;
                else
                {
                    printTreeHelper(0, root);
                    return true;   
                }
            }
            void printInOrder()
            {
                printInOrder(cout);
            }
            void printInOrder(ostream &out)
            {
                printInOrder(root);
                out<<endl;
            }
            void printPreOrder()
            {
                printPreOrder(cout);
            }
            void printPreOrder(ostream &out)
            {
                printPreOrder(root);
                out<<endl;
            }
            bool deleteNode(DataType x)
            {
                if(root==NULL)
                {
                    return false;
                }
                root = deleteNode(root, x);
                return true;
            }
            bool deleteNodePassBackData(DataType x, DataType &temp)
            {
                if(root==NULL)
                {
                    return false;
                }
                root = deleteNode(root, x);
                temp = x;
                return true;
            }
            void deleteTree()
            {
                deleteTree(root);
                root = NULL;
            }

};
#endif