// C program to create a binary tree and display it visually
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 100
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];
#define INFINITY (1<<20)
#define GAP 3

struct node {
    int d;
    struct node *l, *r;
};
struct node *root = NULL;

// Tree creation
void create(int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->d = data;
    new->l = new->r = NULL;
    if (root == NULL) {
        root = new;
    } else {
        struct node *t = root;
        while (1) {
            if (data < t->d) {
                if (t->l == NULL) {
                    t->l = new;
                    break;
                } else {
                    t = t->l;
                }
            } else {
                if (t->r == NULL) {
                    t->r = new;
                    break;
                } else {
                    t = t->r;
                }
            }
        }
    }
}

// Inorder traversal
void inorder(struct node *t) {
    if (t != NULL) {
        inorder(t->l);
        printf("%d->", t->d);
        inorder(t->r);
    }
}

// Preorder traversal
void preorder(struct node *t) {
    if (t != NULL) {
        printf("%d->", t->d);
        preorder(t->l);
        preorder(t->r);
    }
}

// Postorder traversal
void postorder(struct node *t) {
    if (t != NULL) {
        postorder(t->l);
        postorder(t->r);
        printf("%d->", t->d);
    }
}

// ASCII Tree printing structures and helpers
typedef struct asciinode_struct {
    struct asciinode_struct *left, *right;
    int edge_length, height, lablen;
    int parent_dir;
    char label[11];
} asciinode;

int print_next;

asciinode *build_ascii_tree_recursive(struct node *t) {
    if (t == NULL) return NULL;
    asciinode *node = malloc(sizeof(asciinode));
    node->left = build_ascii_tree_recursive(t->l);
    node->right = build_ascii_tree_recursive(t->r);
    if (node->left) node->left->parent_dir = -1;
    if (node->right) node->right->parent_dir = 1;
    sprintf(node->label, "%d", t->d);
    node->lablen = strlen(node->label);
    return node;
}

asciinode *build_ascii_tree(struct node *t) {
    if (t == NULL) return NULL;
    asciinode *node = build_ascii_tree_recursive(t);
    node->parent_dir = 0;
    return node;
}

void free_ascii_tree(asciinode *node) {
    if (node == NULL) return;
    free_ascii_tree(node->left);
    free_ascii_tree(node->right);
    free(node);
}

void compute_lprofile(asciinode *node, int x, int y) {
    if (node == NULL) return;
    int isleft = node->parent_dir == -1;
    lprofile[y] = lprofile[y] < x - ((node->lablen - isleft) / 2) ? lprofile[y] : x - ((node->lablen - isleft) / 2);
    if (node->left != NULL)
        for (int i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++)
            lprofile[y + i] = lprofile[y + i] < x - i ? lprofile[y + i] : x - i;
    compute_lprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    compute_lprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

void compute_rprofile(asciinode *node, int x, int y) {
    if (node == NULL) return;
    int notleft = node->parent_dir != -1;
    rprofile[y] = rprofile[y] > x + ((node->lablen - notleft) / 2) ? rprofile[y] : x + ((node->lablen - notleft) / 2);
    if (node->right != NULL)
        for (int i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++)
            rprofile[y + i] = rprofile[y + i] > x + i ? rprofile[y + i] : x + i;
    compute_rprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    compute_rprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

void compute_edge_lengths(asciinode *node) {
    if (node == NULL) return;
    compute_edge_lengths(node->left);
    compute_edge_lengths(node->right);

    if (node->left == NULL && node->right == NULL) {
        node->edge_length = 0;
    } else {
        int hmin = node->left ? node->left->height : 0;
        if (node->right) {
            hmin = node->right->height < hmin ? node->right->height : hmin;
        }
        int delta = 4;
        for (int i = 0; i < hmin; i++) {
            int gap = GAP + 1 + rprofile[i] - lprofile[i];
            if (gap > delta) delta = gap;
        }
        if (((node->left && node->left->height == 1) || (node->right && node->right->height == 1)) && delta > 4)
            delta--;
        node->edge_length = ((delta + 1) / 2) - 1;
    }

    int h = 1;
    if (node->left)
        h = node->left->height + node->edge_length + 1 > h ? node->left->height + node->edge_length + 1 : h;
    if (node->right)
        h = node->right->height + node->edge_length + 1 > h ? node->right->height + node->edge_length + 1 : h;
    node->height = h;
}

void print_level(asciinode *node, int x, int level) {
    if (node == NULL) return;
    int isleft = node->parent_dir == -1;
    if (level == 0) {
        int i = 0;
        for (; i < (x - print_next - ((node->lablen - isleft) / 2)); i++) printf(" ");
        print_next += i;
        printf("%s", node->label);
        print_next += node->lablen;
    } else if (node->edge_length >= level) {
        if (node->left) {
            int i = 0;
            for (; i < (x - print_next - level); i++) printf(" ");
            print_next += i;
            printf("/");
            print_next++;
        }
        if (node->right) {
            int i = 0;
            for (; i < (x - print_next + level); i++) printf(" ");
            print_next += i;
            printf("\\");
            print_next++;
        }
    } else {
        print_level(node->left, x - node->edge_length - 1, level - node->edge_length - 1);
        print_level(node->right, x + node->edge_length + 1, level - node->edge_length - 1);
    }
}

void print_ascii_tree(struct node *t) {
    if (t == NULL) return;
    asciinode *proot = build_ascii_tree(t);
    compute_edge_lengths(proot);
    for (int i = 0; i < proot->height && i < MAX_HEIGHT; i++) lprofile[i] = INFINITY;
    compute_lprofile(proot, 0, 0);
    int xmin = 0;
    for (int i = 0; i < proot->height && i < MAX_HEIGHT; i++) xmin = xmin < lprofile[i] ? xmin : lprofile[i];

    for (int i = 0; i < proot->height; i++) {
        print_next = 0;
        print_level(proot, -xmin, i);
        printf("\n");
    }

    free_ascii_tree(proot);
}

// Display all traversals and tree
void display() {
    if (root == NULL) {
        printf("Tree is empty\n");
    } else {
        printf("\nVisual Binary Tree:\n");
        print_ascii_tree(root);
        printf("\nInorder:\n");
        inorder(root);
        printf("NULL\nPreorder:\n");
        preorder(root);
        printf("NULL\nPostorder:\n");
        postorder(root);
        printf("NULL\n");
    }
}

int main() {
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        create(data);
    }
    display();
    return 0;
}
