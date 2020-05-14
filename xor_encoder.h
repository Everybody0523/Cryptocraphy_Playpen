#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include <stdio.h>

constexpr int buff_size = 2048;

uint8_t gen_key();


template <typename T>
void print_bit_representation(T key)
{
    int bitlen = sizeof(T) * 8;
    printf("File encoded/decoded with key: ");
    for (int i = 0; i < bitlen; ++i)
    {
        printf("%d", !!((key << i) & 0x80));
    }
    printf("\n"); 
}
