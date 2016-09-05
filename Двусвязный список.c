#include <stdio.h>
#include <stdlib.h>
//temp указатель на объект *temp
typedef struct node {
    int value;
    struct node* next;
    struct node* prev;
} node;
typedef struct list{
    int size;
    node* head;
    node* tail;

} list;

//Создание списка
list* create(void){
    list* temp= (list*) malloc(sizeof(list));
    temp->size=0;
    temp->head=temp->tail=NULL;
    return temp;
}

void deletelist(list **killed){
    node* temp=(*killed)->head;
    node* next=NULL;
    while (temp){
        next=temp->next;
        free(temp);
        temp=next;
    }
    free(*killed);
    (*killed)=NULL;
}

node* getn(list* lst,int index){
    node* temp=lst->head;
    int i=0;
    while (temp && i<index){
        temp=temp->next;
        i++;
    }
    return temp;
}

void push(list* lst, int data){
    node* temp=malloc(sizeof(node));
    temp->value=data;
    temp->next=lst->head;
    temp->prev=NULL;
    if (lst->head)
        lst->head->prev=temp;
    lst->head=temp;
    if (lst->tail==NULL)
        lst->tail=temp;
    lst->size++;
}

int pop(list* lst, int index){
    node *elm=NULL;
    int tmp;
    elm=getn(lst,index);
    if (elm==NULL)
        exit(1);
    if (elm->prev)
        elm->prev->next=elm->next;
    if (elm->next)
        elm->next->prev=elm->prev;
    tmp=elm->value;
    if (!elm->prev)
        lst->head=elm->next;
    if (!elm->next)
        lst->tail=elm->prev;
    free(elm);
    lst->size--;
    return tmp;

}

int min(list* kl){
    int num=0;
    node* temp=kl->head;
    node* min=kl->head;
    for (int i=0;i<(kl->size);i++){
        if ((temp->value)<(min->value)){
            min=temp;
            num=i;
        }
        temp=temp->next;
    }
    return num;
}


int main(void){
    list* arr=create();
    int s;
    FILE* op=fopen("input.txt","r");
    while (fscanf(op,"%d",&s)!=EOF){
        push(arr,s);
    }
    fclose(op);
    op=fopen("output.txt","w");
    while ((arr->size)>0){
        fprintf(op,"%d ",pop(arr,min(arr)));
    }
    return 0;
}
