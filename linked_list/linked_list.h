typedef struct LLItem {
    void* data;
    struct LLItem* previous;
    struct LLItem next;
} LLItem;