1. #include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s[100];
    int n, i, choice, roll, found = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Create
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    do {
        printf("\n1. Display\n2. Search\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nRoll\tName\tMarks\n");
            for (i = 0; i < n; i++)
                printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
            break;

        case 2:
            printf("Enter roll number to search: ");
            scanf("%d", &roll);
            found = 0;
            for (i = 0; i < n; i++) {
                if (s[i].roll == roll) {
                    printf("Record found: %d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Record not found!\n");
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}

2. #include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push() {
    int val;
    if (top == SIZE - 1)
        printf("Stack Overflow!\n");
    else {
        printf("Enter value to push: ");
        scanf("%d", &val);
        stack[++top] = val;
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("Popped element: %d\n", stack[top--]);
}

void display() {
    int i;
    if (top == -1)
        printf("Stack is empty!\n");
    else {
        printf("Stack elements:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main() {
    int choice;
    do {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: display(); break;
        case 4: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}

3.#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char line[100];
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd() {
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter line of text: ");
    fflush(stdin);
    gets(newNode->line);
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteLine() {
    int pos, i;
    struct Node *temp = head, *prev;
    if (head == NULL) {
        printf("No lines to delete!\n");
        return;
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    for (i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("No text to display!\n");
        return;
    }
    printf("\nText content:\n");
    while (temp != NULL) {
        printf("%s\n", temp->line);
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        printf("\n1.Insert Line\n2.Delete Line\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: insertEnd(); break;
        case 2: deleteLine(); break;
        case 3: display(); break;
        case 4: printf("Exiting...\n"); break;
        default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}

4. #include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node *left, *right;
};

struct Node* createNode(char name[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, char name[]) {
    if (root == NULL)
        return createNode(name);
    if (strcmp(name, root->name) < 0)
        root->left = insert(root->left, name);
    else
        root->right = insert(root->right, name);
    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->name);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%s ", root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->name);
    }
}

void search(struct Node *root, char key[]) {
    if (root == NULL) {
        printf("Name not found!\n");
        return;
    }
    if (strcmp(key, root->name) == 0)
        printf("Name found: %s\n", root->name);
    else if (strcmp(key, root->name) < 0)
        search(root->left, key);
    else
        search(root->right, key);
}

int main() {
    struct Node *root = NULL;
    char name[50];
    int n, i;
    printf("Enter number of names: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", name);
        root = insert(root, name);
    }

    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);

    printf("\n\nEnter name to search: ");
    scanf("%s", name);
    search(root, name);
    return 0;
}

5.#include <stdio.h>

int main() {
    int a[10][10], q[10], vis[10] = {0};
    int n, i, j, front = 0, rear = -1, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &v);

    q[++rear] = v;
    vis[v] = 1;
    printf("BFS: ");

    while (front <= rear) {
        v = q[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (a[v][i] && !vis[i]) {
                q[++rear] = i;
                vis[i] = 1;
            }
        }
    }
    return 0;
}

6. #include <stdio.h>
int main() {
    int i, j;
    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= i; j++)
            printf("%d", j);
        printf("\n");
    }
    return 0;
}

7.#include <stdio.h>

int main() {
    int n = 4;

    // Upper part of diamond
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++)
            printf(" ");
        for (int k = 1; k <= i; k++)
            printf("%d ", i);
        printf("\n");
    }

    // Lower part of diamond
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--)
            printf(" ");
        for (int k = 1; k <= i; k++)
            printf("%d ", i);
        printf("\n");
    }

    return 0;
}

8.#include <stdio.h>

int main() {
    int n = 4;
    int i, j, k;

    for (i = 1; i <= n; i++) {
        for (j = i; j < n; j++)
            printf(" ");
        for (k = 1; k <= i; k++)
            printf("* ");
        printf("\n");
    }

    return 0;
}


9. #include <stdio.h>

int main() {
    int n = 4;
    int i, j, k;
    char ch;

    for (i = 1; i <= n; i++) {
        // Print spaces
        for (j = i; j < n; j++)
            printf("  ");

        // Print ascending letters
        for (k = 1; k <= i; k++) {
            ch = 'A' + k - 1;
            printf("%c ", ch);
        }

        // Print descending letters
        for (k = i - 1; k >= 1; k--) {
            ch = 'A' + k - 1;
            printf("%c ", ch);
        }

        printf("\n");
    }

    return 0;
}

11.#include <stdio.h>

int main() {
    int n, i, key, first, last, mid;
    int arr[50];
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in ascending order: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    first = 0;
    last = n - 1;

    while (first <= last) {
        mid = (first + last) / 2;

        if (arr[mid] == key) {
            printf("Element %d found at position %d\n", key, mid + 1);
            found = 1;
            break;
        } else if (arr[mid] < key)
            first = mid + 1;
        else
            last = mid - 1;
    }

    if (found == 0)
        printf("Element %d not found\n", key);

    return 0;
}

10. #include <stdio.h>
#include <string.h>

int main() {
    int n, i, found = 0;
    char names[50][30], search[30];

    printf("Enter number of names: ");
    scanf("%d", &n);

    printf("Enter %d names:\n", n);
    for (i = 0; i < n; i++)
        scanf("%s", names[i]);

    printf("Enter name to search: ");
    scanf("%s", search);

    for (i = 0; i < n; i++) {
        if (strcmp(names[i], search) == 0) {
            printf("Name %s found at position %d\n", search, i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Name %s not found\n", search);

    return 0;
}

12.#include <stdio.h>

int main() {
    int n, i, j;
    float a[50], temp;

    printf("Enter number of products: ");
    scanf("%d", &n);

    printf("Enter product prices:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &a[i]);

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

    printf("\nSorted prices:\n");
    for (i = 0; i < n; i++)
        printf("%.2f ", a[i]);

    return 0;
}


13.#include <stdio.h>

int main() {
    int n, i, j, min;
    float a[50], temp;

    printf("Enter number of products: ");
    scanf("%d", &n);

    printf("Enter product prices:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &a[i]);

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("\nSorted prices:\n");
    for (i = 0; i < n; i++)
        printf("%.2f ", a[i]);

    return 0;
}

14,#include <stdio.h>

int main() {
    int n, i, j;
    float a[50], key;

    printf("Enter number of products: ");
    scanf("%d", &n);

    printf("Enter product prices:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &a[i]);

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    printf("\nSorted prices:\n");
    for (i = 0; i < n; i++)
        printf("%.2f ", a[i]);

    return 0;
}
