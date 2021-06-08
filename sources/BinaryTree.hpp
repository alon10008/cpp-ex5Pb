#include <iostream>
#include <string>

using namespace std;

namespace ariel{    

    template <typename T> class BinaryTree{
        
        public:


            class Node
            {
                public:
                    Node(Node l, Node r, const T& data) : left{l}, right{r}, data{data} {}
                    Node(const T& data) :  left{NULL}, right{NULL}, data{data} {}
                    Node() : left{NULL}, right{NULL}, data{0} {}
                    /*Node(const Node& n)
                    {
                        if(n.left != NULL)
                        {
                            left = new Node;
                            *left = *(n.left);
                        }
                        else 
                        {
                            left = NULL;
                        }
                        if(n.right != NULL)
                        {
                            right = new Node;
                            *right = *(n.right);
                        }
                        else
                        {
                            left = NULL;
                        }
                        data  = n.data;
                    }*/
                    Node* left;
                    Node* right;
                    T data = 0;
                    /*Node& operator=(const Node& node)
                    {
                        this->data = node.data;
                        this->left = node.left;
                        this->right = node.right;
                        return *this;
                    }*/
                    void setData(const T& data)
                    {
                       this->data = data; 
                    }
                    T& getData()
                    {
                        return this->data;
                    }
                    friend ostream& operator<<(ostream& os, Node n) { 
                        os << "hello!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                        return os;
                    }
            };
            
            class iterator_pre {

                public:
                    Node *pt;
                    Node *root;
                    int index;
                    int num;
                
                    iterator_pre(Node* pt = nullptr) : pt(pt), index{0}, root{NULL}, num{0} {counter = 0;}
                    T& operator*() const {
                        
                        return this->pt->data;
                    }
                    T* operator->()const {
                      
                        return &(this->pt->data);
                    }
                    iterator_pre& operator++() {
                        
                        this->counter = 0;
                        if(this->index == this->num)
                        {
                            *this = iterator_pre();
                            return *this;
                        }
                        search(root);
                        index++;
                        counter = 0;
                        return *this;
                    }
                    iterator_pre operator++(int) {
                    
                        iterator_pre it = *this;
                        counter = 0;
                        if(index == num)
                        {
                            *this = iterator_pre();
                            return it;
                        }
                        search(root);
                        index++;
                        counter = 0;
                        return it;
                    }
                    bool operator==(const iterator_pre& it) const {
                        
                        if(this->pt == NULL && it.pt == NULL)
                        {
                            return true;
                        }
                        if(this->pt == NULL || it.pt == NULL)
                        {
                            return false;
                        }
                        return this->pt->data == it.pt->data;

                    }
                    bool operator!=(const iterator_pre& it) const {
                        
                        return !this->operator==(it);

                    }
                    /*iterator_pre& operator=(const iterator_pre& ip)
                    {
                        this->root = ip.root;
                        this->pt = ip.pt;
                        this->num = ip.num;
                        return *this;
                    }*/
                    void setRoot(Node* root, int num)
                    {
                        this->root = new Node;
                        *this->root = *root;
                        this->num = num;
                    }
                
                    int counter = 0;
                    void search(Node* r)
                    {
                        if(r == NULL)
                        {
                            return;
                        }
                        counter++;
                        if(counter == (this->index + 1))
                        {
                            this->pt = r;
                            return;
                        }
                        
                        search(r->left);
                        search(r->right);

                    }
                
            };
    
            class iterator_in {
            
                Node *pt;
                Node *root;
                int index;
                int num;
                public:

                    iterator_in(Node* pt = nullptr) : pt(pt), index{0}, root{NULL}, num{0} {counter = 0;}
                    T& operator*() const {
                        return this->pt->data;
                    }
                    T* operator->()const {
                      
                        return &(this->pt->data);
                    }
                    iterator_in& operator++() {
                    
                        this->counter = 0;
                        if(this->index == this->num)
                        {
                            *this = iterator_in();
                            return *this;
                        }
                        search(this->root);
                        this->index++;
                        this->counter = 0;
                        return *this;
                    }
                    iterator_in operator++(int) {
                    
                        iterator_in it = *this;
                        counter = 0;
                        if(this->index == this->num)
                        { 
                            *this = iterator_in();
                            return it;
                        }
                        search(root);
                        index++;
                        counter = 0;

                        return it;
                    }
                    bool operator==(const iterator_in& it) const {
                        
                        if(this->pt == NULL && it.pt == NULL)
                        {
                            return true;
                        }
                        if(this->pt == NULL || it.pt == NULL)
                        {
                            return false;
                        }
                        bool ans = *(*this) == *it;
                        return ans;

                    }
                    bool operator!=(const iterator_in& it) const {
                        
                        return !this->operator==(it);

                    }
                    /*iterator_in& operator=(const iterator_in& ii)
                    {
                        this->root = ii.root;
                        this->pt = ii.pt;
                        this->num = ii.num;
                        return *this;
                    }*/
                    void setRoot(Node* root, int num)
                    {
                        this->root = new Node;
                        *this->root = *root;
                        this->num = num;
                    }
                    
                    
                    void search(Node* r)
                    {
                        if(r == NULL)
                        {
                            return;
                        }
                        search(r->left);
                        counter++;
                        if(counter == (this->index + 1))
                        {
                            this->pt = r;
                            return;
                        }
                        search(r->right);
                    }
                private:
                    int counter = 0;

            };
        
            class iterator_post {

                Node *pt;
                Node *root;
                int index;
                int num;
                public:
                    iterator_post(Node* pt = nullptr) : pt(pt), index{0}, root{NULL}, num{0} {counter = 0;}
                    T& operator*() const {
                        
                        return this->pt->data;
                    }
                    T* operator->()const {
                      
                        return &(this->pt->data);
                    }
                    iterator_post& operator++() {
                    
                        this->counter = 0;
                        if(index == num)
                        {
                            *this = iterator_post();
                            return *this;
                        }
                        search(this->root);
                        this->index++;
                        this->counter = 0;
                        //cout << "data: " << **this << "    " << index << endl;
                        return *this;
                    }
                    iterator_post operator++(int) {
                    
                        iterator_post it = *this;
                        counter = 0;
                        if(it.index == it.num)
                        {
                            *this = iterator_post();
                            return it;
                        }
                        search(root);
                        index++;
                        counter = 0;
                        return it;
                    }
                    bool operator==(const iterator_post& it) const {
                        
                        if(this->pt == NULL && it.pt == NULL)
                        {
                            return true;
                        }
                        if(this->pt == NULL || it.pt == NULL)
                        {
                            return false;
                        }
                        return *(*this) == *it;

                    }
                    bool operator!=(const iterator_post& it) const {
                        
                        return !this->operator==(it);

                    }
                    /*iterator_post& operator=(const iterator_post& ip)
                    {
                        this->root = ip.root;
                        this->pt = ip.pt;
                        this->num = ip.num;
                        return *this;
                    }*/
                    void setRoot(Node* root, int num)
                    {
                        this->root = new Node;
                        *this->root = *root;
                        this->num = num;
                    }
                
                    void search(Node* r)
                    {
                        if(r == NULL)
                        {
                            return;
                        }
                        
                        search(r->left);
                        search(r->right);
                        counter++;
                        if(counter == (this->index + 1))
                        {
                            this->pt = r;
                            return;
                        }
                    }
                private:
                    int counter = 0;    

            };
        
            BinaryTree() : root{NULL}, add{NULL}, node_num(0) {}
            BinaryTree(Node root) : root{root}, add{NULL}, node_num(1) {}
            BinaryTree(BinaryTree&& bt) noexcept : node_num{bt.node_num}
            {
                this->root = bt.root;
                //this->node_num = bt.node_num;
                this->add = NULL;

                bt.root = nullptr;
                bt.node_num = 0;
            }
            BinaryTree(const BinaryTree& bt) : node_num{bt.node_num}
            {
                copy(this->root, bt.root);
                //this->node_num = bt.node_num;
            }
            BinaryTree& operator=(const BinaryTree& bt) noexcept
            {
                if(this->root != bt.root)
                {
                    this->node_num = bt.node_num;
                    this->root = bt.root;
                }
                return *this;
            }
            BinaryTree& operator=(BinaryTree&& bt) noexcept
            {
                if(this->root != bt.root)
                {
                    delete root;
                    this->root = bt.root;
                    this->node_num = bt.node_num;

                    bt.root = nullptr;
                    bt.node_num = 0;
                }
                return *this;

            }
            //~BinaryTree(){destroy(root);}
            /*void destroy(Node* root)
            {
                if(root == NULL)
                {
                    return;
                }
                cout << "destroy\n";
                destroy(root->left);
                destroy(root->right);
                delete root;
            }*/
            void copy(Node* n1,const Node* n2)
            {
                if(n2 == NULL)
                {
                    n1 = NULL;
                    return;
                }
                n1 = new Node();
                *n1 = *n2;
                copy(n1->left, n2->left);
                copy(n1->right, n2->right);
            }
            BinaryTree<T> add_root(const T& data)
            {
                if(root == NULL)
                {
                    root = new Node();
                    *root = Node(data);
                    this->node_num++;
                    return *this;
                }
                this->root->setData(data);
                return *this;
            }
            BinaryTree<T> add_left(const T& exist, const T& data)  
            {        
                if(root == NULL)
                {
                    throw invalid_argument("no root!");
                }                                    
                search(exist ,root);
                if(this->add == nullptr)
                {
                    throw invalid_argument("not exist!\n");
                }
                if(this->add->left == NULL)
                {
                    this->add->left = new Node;
                    *this->add->left = Node{data};
                    this->node_num++;
                }
                else
                {
                    this->add->left->setData(data);
                }
                this->add = nullptr;
                return *this;
            }

            void search(const T& exist, Node* n)
            {
                if(n == NULL)
                {
                    return;
                }
                if(n->data == exist)
                {
                    this->add = n;
                    return;
                }
                search(exist, n->left);
                search(exist, n->right);
                
            }

            BinaryTree<T> add_right(const T& exist,const T& data)
            {
                if(root == NULL)
                {
                    throw invalid_argument("no root!");
                }
                search(exist, root);
                if(this->add == nullptr)
                {
                    throw invalid_argument("not exist!\n");
                }
                if(this->add->right == nullptr)
                {
                    this->add->right = new Node;
                    *this->add->right = Node{data};
                    this->node_num++;
                }
                else
                {
                    this->add->right->setData(data);
                }
                this->add = nullptr;
                return *this;
            }
            iterator_in begin()
            {
                iterator_in ii;
                if(this->root != NULL)
                {
                    ii.setRoot(this->root, this->node_num);
                    ++ii;
                }    
                return ii;
            }
            iterator_in end()
            {
                iterator_in ii;
                return ii;
            }
            iterator_pre begin_preorder()
            {
                iterator_pre ip;
                if(this->root != NULL)
                {
                    ip.setRoot(this->root, this->node_num);
                    ++ip;
                } 
                return ip;
            }
            iterator_pre end_preorder()
            {
                iterator_pre ip;
                return ip;

            }
            iterator_in begin_inorder()
            {
                iterator_in ii;
                if(this->root != NULL)
                {
                    ii.setRoot(this->root, this->node_num);
                    ++ii;
                } 
                return ii;
            }
            iterator_in end_inorder()
            {
                iterator_in ii;
                return ii;

            }
            iterator_post begin_postorder()
            {
                iterator_post ip;
                if(this->root != NULL)
                {
                    ip.setRoot(this->root, this->node_num);
                    ++ip;
                } 
                return ip;

            }
            iterator_post end_postorder()
            {
                iterator_post ip;
                return ip;

            }
            friend ostream& operator<<(ostream& os, const BinaryTree<T>& bt)
            {
                os << "shalom!\n";
                return os;
            }
            
        private:
            Node* root;
            Node* add;
            int node_num;
    
    };
    
}