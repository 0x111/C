#include <stdio.h>
#include <stdlib.h>

typedef struct BinTree{
    int data;
    int key;
    struct BinTree* left;
    struct BinTree* right;
    struct BinTree* parent;
} node;




node* search(node* root, int key){
    node* temp=root;
    while(1){
        if (temp==NULL) return NULL;
        else
            if (key==temp->key) return temp;
            else
                if (key>temp->key)
                    temp=temp->right;
                else
                    temp=temp->left;
    }
}

node *btmin(node *root){
    node *p=root;
    while (p->left)
        p=p->left;
    return p;
}

node *btsucc(node *temp){
    node *p=temp, *q;
    if (p->right)
        return btmin(p->right);
    q=p->parent;
    while (q && p==q->right){
        p=q;
        q=q->parent;
    }
    return q;
}


void rmv(node **root, node *n)
{
    node *x,*y;
    y=(! n->left || !n->right)?n:btsucc(n); //y указатель на удаляемый узел
    x=y->left?y->left:y->right; //x-указатель на ребенка y , если есть, либо NULL
    if (x)
        x->parent=y->parent; //если есть ребенок x, вырезаем y из родителей
    if (!y->parent) //если у y нет родителя, то новый корень дерева-x
        *root=x;
    else{ //x ребенок присоединяется к y->parent
        if (y==y->parent->left){
            y->parent->left=x;
        }
        else
            y->parent->right=x;
    }
    //Меняем данные, если не n удаляем, а succ(n)
    if(y!=n){
        n->key=y->key;
        n->data=y->data;
    }
}

void walk(node* root){
    if (root==NULL) return;
    walk(root->left);
    printf("%d ",root->data);
    walk(root->right);
}

node* init(int key,int data){
    node *temp=(node*) malloc(sizeof(node));
    temp->parent=NULL;
    temp->left=NULL;
    temp->right=NULL;
    temp->key=key;
    temp->data=data;
    return temp;
}

node* btinsert(node *root, node *te){
    node *p, *q;
    p=root, q=NULL;
    while (p){
        q=p;
        p=(te->key<p->key)?p->left:p->right;
    }
    te->parent=q;
    if (q==NULL)
        root=te;
    else
        if(te->key<q->key)
            q->left=te;
        else
            q->right=te;
    return root;
}

void destroy(node* r){
    if(r==NULL) return;
    destroy(r->left);
    destroy(r->right);
    free(r);
}
int main(void){
    int data,key;
    node *temp, *root=NULL;
    char c,keep[100];
    while(gets(keep)){
        if (keep[0]=='A'){
            sscanf(keep,"%c %d %d",&c,&key,&data);
            temp=NULL;
            temp=search(root,key);
            if (temp)
                temp->data=data;
            else{
                temp=init(key,data);
                root=btinsert(root, temp);
            }
        }
        if (keep[0]=='S'){
            sscanf(keep,"%c %d",&c,&key);
            temp=search(root,key);
            if(temp)
                printf("%d %d\n",temp->key,temp->data);
        }
        if (keep[0]=='D'){
            sscanf(keep,"%c %d",&c,&key);
            temp=NULL;
            temp=search(root,key);
            if (temp)
                rmv(&root,temp);
        }
        if (keep[0]=='F'){
            destroy(root);
            return 0;
        }
    }
    //walk(root);
    return 0;
}
