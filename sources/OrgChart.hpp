#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

namespace ariel
{
    // flags for iterators
    const unsigned int inorder_flag = 0;
    const unsigned int preorder_flag = 1;
    const unsigned int postorder_flag = 2;

    class OrgChart
    {
    
        struct TNode
        {
            string value;
            vector<TNode *> subs;
            TNode(string val) : value(val) {}
        };
         TNode *root;

        public:
        
        string root_name;
        OrgChart() : root(NULL) {}
        ~OrgChart(); 
        vector<TNode*> it_preorder();
        TNode* find_root(string m);
        
        OrgChart &add_root(const string root);
        OrgChart &add_sub(string root, string sub);
        vector<string>::iterator begin_level_order(); // level order
        vector<string>::iterator end_level_order();
        vector<string>::iterator begin_reverse_order(); // level order reverse
        vector<string>::iterator reverse_order();
        vector<string>::iterator begin_preorder(); // preorder
        vector<string>::iterator end_preorder();
        vector<string>::iterator begin();
        vector<string>::iterator end();
        friend ostream &operator<<(ostream &out, const OrgChart &p);
        TNode* getroot();
    };
}