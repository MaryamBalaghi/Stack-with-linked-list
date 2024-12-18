#include <iostream>
using namespace std;
class node
{
    friend class Stack_linked;
    int data;
    node* next;
};
class Stack_linked
{
    private:
    node* mytop;
    public:
    Stack_linked();       
    ~Stack_linked();
    bool Is_empty();
    void Push(int x);
    int Pop();
    int Top();
};
Stack_linked ::Stack_linked()
{
    mytop=nullptr;
}
Stack_linked::~Stack_linked()
{
    node* temp=mytop;
    while (temp!=nullptr)
    {
        mytop=mytop->next;
        delete temp;
        temp=mytop;
    }
}
bool Stack_linked::Is_empty()
{
    if(mytop==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Stack_linked::Push(int x)
{
    node* newnode= new node;
    newnode->data=x;
    newnode->next=mytop;
    mytop=newnode;
}
int Stack_linked::Pop()
{
    if(Is_empty())
    {
        cout<<"This Stack is empty. No any element for pop.\n";
        return -1;
    }
    int x=mytop->data;
    node* temp=mytop;
    
    mytop=mytop->next;
    
    delete temp;
    return x;
}
int Stack_linked::Top()
{
    if(Is_empty())
    {
        cout<<"This Stack is empty. No any element for Top.\n";
        return -1;
    }
    return mytop->data;
}
int main()
{
    Stack_linked myStack;
    cout<<"+++++Guide+++++\n";
    cout<<"1 for Push\n";
    cout<<"2 for Pop\n";
    cout<<"3 for Top\n";
    cout<<"4 for cheking that an stack is empty?\n";
    bool Continue=true;
    int c,x,v;
    char m;
    while (Continue)
    {
        cout<<"Please enter your choice: ";
        cin>>c;
        switch (c)
        {
        case 1:
            cout<<"Please enter your number: ";
            cin>>x;
            myStack.Push(x);
            cout<<"Push done.\n";
            break;
        case 2:
            v=myStack.Pop();
            if(v!=-1)
            cout<<"Top element is "<<v<<",And this element was extracted from the stack.\n";
            break;
        case 3:
            if(myStack.Top()!=-1)
            cout<<"Top element is "<<myStack.Top()<<"\n";
            break;
        case 4:
            if (myStack.Is_empty()) cout<<"This Stack is empty.\n";
            else cout<<"This Stack has several element.\n";
            break;
        default:
            cout<<"Invalid choice, try again.\n";
            break;
        }
        cout<<"Do you want continue?(y/n)";
        cin>>m;
        Continue = (m == 'y' || m == 'Y');
    }
    return 0;
}