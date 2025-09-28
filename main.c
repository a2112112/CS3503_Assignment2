// This is an updated version of main.c from Assignment 1

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// New functions
void oct_to_bin(const char *oct, char *out);
void oct_to_hex(const char *oct, char *out);
void hex_to_bin(const char *hex, char *out);
void to_sign_magnitude(int32_t n, char *out);
void to_ones_complement(int32_t n, char *out);
void to_twos_complement(int32_t n, char *out);

int main() {

   char output[64];

   FILE *file = fopen("a2_test.txt", "r");
   if (file == NULL) {
      perror("Error opening file");
      return 1;
   }

   
   char line[256];
   int index = 1;
   int numPassed = 0;
   while (fgets(line, sizeof(line), file)) {
      char func[50];
      int input;
      int expected;
      char expectedStr[50];
      char format[50];

         if (sscanf(line, "%s %d %s", func, &input, &expectedStr) == 3) {
            if (strcmp(func, "oct_to_bin") == 0) {
               oct_to_bin((const char *)input, output);
            } else if (strcmp(func, "oct_to_hex") == 0) {
               oct_to_hex((const char *)input, output);
            } else if (strcmp(func, "hex_to_bin") == 0) {
               hex_to_bin((const char *)input, output);
            } else if (strcmp(func, "to_sign_magnitude") == 0) {
               to_sign_magnitude(input, output);
            } else if (strcmp(func, "to_ones_complement") == 0) {
               to_ones_complement(input, output);
            } else if (strcmp(func, "to_twos_complement") == 0) {
               to_twos_complement(input, output);
            }
            printf("Test %d: %s(%u) -> Expected: \"%s\", Got: \"%s\" ", index, func, input, expectedStr, output);
            if (strcmp(output, expectedStr) == 0) {
               printf("[PASS]\n");
               numPassed++;
            } else {
               printf("[FAIL]\n");
            }
         }
      index++;
   }

   fclose(file);
   printf("Autocheck tests passed: %d", numPassed);

   return 0;
}
