#include "OrgChart.hpp"
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;
using namespace ariel;

OrgChart::~OrgChart()
{
}
vector<string>::iterator return_vec() // return vector of iterator
{
    vector<string>::iterator vec;
    return vec;
}

OrgChart &OrgChart::add_root(string root)
{
    // his->sizeofTree++;
    if (!this->root)
    {
        this->sizeofTree++;
        this->root = new TNode(root);
        return *this;
    }
    // this->sizeofTree++;
    this->root->value = root;
    return *this;
}

OrgChart &OrgChart::add_sub(string root, string sub)
{

    TNode *f = find_root(root);

    if (f == NULL)
    {
        throw runtime_error("root not exist");
    }
    this->sizeofTree++;
    // cout << this->root->value << endl;
    TNode *s = new TNode(sub);
    // cout <<s->value << endl;
    f->subs.push_back(s);
    return *this;
}

ostream &ariel::operator<<(ostream &out, const OrgChart &p)
{
    return out;
}
OrgChart::TNode *OrgChart::getroot()
{
    return root;
}
vector<OrgChart::TNode *> OrgChart::it_preorder()
{
    stack<TNode *> Stack;

    vector<TNode *> Preorders_nodes; // visited nodes

    Stack.push(getroot());
    // cout << this->sizeofTree << endl;
    while (!Stack.empty())
    {
        TNode *temp = Stack.top();
        // cout << temp->value << endl;
        Stack.pop();

        Preorders_nodes.push_back(temp);
        // cout << temp->subs.size() << endl;
        for (size_t i = temp->subs.size(); i > 0; i--) // the stack from right to left
        {
            // cout << temp->subs.size() << endl;
            // cout  << i << endl;
            Stack.push(temp->subs[i - 1]);
        }
    }
    return Preorders_nodes;
}
OrgChart::TNode *OrgChart::find_root(string m)
{

    vector<TNode *> iter = it_preorder();

    TNode *t = NULL;
    for (auto i : iter)
    {

        if (m == i->value)
        {
            TNode *t = i;

            return i;
        };
    }

    return t;
}
void OrgChart::printNTree()
{
    TNode *x = this->root;
    unsigned long size = (unsigned long)this->sizeofTree;
    vector<bool> flag(size, true);
    printNTree_help(x, flag, 0, false);
}
void OrgChart::printNTree_help(TNode *x, vector<bool> flag, int depth = 0, bool isLast = false)

{

    if (x == NULL)
        return;

    // Loop to print

    for (size_t i = 1; i < depth; ++i)
    {

        if (flag[i] == true)
        {
            cout << "| "
                 << " "
                 << " "
                 << " ";
        }

        else
        {
            cout << " "
                 << " "
                 << " "
                 << " ";
        }
    }

    if (depth == 0)
        cout << x->value << '\n';

    else if (isLast)
    {
        cout << "+--- " << x->value << '\n';

        flag[(size_t)depth] = false;
    }
    else
    {
        cout << "+--- " << x->value << '\n';
    }

    int it = 0;
    for (auto i = x->subs.begin(); i != x->subs.end(); ++i, ++it)

        // recursive call

        printNTree_help(*i, flag, depth + 1, it == (x->subs.size()) - 1);
    flag[(size_t)depth] = true;
}
void OrgChart::iterator::Preoder(TNode *root)
{
    stack<TNode *> Stack;

    // vector<TNode*> Preorder;

    Stack.push(root);

    while (!Stack.empty())
    {
        TNode *temp = Stack.top();
        Stack.pop();
        this->tq.push(temp);
        // Push all of the child
        // cout << temp->subs.size()<<endl;

        for (size_t i = temp->subs.size(); i > 0; i--)
        {
            // cout <<"ups" <<endl;
            Stack.push(temp->subs[i - 1]);
        }
    }

    this->pointer_to_node = this->tq.front();
}

void OrgChart::iterator::level_order(TNode *root)
{
    // cout <<"Priv"<<endl;
    vector<vector<TNode *>> ans;
    if (!root)
    {
        throw runtime_error("Null");
    }

    queue<TNode *> main_queue;

    main_queue.push(root);

    vector<TNode *> temp;

    while (!main_queue.empty())
    {

        int n = main_queue.size();

        for (size_t i = 0; i < n; i++)
        {
            TNode *cur = main_queue.front();
            main_queue.pop();
            temp.push_back(cur);
            for (auto u : cur->subs)
                main_queue.push(u);
        }
        ans.push_back(temp);
        temp.clear();
    }
    for (auto v : ans)
    {
        for (TNode *x : v)
        {
            this->tq.push(x);
            // cout << x->value << " ";
        }

        // cout << endl;
    }
    this->pointer_to_node = this->tq.front();
}

void OrgChart::iterator::level_order_reverse(TNode *root)
{
    // cout <<"Priv"<<endl;
    vector<vector<TNode *>> ans;
    if (!root)
    {
        throw runtime_error("Null");
    }

    queue<TNode *> main_queue;

    main_queue.push(root);

    vector<TNode *> temp;

    while (!main_queue.empty())
    {

        int n = main_queue.size();

        for (size_t i = 0; i < n; i++)
        {
            TNode *cur = main_queue.front();
            main_queue.pop();
            temp.push_back(cur);
            for (auto u : cur->subs)
                main_queue.push(u);
        }
        ans.push_back(temp);
        temp.clear();
    }
  
    stack< queue<TNode *>> stack;
      
    for (auto v : ans)
    {
         queue<TNode *> y;
        for (TNode *x : v)
        {
       
           y.push(x);
            // cout << x->value << " ";
        }
      //cout<<y.size()<<endl;
       stack.push(y);
        // cout << endl;
    }
     //cout << "fdghg"<<endl;
   
    while (!stack.empty())
    {
      
     queue<TNode *> y = stack.top();
          //cout<<y.size()<<endl;
       // stack.pop();
       // cout << "fdghg"<<endl;
       
        while (!y.empty())
    {
       
        TNode *i= y.front();
        //cout<<i->value<<endl;
        this->tq.push( i);
        y.pop();
    }
         stack.pop();
        //this->tq.push(n);
    }

    this->pointer_to_node = this->tq.front();
}
