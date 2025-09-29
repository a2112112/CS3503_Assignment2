// This is an updated version of main.c from Assignment 1

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
      char input[50];
      char expectedStr[50];
      char format[50];

      int32_t n;

      // Ignore comment lines in the text file
      if (line[0] == '#') {
            continue;
      }

      if (sscanf(line, "%s %s %s", func, &input, &expectedStr) == 3) {
         // For mapping functions, cast the input as a const char * when making the call
            if (strcmp(func, "oct_to_bin") == 0) {
               oct_to_bin((const char *)input, output);
            } else if (strcmp(func, "oct_to_hex") == 0) {
               oct_to_hex((const char *)input, output);
            } else if (strcmp(func, "hex_to_bin") == 0) {
               hex_to_bin((const char *)input, output);
         // For signed number representations, convert the input to an integer before making the call
            } else if (strcmp(func, "to_sign_magnitude") == 0) {
               n = atoi(input);
               to_sign_magnitude(n, output);
            } else if (strcmp(func, "to_ones_complement") == 0) {
               n = atoi(input);
               to_ones_complement(n, output);
            } else if (strcmp(func, "to_twos_complement") == 0) {
               n = atoi(input);
               to_twos_complement(n, output);
            }

            printf("Test %d: %s(%s) -> Expected: \"%s\", Got: \"%s\" ", index, func, input, expectedStr, output);
            if (strcmp(output, expectedStr) == 0) {
               printf("[PASS]\n");
               numPassed++;
            } else {
               printf("[FAIL]\n");
            }
            index++;
      }
   }

   fclose(file);
   printf("Tests passed: %d/51", numPassed);

   return 0;
}
