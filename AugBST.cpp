#include<iostream>
using namespace std;

template <typename T>
class AugBST{
    public:
        class node{
            public:
                T key;
                int nleft;
                node * left;
                node * right;
                node * parent;
                node(T k, node * p){
                    parent = p;
                    nleft = 0;
                    key = k;
                    left = NULL;
                    right = NULL;
                }
        };
        node * root = NULL;
        int n;
        void insert(T x){
            root=insertUtil(root, x, NULL);
        }
        void remove(T x){
            root=removeUtil(root, x, NULL);
        }
        node * search(T x){
            return searchUtil(root,x);
        }
        void inorder(){
            inorderUtil(root);
            cout<<endl;
        }
        T ksmallest(int k){
            return ksmallestUtil(root, k);
        }
        int rank(T x){
            return rankUtil(root, x, 0);
        }
    private:
        void inorderUtil(node * head){
            if(head==NULL) return ;
            inorderUtil(head->left);
            cout<<head->key<<" ";
            inorderUtil(head->right);
        }
        node * insertUtil(node * head, T x, node * p){
            if(head == NULL){
                n++;
                node * temp = new node(x,p);
                while(p!=NULL){
                    if(x<p->key) p->nleft += 1;
                    p=p->parent;
                }
                return temp;
            }
            if(x > head->key) head->right = insertUtil(head->right, x, head);
            else if(x < head->key) head->left = insertUtil(head->left, x, head);
            return head;
        }
        node * searchUtil(node * head, T x){
            if(head == NULL) return NULL;
            T k = head->key;
            if(k == x) return head;
            if(k > x) return searchUtil(head->left, x);
            if(k < x) return searchUtil(head->right, x);
        }
        int rankUtil(node * head, T x, int r){
            if(head == NULL) return 0;
            T k = head->key;
            if(k == x) return r+1+head->nleft;
            if(k > x) return rankUtil(head->left, x, r);
            if(k < x) return rankUtil(head->right, x, r+head->nleft+1);
        }
        node * removeUtil(node * head, T x, node * p){
            if(head == NULL) return NULL;
            if(x == head->key){
                node * l = head->left;
                node * r = head->right;
                while(p!=NULL){
                    if(x<p->key) p->nleft -= 1;
                    p=p->parent;
                }
                if(l == NULL){
                    delete(head);
                    return r;
                }
                if(r == NULL){
                    delete(head);
                    return l;
                }
                while(r->left != NULL) r = r->left;
                head->key = r->key;
                head->right = removeUtil(head->right, r->key, NULL);
                return head;
            }
            if(x < head->key) head->left = removeUtil(head->left, x, head);
            else head->right = removeUtil(head->right, x, head);
            return head;
        }

        T ksmallestUtil(node * head, int k){
            if(k<1 || k>n) return NULL;
            if(head->nleft == k-1) return head->key;
            if(head->nleft > k-1) return ksmallestUtil(head->left, k);
            return ksmallestUtil(head->right, k-1-head->nleft);
        }
};
int main(){
    AugBST<float> t;
    t.insert(4.1);
    t.insert(2.3);
    t.insert(1.5);
    t.insert(3.7);
    t.insert(6.5);
    t.insert(5.4);
    t.insert(7.2);
    t.inorder();
    cout<<t.rank(t.ksmallest(1));
}
