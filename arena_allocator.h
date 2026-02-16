#include <cstddef>

class ArenaAllocator {
    char* buffer;
    size_t offset;
public:
    ArenaAllocator(size_t size) : offset(0) {
        buffer = new char[size]; // Grab one big block (The Arena)
    }

    // Fast allocation: just move a pointer, no slow "new" calls
    void* allocate(size_t size) {
        void* ptr = buffer + offset;
        offset += size;
        return ptr;
    }
};
