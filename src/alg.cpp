// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int ct = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        ct++;
      }
    }
  }
  return ct;
}
int countPairs2(int *arr, int len, int value) {
  int lt = 0;
  int rt = len - 1;
  int ct = 0;
  while (lt < rt) {
    int sum = arr[lt] + arr[rt];
  if (sum == value) {
    ct++;
    lt++;
    rt--;
    } else if (sum < value) {
  lt++;
  } else {
  rt--;
  }
    }
  return ct;
}
int countPairs3(int *arr, int len, int value) {
  int ct = 0;
  for (int i = 0; i < len; i++) {
    int tg = value - arr[i];
    int lt = i + 1;
    int rt = len - 1;
    while (lt <= rt) {
      int m = lt + (rt - lt) / 2;
      if (arr[m] == tg) {
        ct++;
        break;
      } else if (arr[m] < tg) {
        lt = m + 1;
      } else {
        rt = m - 1;
      }
    }
  }
  return ct;
}
