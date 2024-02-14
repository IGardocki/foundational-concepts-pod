typedef struct Node{
    double data;
    // struct LLItem* previous;
    struct Node* next;
} Node;

typedef struct {
    size_t size;
    Node* head;
    Node* tail;
    int number_of_items;
} LinkedList;