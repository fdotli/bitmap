#include "gtest/gtest.h"
#include "bitmap.h"



TEST(bitmap, bitmap_zero)
{
int i;

unsigned long * port_pool, * cursor;

cursor = port_pool = (unsigned long *)malloc(1024 * sizeof(unsigned long));

bitmap_zero(port_pool, 65536);

for (i = 0; i < 1024; i++)
{
    EXPECT_EQ(*cursor, 0);
    cursor++;
}

}

TEST(bitmap, bitmap_allocation)
{
int i;

unsigned long * port_pool, * cursor, port;

cursor = port_pool = (unsigned long *)malloc(1024 * sizeof(unsigned long));

bitmap_zero(port_pool, 65536);

for (i = 0; i < 65536; i++)
{
    port = bitmap_find_next_zero_area(port_pool, 65536, 0, 1, 0);

    //printf("port:%ld\n", port);

    bitmap_set(port_pool, port, 1);
}

}

TEST(bitmap, bitmap_deallocation)
{
int i;

unsigned long * port_pool, * cursor;

cursor = port_pool = (unsigned long *)malloc(1024 * sizeof(unsigned long));

bitmap_zero(port_pool, 65536);

for (i = 0; i < 65536; i++)
{
    bitmap_clear(port_pool, i, 1);
}

}



