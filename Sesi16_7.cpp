#include <stdio.h>

union Converter {
    unsigned int num;
    unsigned char bytes[4];
};

int main() {
    union Converter u;
    printf("Enter unsigned integer (0 - 4294967295): ");
    scanf("%u", &u.num);

    printf("Hexadecimal: 0x%02X%02X%02X%02X\n",
           u.bytes[3], u.bytes[2], u.bytes[1], u.bytes[0]);

    return 0;
}
