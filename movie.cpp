#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    string m_name;
    int  m_point;
    Node* next;
    Node* prev;

public:
    Node()
    {
        next= nullptr;
        prev = nullptr;
    }
    Node(string name, int point, Node* n): m_name(name), m_point(point)
    {
        next = n;
    }
    Node(string name, int point):m_name(name), m_point(point)
    {
        next = nullptr;
        prev = nullptr;
    }
};

class DataList
{
    Node* head;
    Node* tail;

public:
    DataList()
    {
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    void push_front(string name, int point)
    {        
        head = new Node(name, point, head);
    }

    void push_back(string name, int point)     
    {
        hangnode( name,  point, tail);
    }

    void hangnode(string name, int point, Node* pos)
    {
        Node* p=  new Node(name, point);

        p->prev = pos->prev;
        p->next = pos;

        pos->prev->next = p;
        pos->prev = p;

    }

    void print_all_items( ) 
    {
        Node*p = head->next;

        while(p->next!= nullptr)
        {
            cout<<p->m_name<<endl;
            cout<<p->m_point<<endl;
            p=p->next;
        }
    }


};

DataList mydata;

bool file_read(string name)
{
    string filename;
    string rdata;
    ifstream ifs;
    int len;

     

    ifs.open(name);

    if (!ifs) return false;

    getline(ifs,rdata );
    len = stoi(rdata);
   
    cout<<"length"<<len<<endl;
    for (int i = 0 ; i <len ; i++)
    {
        string temp_name;
        int temp_point;

        getline(ifs, rdata);
       temp_name = rdata;

        getline(ifs, rdata);
        temp_point = stoi(rdata);

        cout<<temp_name<<" " <<temp_point<<endl;
        
       mydata.push_back(temp_name, temp_point);
        
    }

    return true;

}

void print_menu()
{
    cout<<endl;
    cout<<"Please select an option and press enter.\n"<<endl;
    cout<<" 1. Print all items "<< "\t\t\t"<< "2.Print an item"<<endl;
    cout<<" 3. Edit an item      "<<"\t\t\t"<< "4.Add an item"<<endl;
    cout<<" 5. Insert an items "<<"\t\t\t"<< "6.Delete an item"<<endl;
    cout<<" 7. Delete all items"<<"\t\t\t"<<"8.Save file"<<endl;
    cout<<" 9. Search by  name  "<<"\t\t\t"<< "10.Quit"<<endl;

}

void print_all_items()
{
    mydata.print_all_items();
}

void quit()
{
    exit(1);
}

int main()
{
    string filename;

    cout<<"please input filename to read and press Enter"<<endl;
    cout<<">> ";
    cin>> filename;

    if (file_read(filename))   print_menu();
    else cout << " file open error!!!" <<endl;

    while(1)
    {
        int cmd;
        cout<<">> ";
        cin>>cmd;

        switch(cmd)
        {
            case 1:
                print_all_items();
                break;

            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:

            case 10:             quit();            break;

            default:
                cout<<"unknown number"<<endl;
        }


         print_menu();
    }


    return 0;   
    
}