/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月08日 星期五 23时51分57秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
const int KIND = 26;
int n, k;
string line;

struct Node {
    Node* next[KIND];

    Node() {
        for (int i = 0; i < KIND; i ++) {
            next[i] = NULL;
        }
    }
} *root;

void addNode(int top, Node *&root) 
{
    if (top == line.length()) {
        return ;
    }
    Node *tr = root;
    int x = line[top] - 'a';
    if (tr->next[x] == NULL) {
        tr->next[x] = new Node();
    }
    addNode(top + 1, tr->next[x]);
}

bool gao(Node *root)
{
    for (int i = 0; i < KIND; i ++) {
        if (root->next[i]) {
            if (!gao(root->next[i])) {
                return true;
            }
        }
    }
    return false;
}

bool check(Node *root)
{
    int flag = 0;
    for (int i = 0; i < KIND; i ++) {
        if (root->next[i]) {
            flag = 1;
            if (!check(root->next[i])) {
                return true;
            }
        }
    }
    if (flag) return false;
    return true;
}

void work()
{

    root = new Node();
    for (int i = 1; i <= n; i ++) {
        cin >> line;
        addNode(0, root);
    }
    int flag = gao(root);
    int flag1 = check(root);
    if (flag) {
        if (flag1) {
            printf("First\n");
        } else {
            if (k & 1) printf("First\n");
            else printf("Second\n");
        }
    } else {
        printf("Second\n");
    }
}
int main()
{
    //freopen("in", "r", stdin);
    while (scanf("%d %d", &n, &k) != EOF) {
        work();
    }
    return 0;
}
