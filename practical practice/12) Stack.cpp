#include<iostream>
#include<string>
using namespace std;

#define MAX 10

class Stack{
    public:
    char arr[MAX];
    string a;
    int top;
    Stack(){
        top = -1;
    }
    void pop(){
        if(top == -1)
        {
            return;
        }
        top--;
    }
    void push(){
        cout<<"Enter Expression : ";
        cin>>a;
        if (top == MAX-1)
        {
            cout<<"Stack is Full"<<endl;
            return;
        }
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == '(' || a[i] == '[' || a[i] == '{')
            {
                top++;
                arr[top] = a[i];
            }
            if ((a[i] == ')' && arr[top] == '(') || (a[i] == ']' && arr[top] == '[') || (a[i] == '}' && arr[top] == '{'))
            {
                if (top == 0)
                {
                    cout<<"Incorrect"<<endl;
                    return;
                }
                pop();
            }
        }
        if (top == -1)
        {
            cout<<"Correct !!"<<endl;
        }else
        {
            cout<<"Incorrect !!"<<endl;
        }
        
    }
    void Top(){
        cout<<top;
    }
};

int main(int argc, char const *argv[])
{
    Stack s1;
    bool temp = 1;
    while (temp)
    {
        int choice;
        cout<<"1.Enter Expression : "<<endl
            <<"2.Exit"<<endl;
        cout<<"=>";
        cin>>choice;
        switch (choice)
        {
        case 1:{
            s1.push();
            break;
        }
        case 2:{
            temp = 0;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}