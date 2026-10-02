#include <stdio.h>

int main(int argc, char *argv[]){
  int arr[256] = {0};
  for (int i = 1; i < argc ; i++) {
    for (int j = 0; argv[i][j] != '\0' ; j++) {
      if (argv[i][j] != '"'){
        arr[argv[i][j]]++;
      }

      else{

      }

    }

  }
  for (int x = 0;  x < 256 ; x++){
    if (arr[x] > 0){
      printf ("%c:%d\n", x, arr[x]);
    }
  }
  return 0;
}