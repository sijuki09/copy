#include <stdlib.h>

int main() {
  int return_value;
  return_value = system("bash script.sh");
  return return_value;
}
