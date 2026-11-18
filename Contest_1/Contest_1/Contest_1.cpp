#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TASK_10

#ifdef TASK_1
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* heights = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int k;
    while (scanf("%d", &k) && k != -1) {
        int idx = k - 1;
        int left_count = 0;
        int right_count = 0;
        int current_max;

        current_max = heights[idx];
        for (int i = idx - 1; i >= 0; i--) {
            if (heights[i] >= current_max) {
                left_count++;
                current_max = heights[i];
            }
        }

        current_max = heights[idx];
        for (int i = idx + 1; i < n; i++) {
            if (heights[i] >= current_max) {
                right_count++;
                current_max = heights[i];
            }
        }
        printf("%d %d\n", left_count, right_count);
    }
    return 0;
}
#endif

#ifdef TASK_2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int min = 100;
    int max = 9;

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);

        if (num < min) min = num;
        if (num > max) max = num;
    }

    int sumMin = (min / 10) + (min % 10);
    int sumMax = (max / 10) + (max % 10);

    printf("%d %d\n", sumMax, sumMin);

    if (sumMax == sumMin) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;
}

#endif


#ifdef TASK_3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int arr[10000];
    double sum = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    double average = sum / N;
    int result[10000];
    int idx = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] >= average) {
            result[idx++] = arr[i];
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] < average) {
            result[idx++] = arr[i];
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}

#endif

#ifdef TASK_4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int arr[100000];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    
    for (int i = N-1; i >= 0 ; i--) {
        int num = arr[i];
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        printf("%d\n", sum);
    }

    return 0;
}

#endif

#ifdef TASK_5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int can_form_multiple_of_six(int num) {
    if (num < 0) num = -num;

    if (num == 0) return 1;

    int digits[10] = { 0 };
    int sum = 0;
    int temp = num;

    while (temp > 0) {
        int digit = temp % 10;
        digits[digit]++;
        sum += digit;
        temp /= 10;
    }

    if (sum % 3 != 0) return 0;

    for (int i = 0; i <= 8; i += 2) {
        if (digits[i] > 0) return 1;
    }

    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    while (scanf("%d", &k) && k != -1) {
        k--;

        int divisible_by_3 = (arr[k] % 3 == 0);
        int can_form_6 = can_form_multiple_of_six(arr[k]);

        if (divisible_by_3 && can_form_6) {
            printf("Yes Yes\n");
        }
        else if (divisible_by_3 && !can_form_6) {
            printf("Yes No\n");
        }
        else {
            printf("No No\n");
        }
    }

    free(arr);
    return 0;
}

#endif

#ifdef TASK_6
#include <stdio.h>

#define MAX_SIZE 220001

int main() {
    int N;
    scanf("%d", &N);

    int presence[MAX_SIZE] = { 0 };

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        if (num < MAX_SIZE) {
            presence[num] = 1;
        }
    }

    int M;
    scanf("%d", &M);
    int count = 0;

    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        if (num < MAX_SIZE && presence[num]) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}

#endif

#ifdef TASK_7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int popular = arr[0];
    int max_count = 1;

    for (int i = 0; i < N; i++) {
        int count = 1;

        for (int j = i + 1; j < N; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        if (count > max_count) {
            max_count = count;
            popular = arr[i];
        }
    }

    printf("%d\n", popular);
    free(arr);
    return 0;
}
#endif

#ifdef TASK_8
#include <stdio.h>

int main() {
    char symbol;
    int balance = 0;

    while (scanf("%c", &symbol) == 1 && symbol != '\n' && symbol != '\0') {
        if (symbol == '(') {
            balance++;
        }
        else if (symbol == ')') {
            balance--;
            if (balance < 0) {
                printf("No\n");
                return 0;
            }
        }
        else if (symbol != ' ') {
            printf("No\n");
            return 0;
        }
    }

    if (balance == 0) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;
}

#endif

#ifdef TASK_9
#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    char str[MAX_SIZE + 1];
    scanf("%s", str);

    char stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stack[++top] = str[i];
        }
        else {
            if (top == -1) {
                printf("No\n");
                return 0;
            }

            char last = stack[top--];
            if ((str[i] == ')' && last != '(') ||
                (str[i] == ']' && last != '[') ||
                (str[i] == '}' && last != '{')) {
                printf("No\n");
                return 0;
            }
        }
    }

    if (top == -1) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;
}
#endif

#ifdef TASK_10
#include <stdio.h>

#define MAX_SIZE 100000

int main_stack[MAX_SIZE];
int max_stack[MAX_SIZE];
int min_stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Overflow\n");
        return;
    }

    top++;
    main_stack[top] = value;

    if (top == 0) {
        max_stack[top] = value;
        min_stack[top] = value;
    }
    else {
        max_stack[top] = (value > max_stack[top - 1]) ? value : max_stack[top - 1];
        min_stack[top] = (value < min_stack[top - 1]) ? value : min_stack[top - 1];
    }
}

void pop() {
    if (top < 0) {
        printf("Underflow\n");
        return;
    }
    top--;
}

void get_top() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", main_stack[top]);
}

void get_max() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", max_stack[top]);
}

void get_min() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", min_stack[top]);
}

int main() {
    int command;

    while (1) {
        scanf("%d", &command);

        switch (command) {
        case 0: {
            int value;
            scanf("%d", &value);
            push(value);
            break;
        }
        case 1:
            pop();
            break;
        case 2:
            get_top();
            break;
        case 3:
            get_max();
            break;
        case 4:
            get_min();
            break;
        case 5:
            return 0;
        }
    }

    return 0;
}
#endif