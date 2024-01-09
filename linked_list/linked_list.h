typedef struct {
    void* data;
    struct LLItem* previous;
    struct LLItem* next;
} LLItem;

typedef struct {
    size_t size;
    LLItem* head;
    LLItem* tail;
} LinkedList;