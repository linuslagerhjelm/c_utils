#include <assert.h>
#include <string.h>
#include "split.h"

void testSunnyDayCase() {
  printf("\t testSunnyDayCase - ");
  const char* STR = "path/to/file";
  const char DELIM = '/';
  char** parts = split(STR, DELIM, NULL);
  assert(strncmp(parts[0], "path", 5) == 0);
  assert(strncmp(parts[1], "to", 3) == 0);
  assert(strncmp(parts[2], "file", 5) == 0);
  free(parts[0]);
  free(parts[1]);
  free(parts[2]);
  free(parts);
  printf("pass!\n");
}

void emptyStringReturnsNull() {
  printf("\t emptyStringReturnsNull - ");
  const char* STR = "";
  const char DELIM = '/';
  int* size = malloc(sizeof(int));
  char** parts = split(STR, DELIM, size);
  assert(*size == 0);
  assert(parts == NULL);
  free(size);
  free(parts);
  printf("pass!\n");
}

void delimitersAreExcludedFromResult() {
  printf("\t delimitersAreExcludedFromResult - ");
  const char* STR = "/path/to/";
  const char DELIM = '/';
  char** parts = split(STR, DELIM, NULL);
  
  int len1 = strlen(parts[0]);
  for (int i = 0; i < len1; ++i){
    assert(parts[0][i] != DELIM);
  }

  int len2 = strlen(parts[1]);
  for (int i = 0; i < len2; ++i){
    assert(parts[1][i] != DELIM);
  }
  free(parts[0]);
  free(parts[1]);
  free(parts);
  printf("pass!\n");
}

void consecutiveDelimsDoesNotCreateEmptyIndexes() {
  printf("\t consecutiveDelimsDoesNotCreateEmptyIndexes - ");
  const char* STR = "//path//to//";
  const char DELIM = '/';
  char** parts = split(STR, DELIM, NULL);
  assert(strlen(parts[0]) == 4);
  assert(strlen(parts[1]) == 2);
  free(parts[0]);
  free(parts[1]);
  free(parts);
  printf("pass!\n");
}

void noDelimReturnsUnmodifiedString() {
  printf("\t noDelimReturnsUnmodifiedString - ");
  const char* STR = "pathtofile";
  const char DELIM = '/';
  char** parts = split(STR, DELIM, NULL);
  assert(strncmp(parts[0], STR, strlen(STR)) == 0);
  free(parts[0]);
  free(parts);
  printf("pass!\n");
}

void delimitersOtherThanSlashAreValid() {
  printf("\t delimitersOtherThanSlashAreValid - ");
  const char* STR = "*path*to*file*";
  const char DELIM = '*';
  char** parts = split(STR, DELIM, NULL);
  assert(strncmp(parts[0], "path", 5) == 0);
  assert(strncmp(parts[1], "to", 3) == 0);
  assert(strncmp(parts[2], "file", 5) == 0);
  free(parts[0]);
  free(parts[1]);
  free(parts[2]);
  free(parts);
  printf("pass!\n");
}

int main() {
  printf("Running tests: \n");
  testSunnyDayCase();
  emptyStringReturnsNull();
  delimitersAreExcludedFromResult();
  consecutiveDelimsDoesNotCreateEmptyIndexes();
  noDelimReturnsUnmodifiedString();
  delimitersOtherThanSlashAreValid();
  printf("All tests passed!\n");
}
