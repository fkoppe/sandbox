#include <dark/darkstar.h>

int main()
{
    DARK_DEBUG_MEMORY_INITIALISE;

    Dark_Allocator* main_allocator = dark_os_allocator_new();

    int64_t* integer = dark_malloc(main_allocator, sizeof(int64_t));

    integer = dark_realloc(main_allocator, integer, sizeof(int64_t), 2*sizeof(int64_t));

    dark_free(main_allocator, integer, 2*sizeof(int64_t));

    dark_os_allocator_delete(main_allocator);

    DARK_DEBUG_MEMORY_SHUTDOWN;

    return DARK_EXIT_SUCCESS;
}
