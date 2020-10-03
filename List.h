#ifndef LIST_H
#define LIST_H
#include<iostream>
using namespace std;

template <class DataType>
class List
{
    private:
        struct node;
        typedef node *nodePtr;
        struct node
        {
            DataType info;
            nodePtr next;
        };
        nodePtr head;
    public:
        List()
        {
            head = NULL;
        }

        List(const List<DataType> &copyList)
        {   
            head=NULL;
            node * t=copyList.head;
            node * th=NULL;
            while(t!=NULL)
            {
                node *new_node =new node();
                new_node->info=t->info;
                new_node->next=t->next;
                th=new_node;
                if(head==NULL)
                {
                    head=th;
                }
                th=th->next;
                t=t->next;
            }

        }
        ~List()
        {

        }

        const List& operator =(const List& rhs)
        {
                
        }

        void insert(const DataType& x)
        {
            node* new_node = new node();
            new_node->info = x;
            new_node->next = NULL;
            if(head==NULL)
                head=new_node;
            else
            {
                node * temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=new_node;
            }
        }

        bool isInList(DataType x)
        {
            node *temp=head;
            while(temp->next!=NULL)
            {
                if(temp->info==x)
                {
                    return true;
                }
                temp = temp->next;
                
            }
            return false;

        }

        void printList()
        {
            printList(cout);
        }

        void printList(ostream &out)
        {
            node* t = head;
            while(t!=NULL)
            {
                out << t->info << " ";
                t = t->next;
            }
            out<<endl;
        }

        bool deleteListItem(DataType inInfo)
        {
            node* tmp = head;
            while(tmp->next!=NULL)
            {
                if(tmp->next->info==inInfo)
                 {
                    tmp->next=tmp->next->next;
                     return true;
                 }
                 tmp=tmp->next;
            }
            return false;
        }

        bool deleteAndPassBackListItem(DataType inInfo, DataType &outInfo)
        {
            node* tmp = head;
            while(tmp->next!=NULL)
            {
                if(tmp->next->info==inInfo)
                 {
                     outInfo=inInfo;
                    tmp->next=tmp->next->next;
                     return true;
                 }
                 tmp=tmp->next;
            }
            return false;
        }

        bool deleteFirstAndPassBackListItem(DataType &outInfo)
        {
            if(head==NULL)
                return false;
            outInfo=head->info;
            head=head->next;
            return true;
            
        }
        bool isEmpty()
        {
            if(head==NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
};

#endif