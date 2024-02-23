int PIntComparator(const void* x, const void* y) { 
    return *(int*)x - *(int*)y; 
};

int PCharComparator(const void* x, const void* y) {
    return *(char*)x - *(char*)y;
}