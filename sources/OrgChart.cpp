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
    if (!this->root)
    {
        this->root = new TNode(root);
        return *this;
    }
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
    return this->root;
}
vector<OrgChart::TNode *> OrgChart::it_preorder()
{
    stack<TNode *> Stack;

    vector<TNode *> Preorders_nodes; // visited nodes

    Stack.push(this->root);

    while (!Stack.empty())
    {
        TNode *temp = Stack.top();
        Stack.pop();
        
        Preorders_nodes.push_back(temp);
       
        
        for (size_t i = temp->subs.size() - 1; i >= 0; i--)// the stack from right to left
        {
            Stack.push(temp->subs[i]);
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