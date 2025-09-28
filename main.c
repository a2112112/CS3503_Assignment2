#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Create function prototypes to prevent implicit declaration
void div_convert(uint32_t n, int base, char *out);
void sub_convert(uint32_t n, int base, char *out);
void print_tables(uint32_t n);
int is_empty_line(const char *line);

int main() {

   char output[64];

   FILE *file = fopen("a1_test_file.txt", "r");
   if (file == NULL) {
      perror("Error opening file");
      return 1;
   }

   
   char line[256];
   int index = 1;
   int numPassed = 0;
   while (fgets(line, sizeof(line), file)) {
      char func[50];
      unsigned int parameter;
      int base;
      int expected;
      char expectedStr[50];
      char format[50];

         if (sscanf(line, "%s %u %u %s", func, &parameter, &base, &expectedStr) == 4) {
            if (strcmp(func, "div_convert") == 0) {
               div_convert(parameter, base, output);
            } else if (strcmp(func, "sub_convert") == 0) {
               sub_convert(parameter, base, output);
            }
            printf("Test %d: %s(%u, %u) -> Expected: \"%s\", Got: \"%s\" ", index, func, parameter, base, expectedStr, output);
            if (strcmp(output, expectedStr) == 0) {
               printf("[PASS]\n");
               numPassed++;
            } else {
               printf("[FAIL]\n");
            }
         }
         if (sscanf(line, "%s %u %s", func, &parameter, &format) == 3) {
            if (strcmp(func, "print_tables") == 0) {
               printf("Test %d: %s(%u) -> \n", index, func, parameter);
               print_tables(parameter);
            }
         }
         index++;
   }


    fclose(file);
    printf("Autocheck tests passed: %d", numPassed);

    return 0;
}

int is_empty_line(const char *line) {
    for (int i = 0; line[i] != '\0'; i++) {
        if (!isspace(line[i])) {
            return 0;
        }
    }
    return 1;
}

void print_tables(uint32_t n) {
   char bin[33], oct[12], hex[9];

   // Original number
   div_convert(n, 2, bin);
   div_convert(n, 8, oct);
   div_convert(n, 16, hex);
   printf("Original: Binary=%s Octal=%s Decimal=%u Hex=%s\n", bin, oct, n, hex);
 
   // Left shift by 3
   uint32_t shifted = n << 3;
   div_convert(shifted, 2, bin);
   div_convert(shifted, 8, oct);
   div_convert(shifted, 16, hex);
   printf("Left Shift by 3: Binary=%s Octal=%s Decimal=%u Hex=%s\n", bin, oct, shifted, hex);
   // AND with 0xFF
   uint32_t masked = n & 0xFF;
   div_convert(masked, 2, bin);
   div_convert(masked, 8, oct);
   div_convert(masked, 16, hex);
   printf("AND with 0xFF: Binary=%s Octal=%s Decimal=%u Hex=%s\n", bin, oct, masked, hex);
}
