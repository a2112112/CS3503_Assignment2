#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

const char* octal_digit_conversion(char oct_digit);

// Octal to Binary
void oct_to_bin(const char *oct, char *out) {
   char temp[65];
   int pos = 0;

   size_t bin_length = strlen(oct) * 3 + 1;
   char *bin = (char *)malloc(bin_length);

   for (size_t i = 0; i < strlen(oct); i++) {
      out[pos++] = (char)octal_digit_conversion(oct[i]);
   }

   out[pos] = '\0';
} 

// Helper Method for Octal > Binary Conversion
const char* octal_digit_conversion(char oct_digit) {
   switch (oct_digit) {
      case '0': return "000";
      case '1': return "001";
      case '2': return "010";
      case '3': return "011";
      case '4': return "100";
      case '5': return "101";
      case '6': return "110";
      case '7': return "111";
      default: return "";
   }
}

// Octal to Hex
void oct_to_hex(const char *oct, char *out) {
      
}
   
// Hex to Binary
void hex_to_bin(const char *hex, char *out) {
   
}

// To Sign Magnitude
void to_sign_magnitude(int32_t n, char *out) {

}

// To Ones Complement
void to_ones_complement(int32_t n, char *out) {

}

// To Twos Complement
void to_twos_complement(int32_t n, char *out) {
   
}

char convertDigit(unsigned d) {
   if (d < 10) {
      return (char)('0' + d);
   } else {
      return (char)('A' + (d-10));
   }
}