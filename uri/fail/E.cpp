#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

typedef struct {
  string filename;
  unsigned long long size;
  unsigned long long offset;
} cell;

typedef struct {
  unsigned long long space;
  unsigned long long offset;
} blank;

typedef struct {
  vector<blank> v;
  unsigned long long not_used;
} blank_space;

typedef struct {
  vector<cell> v;
  unsigned long long used;
  unsigned long long space;
} disc;

blank_space empty;
disc drive;

void otimiza() {
  empty.v.clear();
  blank b;
  b.offset = drive.used;
  b.space = empty.not_used;
  empty.v.push_back(b);
}

bool insert(string filename, unsigned long long size) {
  blank *b = NULL;
  cell c;
  if (empty.not_used < size) return false;
  for (vector<blank>::iterator it = empty.v.begin(); it != empty.v.end(); it++) {
    if (it->space >= size)
      b = &(*it);
  }
  if (b == NULL) {
    otimiza();
    for (vector<blank>::iterator it = empty.v.begin(); it != empty.v.end(); it++) {
      printf("Blank: %d\n", it->space);
      if (it->space >= size)
        b = &(*it);
    }
  }
  c.filename = filename;
  c.size = size;
  c.offset = b->offset;
  drive.used += size;

  b->offset += size;
  b->space -= size;
  empty.not_used -= size;
  drive.v.push_back(c);
  return true;
}

int remove(string filename) {
  for (vector<cell>::iterator it = drive.v.begin(); it != drive.v.end(); it++) {
    if (filename == it->filename) {
      blank new_blank;
      new_blank.space = it->size;
      new_blank.offset = it->offset;

      empty.not_used += new_blank.space;
      for (vector<blank>::iterator i = empty.v.begin(); i != empty.v.end(); i++) {
        if (i->offset > new_blank.offset) {
          empty.v.insert(i, new_blank);
          break;
        }
      }

      drive.used -= new_blank.space;
      it = drive.v.erase(it);
      break;
    }
  }
}

unsigned long long get_bytes_size(char *s) {
  int len = strlen(s);
  char deg;
  unsigned long long result;
  deg = s[len-2];
  s[len-2] = '\0';

  printf("Num: %s%c\n", s, deg);

  result = atof(s);
  switch(deg) {
    case 'G':
      result = result * 1024 * 1024 * 1024;
      break;
    case 'M':
      result = result * 1024 * 1024;
      break;
    case 'K':
      result = result * 1024;
      break;
  }
  return result;
}

int main() {
  for (int n; scanf("%d\n", &n) != EOF && n;) {
    printf("%d\n", n);
    char sizeof_disc_s[10];
    bool error = false;

    drive.used = 0;
    drive.v.clear();
    empty.v.clear();


    scanf("%s\n", sizeof_disc_s);
    printf("Space %s\n", sizeof_disc_s);
    drive.space = get_bytes_size(sizeof_disc_s);
    
    blank first;
    first.space = drive.space;
    first.offset = 0;
    empty.v.push_back(first);
    empty.not_used = drive.space;

    printf("Space: %lld\n", drive.space);
    for (int i = 0; i < n; i++) {
      char inst[100], filename[20], size_s[10];
      unsigned long long size;
      scanf("%s", inst);
      printf("Blank space: %lld\n", empty.not_used);
      printf("Inst: %s\n", inst);

      if (!strcmp("insere", inst)) {
        scanf("%s %s\n", filename, size_s);
        size = get_bytes_size(size_s);
        printf("bytes: %llu\n", size);
        if (!insert(string(filename), size))
          error = true;
      } else if (!strcmp("remove", inst)) {
        scanf("%s\n", filename);
        remove(string(filename));
      } else {
        scanf("\n");
        otimiza();
      }
    }

    if (error)
      printf("ERRO: disco cheio\n");
    else {
      unsigned long long block = drive.space / 8;
      unsigned long long used = drive.used;
      for (int i = 0; i < 8; i++) {
        printf("[");
        if (used > block || block*0.75 <= used) {
          printf("#] ");
        } else if (block*0.25 <= used) {
          printf("-] ");
        } else {
          printf(" ] ");
        }
        used -= block;
      }
      printf("\n");
    }
  }
}
