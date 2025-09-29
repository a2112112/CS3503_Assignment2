// An updated version of convert.c from Assignment 1.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Prototype of helper functions
void octal_digit_conversion(char oct_digit, char *out);
void bin_to_hex(const char *bin, char *out);

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
   char temp[63];

   // Use the existing Octal > Binary conversion function before using a helper method to finish the process.
   oct_to_bin(oct, temp);
   bin_to_hex(temp, out);
}

// Helper Method for Octal > Hex Conversion
void bin_to_hex(const char *bin, char *out) {
   int length = strlen(bin);
   int padded = length + (4 - length % 4) % 4;

   char padded_binary[padded - 1];
   padded_binary[0] = '\0';

   for (int i = 0; i < (4 - length % 4) % 4; i++) {
      strcat(padded_binary, "0");
   }
   strcat(padded_binary, bin);

   int index = 0;
   for (int i = 0; i < padded; i += 4) {
      char nibble[5];

      strncpy(nibble, &padded_binary[i], 4);
      nibble[4] = '\0';

      int value = (nibble[0] - '0') * 8 +(nibble[1] - '0') * 4 + (nibble[2] - '0') * 2 + (nibble[3] - '0') * 1;
   
      out[index++] = (value < 10) ? (value + '0') : (value - 10 + 'A');
   }
   out[index] = '\0';
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
void to_ones_complement(int32_t n, char *out) {
    if (n >= 0) {
        for (int i = 31; i >= 0; i--) {
            out[31 - i] = (n & (1 << i)) ? '1' : '0';
        }
    } else {
      n = -n;
      int32_t onesComplement = ~n; 
      for (int i = 31; i >= 0; i--) {
         out[31 - i] = (onesComplement & (1 << i)) ? '1' : '0';
      }
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