#include <dirent.h>
#include <stdio.h>

int main(void) {
  DIR *dir = opendir(".");
  if (dir == NULL) {
    perror("opendir");
    return 1;
  }

  struct dirent *S;
  while ((S = readdir(dir)) != NULL) {
    if (S->d_name[0] != '.') {
      printf("%s\n", S->d_name);
    }
  }

  closedir(dir);
  return 0;
}
