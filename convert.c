#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char convertDigit(unsigned d) {
   if (d < 10) {
      return (char)('0' + d);
   } else {
      return (char)('A' + (d-10));
   }
}

// Division Algorithm
void div_convert(uint32_t n, int base, char *out) {
   char temp[65];
   int pos = 0;

   if (n == 0) {
      strcpy(out, "0");
      return;
   }

   while (n > 0) {
      int remainder = n % base;
      n = n / base;

      if (remainder < 10)
         temp[pos++] = '0' + remainder;
      else
         temp[pos++] = 'A' + (remainder- 10);
   }

   for (int i = 0; i < pos; i++) {
        out[i] = temp[pos - i - 1];
    }
    out[pos] = '\0';
}

// Subtraction Algorithm
void sub_convert(uint32_t n, int base, char* out) {

   
   int pos = 0, startFlag = 0;
   uint32_t power = 1;

    if (n == 0) {
        out[pos++] = '0';
        out[pos] = '\0';
        return;
    }

    while (power <= n / (uint32_t)base) {
      power *= (uint32_t)base;
    }

    while (power > 0) {
      unsigned digit = (unsigned)(n / power);
      
      if (digit != 0 || startFlag) {
         out[pos++] = convertDigit(digit);
         startFlag = 1;
      }
      
      n -= (uint32_t)digit * power;
      power /= (uint32_t)base;
    }
   
    if (!startFlag) {
      out[pos++] = '0';
    }

    out[pos] = '\0';
   }