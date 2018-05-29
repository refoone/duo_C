#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <dl_lists.h>







int main(int argc, char **argv){

    struct address* pInfo = malloc (sizeof (struct address));
    struct address* pInfo2 = malloc (sizeof (struct address));
    struct address* pInfo3 = malloc (sizeof (struct address));
    struct LinkedList* a = malloc (sizeof (struct LinkedList));
    struct LinkedList* b = malloc (sizeof(struct LinkedList));
    struct LinkedList* c = malloc (sizeof(struct LinkedList));
    

     strcpy (pInfo->name, "PEREMOGA" );
     strcpy (pInfo->street, "App" );  
     strcpy (pInfo->state, "dzhihad" );
     strcpy (pInfo->city, "Saint P" );  
     strcpy (pInfo->zip, "628417" );  
 
     
     strcpy (pInfo2->name, "VID" );
     strcpy (pInfo2->street, "App" );  
     strcpy (pInfo2->state, "DC" );
     strcpy (pInfo2->city, "Msk" );  
     strcpy (pInfo2->zip, "148828" );  

     
     strcpy (pInfo3->name, "ADA" );
     strcpy (pInfo3->street, "App" );  
     strcpy (pInfo3->state, "DC" );
     strcpy (pInfo3->city, "Msk" );  
     strcpy (pInfo3->zip, "628417" );

    LinkedList_new (a);
    
    addNode (a, pInfo);
    addNode (a, pInfo2);
    addNode (a, pInfo2);
    
    printf ("a[1]: %d \n" ,a->start);
    printf ("a[2]: %d\n" ,a->start->next);
    printf ("element (a,2): %d\n", element (a,2));
    printf ("element(a,0): %d\n", element (a,0));
    printf ("element (a,4): %d\n", element (a,4));
    
    printf ("\na[1]: %d\n" ,a->start);
    printf ("a[2]: %d\n" ,a->start->next);
    printf ("a[3]: %d\n" ,a->start->next->next);
    
    reverse (a);
    printf ("\na[1]: %d\n" ,a->start);
    printf ("a[2]: %d\n" ,a->start->next);
    printf ("a[3]: %d\n" ,a->start->next->next);
    printf ("a[4]: %d\n" ,a->start->next->next->next);
    
    reverse (a);
    printf ("\na[1]: %d\n" ,a->start);
    printf ("a[2]: %d\n" ,a->start->next);
    printf ("a[3]: %d\n" ,a->start->next->next);
    printf ("a[4]: %d\n" ,a->start->next->next->next);
    
    /*deleteNode (a,1);
    printf ("\na[1]: %d\n" ,a->start);
    printf ("a[2]: %d\n" ,a->start->next);
    printf ("a[3]: %d\n" ,a->start->next->next);
    deleteNode (a,1);
    deleteNode (a,1);
    printf ("\na[start]: %d\n" ,a->start);
    printf ("a[end]: %d\n" ,a->end);*/
    
    /*struct Node* ita;
    
    ita = element (a,2);
    printf ("a[2]: %d \n", ita);
    ita = iterator (ita, 45);
    printf ("a[3]: %d \n", ita);
    ita = element (a,2);
    printf ("a[2]: %d \n", ita);
    ita = iterator (ita, false);
    printf ("a[1]: %d \n", ita);
    ita = iterator (ita, false);
    printf ("a[3]: %d \n", ita);
    
    struct LinkedList* l1 = malloc (sizeof (struct LinkedList));
    struct LinkedList* l2 = malloc (sizeof (struct LinkedList));

    l1 = filter (filter_city, a);
    printf ("Saint P: %s \n",  ((struct address*) l1->start->value)->city);
    printf ("size is 1: %d \n",  l1->size);
    printf ("address l1->start: %d \n",  l1->start);
    
    l2 = filter (filter_city, a);
    printf ("Saint P: %s \n",  ((struct address*) l2->start->value)->city);
    printf ("size is 1: %d \n",  l2->size);
    printf ("address l2->start: %d \n",  l2->start);*/
    
    
    struct LinkedList* l1 = malloc (sizeof (struct LinkedList));

    l1 = filter (SaintP, a);
    printf ("Saint P: %s \n",  ((struct address*) l1->start->value)->city);
    printf ("size is 1: %d \n",  l1->size);
    printf ("address l1->start: %d \n",  l1->start);
    
    
    
    struct Iterator* it1;
    struct Iterator* it2;

    it1 = make_iterator(a, true);
    printf ("Iterator a[1]: %d \n", it1->result);
    next (it1);
    printf ("Iterator a[2]: %d \n", it1->result);
    next (it1);
    printf ("Iterator a[3]: %d \n", it1->result);
    next (it1);
    printf ("Iterator a[4]: %d \n", it1->result);
    next (it1);
    printf ("Iterator a->next: %d \n", it1->result);
    it2 = make_iterator(a, false);
    printf ("reverse Iterator a[1]: %d \n", it2->result);
    next (it2);
    printf ("reverse Iterator a[2]: %d \n", it2->result);
    
    




    








    
    

    
    

    
    
    
    
    
    
    

    
    



     
  
  
  
  
  
	return 0;
}
