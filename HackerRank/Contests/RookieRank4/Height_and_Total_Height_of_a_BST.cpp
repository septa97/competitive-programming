#include <cstdio>
#include <cstdlib>

#define max(x, y) (x > y ? x : y)

using namespace std;

struct node {
    int num;
    int height;
    struct node *left, *right, *parent;
};

struct node* create_node(int n) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->num = n;
    temp->height = 0;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;

    return temp;
}

void update_height(struct node* node) {
    while (node->parent != NULL) {
        int child_height = node->height;
        node = node->parent;
        node->height = max(node->height, child_height+1);
    }
}

struct node* insert_node(struct node *node, int n) {
    if (node == NULL) {
        return create_node(n);
    }

    if (n < node->num) {
        node->left = insert_node(node->left, n);
        node->left->parent = node;
        if (node->left->left == NULL && node->left->right == NULL) update_height(node->left);
    }
    else if (n > node->num) {
        node->right = insert_node(node->right, n);
        node->right->parent = node;
        if (node->right->left == NULL && node->right->right == NULL) update_height(node->right);
    }

    return node;
}

int total_height(struct node* node) {
    if (node == NULL) return 0;
    if (node->height == 0) return 0;

    return total_height(node->left) + total_height(node->right) + node->height;
}

int main() {
    int n, temp;
    scanf("%d", &n);

    scanf("%d", &temp);
    struct node *root = NULL;
    root = insert_node(root, temp);

    for (int i = 1; i < n; i++) {
        scanf("%d", &temp);
        insert_node(root, temp);
    }

    printf("%d\n", root->height);
    printf("%d\n", total_height(root));

    return 0;
}
