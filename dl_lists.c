#include <stdlib.h>
#include <stdbool.h>
#include <dl_lists.h>
#include <string.h>



void LinkedList_new (struct LinkedList* ll) {
    ll->start = NULL;
    ll->end = ll->start;

    ll->size=0;
    return;
}


struct Node* element (struct LinkedList* ll, int i){
    struct Node* ita;
    
    if (i==0 || i>ll->size) return NULL;
    
    ita = ll->start;
    for (int a=1; a<=i; a++){
        if (a==1) continue;
        else ita=ita->next;
    }
    return ita;
}


struct Iterator* make_iterator (struct LinkedList* ll, bool a){
    struct Iterator* ita = malloc (sizeof(struct Iterator));
    struct Iterator** iter;
    iter = &ita;
    
    (*iter)->dir = a;
    
    if ((*iter)->dir) {
        (*iter)->result = ll->start;
        (*iter)->state = ll->start;
    }
    else {
        (*iter)->result = ll->end;
        (*iter)->state = ll->end;
    }
    
    
    return *iter;
   
}

void next (struct Iterator* iter){
    struct Iterator** ita;
    ita = &iter;
    
    if (iter->dir) {
        if ((iter->result == NULL) || (((struct Node*) iter->result)->next == NULL)){
            (*ita)->result = NULL;
            
            return;
        }
        
        (*ita)->result = ((struct Node*) iter->result)->next;
        
    }
    else {
        if ((iter->result == NULL) || (((struct Node*) iter->result)->prev == NULL)){
            (*ita)->result = NULL;

            return;
        }  
        
        (*ita)->result = ((struct Node*) iter->result)->prev;

    }


    return;
}


void reverse (struct LinkedList* ll){
    struct Node* cur;
    struct Node* ita;
    cur = ll->start;
    for(int i=1; i<=ll->size-1; i++){
        cur = cur->next;
        ita = cur->prev->prev;
        cur->prev->prev = cur->prev->next;
        cur->prev->next = ita;
    }
    
    ita = cur->prev;
    cur->prev = cur->next;
    cur->next = ita;
    ita = ll->start;
    ll->start = ll->end;
    ll->end = ita;
    
    return;
    
}


void addNode (struct LinkedList* ll, void* value) {
    if (NULL == ll->start) {
        ll->start =  malloc (sizeof (struct Node));
        ll->start->prev = NULL;
        ll->start->next = NULL;
        ll->end = ll->start;
    } 
    else {
        ll->end->next =  malloc (sizeof(struct Node));
        ll->end->next->prev = ll->end;
        ll->end->next->next=NULL;
        ll->end = ll->end->next;
    }
    ll->end->value = value;
    ll->size++;
    return;
}

void deleteNode (struct LinkedList* ll, int i){
    struct Node* ita;
    
    if (ll->size==1){
        free(ll->start);
        ll->end = NULL;
        ll->start = NULL;
         
    }
    else if (i==1){
        ita=ll->start->next;
        free (ita->prev);
        ita->prev = NULL;
        ll->start = ita;
    }
    else if (i==ll->size){
        ita = ll->end->prev;
        free (ita->next);
        ita->next = NULL;
        ll->end = ita;
        
    }
    else if (i<=0 || i>ll->size) return;
    else {
        ita = element (ll,i);
        ita->prev->next = ita->next;
        ita->next->prev = ita->prev;
        free (ita);
        
    }
    
    ll->size--;
    
    return;
}


void append (struct LinkedList* a, struct LinkedList* b){
    a->end->next=b->start;
    a->end->next->prev=a->end;
    a->end=b->end;
    a->size+=b->size;
    
    return;
}


bool SaintP (struct Node* s) {
    if (strcmp ("Saint P", ((struct address*) s->value)->city) == 0) return true;
    else return false;
    
}



struct LinkedList* filter (bool (pred) (struct Node* ita), struct LinkedList* ll){
    struct Node* s;
    struct LinkedList* a = malloc (sizeof(struct LinkedList));
    
    LinkedList_new (a);
    s = ll->start;
    for (int i=1; i <= ll->size; i++){
        if (pred (s)){
            addNode (a, s->value);
        }
        s = s->next;
    }
    
    if (a->size == 0) {
            free (a);
            return NULL;
        }
    
    return a;
}









  

