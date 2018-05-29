

struct Node {
    void* value;
    struct Node* next;
    struct Node* prev;
};


struct LinkedList {
    struct Node* start;
    struct Node* end;
    int size;
};

struct Iterator {
    struct Node* result;
    struct Node* state;
    bool dir;
    
};

struct address {
  char name[40];
  char street[40];
  char city[20];
  char state[10];
  char zip[11];
  
};


void LinkedList_new (struct LinkedList* ll);
struct Node* element (struct LinkedList* ll, int i);
struct Iterator* make_iterator (struct LinkedList* ll, bool dir);
void next (struct Iterator* iter);
struct LinkedList* filter (bool (pred) (struct Node* s), struct LinkedList* ll);

void append (struct LinkedList* a, struct LinkedList* b);
void reverse (struct LinkedList* ll);
void addNode (struct LinkedList* ll, void* value); 
void deleteNode (struct LinkedList* ll, int i);


bool SaintP (struct Node* s);