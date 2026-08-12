#include <stdio.h>
#include <stdint.h>

void address_translation(uint32_t virtual_address) {
    uint32_t page_number = 0;
    uint32_t offset = 0;

    // Calculate page number by shifting right by 12 bits
    page_number = virtual_address >> 12;

    // Calculate offset using mask 0xFFF
    offset = virtual_address & 0xFFF;

    printf("[1A] Addr: 0x%08X -> Page: %u (0x%X), Offset: %u (0x%X)\n",
           virtual_address,
           page_number,
           page_number,
           offset,
           offset);
}

int main() {
    uint32_t virtual_address;

    printf("Enter virtual address (hex): 0x");
    scanf("%x", &virtual_address);

    address_translation(virtual_address);

    return 0;
}