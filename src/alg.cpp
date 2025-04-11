// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, 
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] != arr[right]) {
                int left_val = arr[left];
                int left_count = 1;
                while (left + 1 < right && arr[left+1] == left_val) {
                    left++;
                    left_count++;
                }
                int right_val = arr[right];
                int right_count = 1;
                while (right - 1 > left && arr[right-1] == right_val) {
                    right--;
                    right_count++;
                }
                count += left_count * right_count;
                left++;
                right--;
            } else {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
        } 
        else if (sum < value) left++;
        else right--;
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int target = value - arr[i];
        int low = i + 1, high = len - 1;
        int first = len;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                first = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low = i + 1, high = len - 1;
        int last = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target) {
                last = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (first <= last) {
            count += last - first + 1;
        }
    }
    return count;
}
