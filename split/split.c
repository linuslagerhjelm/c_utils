#include "split.h"


static void fail(const char* str) {
  fprintf(stderr, "ERROR: %s\n", str);
  exit(EXIT_FAILURE);
}

char** split(const char* str, char delim, int* size) {
  const int len = strnlen(str, BUFSIZ);
  char** out = NULL;
  int start = 0, inserted = 0;

  for (int i = 0; i < len; ++i) {
    if (str[i] == delim) {
      int size = (i - start);
      
      // Handle case: conseccutive delimiters
      if (size == 0) {
        ++start;
        continue;
      }
      
      // Copy string segment between delimiters
      char* substring = calloc((size + 1), sizeof(char));
      memcpy(substring, &str[start], size);
      
      // Append line to out-matrix
      char** newp = realloc(out, (++inserted) * sizeof(char**));
      if (!newp) fail("Out of memmory");
      out = newp;
      out[inserted - 1] = substring;

      start = i + 1;
    }
    if (i == len - 1 && str[i] != delim) {
      int size = (len - start);
      char* substring = calloc((size + 1), sizeof(char));
      memcpy(substring, &str[start], size);
      char** newp = realloc(out, (++inserted) * sizeof(char**));
      
      if (!newp) fail("Out of memmory");
      out = newp;
      out[inserted - 1] = substring;
    }
  }

  if (size != NULL) *size = inserted;
  return out;
}
