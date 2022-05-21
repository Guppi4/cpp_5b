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

vector<string>::iterator OrgChart::begin_level_order()
{

    return return_vec();
}

vector<string>::iterator OrgChart::end_level_order()
{
    return return_vec();
}

vector<string>::iterator OrgChart::begin_reverse_order()
{
    return return_vec();
}

vector<string>::iterator OrgChart::reverse_order()
{
    return return_vec();
}

vector<string>::iterator OrgChart::begin_preorder()
{
    return return_vec();
}

vector<string>::iterator OrgChart::end_preorder()
{
    return return_vec();
}

vector<string>::iterator OrgChart::begin()
{
    return return_vec();
}
vector<string>::iterator OrgChart::end()
{
    return return_vec();
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