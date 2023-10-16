#include <stdio.h>

int main() {
  long long int A, B, C;
  scanf("%lld %lld %lld", &A, &B, &C);

  if (A == B && B == C) {
    return 0;
  }

  if (A > B && A > C) {
    printf("Daging\n");
    if (B > C) {
      printf("Sayur\n");
      printf("Telur\n");
    } else {
      printf("Telur\n");
      printf("Sayur\n");
    }
  } else if (B > A && B > C) {
    printf("Sayur\n");
    if (A > C) {
      printf("Daging\n");
      printf("Telur\n");
    } else {
      printf("Telur\n");
      printf("Daging\n");
    }
  } else if (C > A && C > B) {
    printf("Telur\n");
    if (A > B) {
      printf("Daging\n");
      printf("Sayur\n");
    } else {
      printf("Sayur\n");
      printf("Daging\n");
    }
  }

  return 0;
}
