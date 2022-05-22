#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <queue>
using namespace std;

namespace ariel
{
    // flags for iterators
    const unsigned int level_order_flag = 0;
    const unsigned int preorder_flag = 1;
    const unsigned int level_order_reverse_flag = 2;

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
        int sizeofTree;
        string root_name;
        OrgChart() : root(NULL), sizeofTree(0),root_name("") {}
        ~OrgChart();
        vector<TNode *> it_preorder();
        TNode *find_root(string m);

        OrgChart &add_root(const string root);
        OrgChart &add_sub(string root, string sub);
       string  printNTree_help(TNode *x, vector<bool> flag, int depth, bool isLast);
       friend ostream &operator<<(ostream &out,  OrgChart &p)
        {
            TNode *x = p.getroot();
            unsigned long size = (unsigned long)p.sizeofTree;
            vector<bool> flag(size, true);
            string s=p.printNTree_help(x,flag, 0, false);
            out<<s;
            p.root_name="";
            ///
            //cout << s<<endl;
            return out;
        }

        TNode *getroot();
        string printNTree();
        

        class iterator
        {
        private:
            TNode *pointer_to_node;
            queue<TNode *> tq;

        public:
            iterator(unsigned int flag, TNode *ptr) : pointer_to_node(ptr)
            {
                if (pointer_to_node != nullptr)
                {

                    if (flag == level_order_flag) // flags to iterators
                    {

                        level_order(pointer_to_node);
                        // cout <<"Priv"<<endl;
                    }
                    if (flag == preorder_flag)
                    {

                        Preoder(pointer_to_node);
                    }
                    if (flag == level_order_reverse_flag)
                    {
                        // cout <<"Priv"<<endl;
                        level_order_reverse(pointer_to_node);
                    }
                    tq.push(nullptr);
                }
            }

            iterator(TNode *ptr) : pointer_to_node(ptr) {}

            string operator*() const { return pointer_to_node->value; }
            string *operator->() const { return &(pointer_to_node->value); } // tyu
            void level_order(TNode *root);
            void Preoder(TNode *root);
            void level_order_reverse(TNode *root);

            iterator &operator++()
            {
                tq.pop();
                pointer_to_node = tq.front();
                return *this;
            }
            iterator operator++(int)
            {
                iterator tmp = *this;
                tq.pop();
                pointer_to_node = tq.front();
                return tmp;
            }

            bool operator==(const iterator &rhs) const { return pointer_to_node == rhs.pointer_to_node; }
            bool operator!=(const iterator &rhs) const { return pointer_to_node != rhs.pointer_to_node; }
        };
        iterator begin_level_order() { return iterator(level_order_flag, root); }
        iterator end_level_order() { return iterator(nullptr); }
        iterator begin_preorder() { return iterator(preorder_flag, root); }
        iterator end_preorder() { return iterator(nullptr); }
        iterator begin_reverse_order() { return iterator(level_order_reverse_flag, root); }
        iterator reverse_order() { return iterator(nullptr); }
        iterator begin() { return iterator(level_order_flag, root); }
        iterator end() { return iterator(nullptr); }
    };
}