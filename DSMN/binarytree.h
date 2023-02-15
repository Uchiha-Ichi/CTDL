#include<iostream>
#include<cstring>
using namespace std;

class subject{
    public:
    char code[10];
    char name[50];
    int TH;
    int LT;
};
class Node{
    public:
    subject data;
    Node* left;
    Node* right;
};
class BST{
    private:
    Node* root;
    Node* insert(Node* r,subject key){
        if(r==NULL){
            r = new Node();
            r->data=key;
            r->left=NULL;
            r->right=NULL;
        } else {
            if(strcmp(key.name,r->data.name)<0){
                r->left =insert(r->left,key);
            } else {
                r->right=insert(r->right,key);
            }
        }
        return r;
    }
    Node* erase(Node* r, char* key){
        if(r==NULL){
            return NULL;
            r= NULL;
        } else if(strcmp(key,r->data.name)<0) {
            r->left = erase(r->left,key);
        } else if(strcmp(key,r->data.name)>0){
            r->right = erase(r->right,key);
        } else {
            if(r->left==NULL&&r->right==NULL){
                delete r;
                r=NULL;
            } else if(r->left==NULL){
                Node* tmp = r;
                r = r->right;
                delete tmp;
            } else if(r->right==NULL){
                Node* tmp = r;
                r = r->left;
                delete tmp;
            } else {
                Node* tmp = r->right;
                while(tmp->left!=NULL){
                    tmp = tmp->left;
                }
                r->data = tmp->data;
                r->right = erase(tmp->right,tmp->data.name);
            }
        }
        return r;
    }
    Node* seach(Node* r, char* key){
        if(r==NULL){
            return NULL;
        } else if(strcmp(key,r->data.name)<0) {
            r->left = erase(r->left,key);
        }else if(strcmp(key,r->data.name)>0){
            r->right = erase(r->right,key);
        } else {
            return r;
        }
    }
    void inOder(Node* r){
        if(r!=NULL){
            inOder(r->left);
            cout << r->data.name << " " << r->data.code << " " << r->data.LT << " "<< r->data.TH  << endl;
            inOder(r->right);
        }
    }
    public:
    BST(){
    root = NULL;
    }
    void insertNode(subject key){
        root = insert(root,key);
    }
    void eraseNode(char* key){
        root = erase(root,key);
    }
    Node* seachNode(char* key){
        return seach(root,key);
    }
    void hieuChinhCode(char* name,char* key){
        Node* tmp= seachNode(name);
        strcpy(tmp->data.code,key);
    } 
    void hieuChinhLT(char* name, int key){
        Node* tmp = seachNode(name);
        tmp->data.LT=key;
    }
    void hieuChinhTH(char* name,int key){
        Node* tmp = seachNode(name);
        tmp->data.TH=key;
    }
    void inOderNode(){
        inOder(root);
    }
};
BST bst;
void input(){  
    for(int i =0;i<5;i++){
      char s[50]; cin >> s;
      char s2[10];cin >> s2;
      int a,b; cin >> a >>b;
      subject su;
      strcpy(su.name,s);
      strcpy(su.code,s2);
      su.LT=a;
      su.TH=b;
      bst.insertNode(su);
    }
}
