#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include <stdio.h>

//int main() {
//    int a = 1, b = 2, c = 3;
//
//    // 使用逗号表达式
//    int result = (a += 5, b *= 2, c += a + b);
//                //6       4       13
//    printf("Result: %d\n", result);  // 输出：Result: 13
//
//    return 0;
//}
//
//
////00000000000000000000000000001010
////1111 1111 1111 1111 1111 1111 1111 0101


int main()
{
    unsigned int a = 0b1010; // 10 的二进制表示
    unsigned int b = 0b1100; // 12 的二进制表示

    unsigned int and = a & b; // 0b1000 (8)
    unsigned int or = a | b;  // 0b1110 (14)
    unsigned int xor = a ^ b; // 0b0110 (6)
    unsigned int not_a = ~a;         // 0b11111111111111111111111111110101 (4294967285)
    unsigned int left_shift = a << 2;        // 0b101000 (40)
    unsigned int right_shift = a >> 2;       // 0b10 (2)

    printf("Bitwise AND: %u\n", and);
    printf("Bitwise OR: %u\n", or );
    printf("Bitwise XOR: %u\n", xor);
    printf("Bitwise NOT of a: %u\n", not_a);
    printf("Left Shift of a: %u\n", left_shift);
    printf("Right Shift of a: %u\n", right_shift);

    return 0;
}