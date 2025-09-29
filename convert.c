// An updated version of convert.c from Assignment 1.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void octal_digit_conversion(char oct_digit, char *out);
char binaryToHex(const char *binary);

// Octal to Binary
void oct_to_bin(const char *oct, char *out) {
   char temp[65];

   out[0] = '\0';

   for (size_t i = 0; i < strlen(oct); i++) {
        if (!isdigit(oct[i]) || oct[i] < '0' || oct[i] > '7') {
            fprintf(stderr, "Error: Invalid octal digit '%c'.\n", oct[i]);
            return;
        }
        octal_digit_conversion(oct[i], out);
    }

} 

// Helper Method for Octal > Binary Conversion
void octal_digit_conversion(char oct_digit, char *out) {
   switch (oct_digit) {
      case '0': strcat(out, "000"); break;
      case '1': strcat(out, "001"); break;
      case '2': strcat(out, "010"); break;
      case '3': strcat(out, "011"); break;
      case '4': strcat(out, "100"); break;
      case '5': strcat(out, "101"); break;
      case '6': strcat(out, "110"); break;
      case '7': strcat(out, "111"); break;
      default: break;
   }
}

// Octal to Hex
void oct_to_hex(const char *oct, char *out) {
   
}

// Helper Method for Octal > Hex Conversion
char binaryToHex(const char *binary) {
    if (strcmp(binary, "0000") == 0) return '0';
    if (strcmp(binary, "0001") == 0) return '1';
    if (strcmp(binary, "0010") == 0) return '2';
    if (strcmp(binary, "0011") == 0) return '3';
    if (strcmp(binary, "0100") == 0) return '4';
    if (strcmp(binary, "0101") == 0) return '5';
    if (strcmp(binary, "0110") == 0) return '6';
    if (strcmp(binary, "0111") == 0) return '7';
    if (strcmp(binary, "1000") == 0) return '8';
    if (strcmp(binary, "1001") == 0) return '9';
    if (strcmp(binary, "1010") == 0) return 'A';
    if (strcmp(binary, "1011") == 0) return 'B';
    if (strcmp(binary, "1100") == 0) return 'C';
    if (strcmp(binary, "1101") == 0) return 'D';
    if (strcmp(binary, "1110") == 0) return 'E';
    if (strcmp(binary, "1111") == 0) return 'F';
    return '\0';
}
   
// Hex to Binary
void hex_to_bin(const char *hex, char *out) {
    const char *hexToBinTable[] = {
        "0000", "0001", "0010", "0011", 
        "0100", "0101", "0110", "0111", 
        "1000", "1001", "1010", "1011", 
        "1100", "1101", "1110", "1111"
    };

    size_t hexLen = strlen(hex);
    size_t binaryIndex = 0;

    for (size_t i = 0; i < hexLen; i++) {
        char currentChar = toupper(hex[i]);

        if (currentChar >= '0' && currentChar <= '9') {
            strcpy(&out[binaryIndex], hexToBinTable[currentChar - '0']);
        } else if (currentChar >= 'A' && currentChar <= 'F') {
            strcpy(&out[binaryIndex], hexToBinTable[currentChar - 'A' + 10]);
        }

        binaryIndex += 4;
    }

    out[binaryIndex] = '\0';
}

// To Sign Magnitude
void to_sign_magnitude(int32_t n, char *out) {
    if (out == NULL) {
        fprintf(stderr, "Error: out buffer is NULL.\n");
        return;
    }

    memset(out, '0', 32);
    out[32] = '\0'; 


    if (n < 0) {
        out[0] = '1';
        n = -n;
    } else {
        out[0] = '0'; 
    }


    for (int i = 31; i > 0; i--) {
        out[i] = (n % 2) ? '1' : '0';
        n /= 2;
    }
}

// To Ones Complement
void to_ones_complement(uint32_t n, char *out) {
    if (out == NULL) {
        printf("Error: out pointer is NULL.\n");
        return;
    }

    int32_t onesComplement = ~n;

    for (int i = 31; i >= 0; i--) {
        out[31 - i] = (onesComplement & (1 << i)) ? '1' : '0';
    }

    out[32] = '\0';
}

// To Twos Complement
void to_twos_complement(uint32_t n, char *out) {
   if (out == NULL) {
        return;
    }

    for (int i = 31; i >= 0; i--) {
        out[31 - i] = (n & (1 << i)) ? '1' : '0';
    }

    out[32] = '\0';
}