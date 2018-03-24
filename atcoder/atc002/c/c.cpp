// AtCoder Typical Contenst 002
// C - 最適二分探索木

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 100000
#define INF 1000000000


// SkewHeap (併合可能ヒープ, Meldable Heap)
template <class T>
class Node {
public:
  Node<T> *l, *r;
  T val;
  Node();
};

template <class T>
Node<T>::Node() {
  l = NULL;
  r = NULL;
  return;
}

template <class T>
Node<T> *merge(Node<T> *a, Node<T> *b) {
  if (a == NULL) {
    return b;
  }
  if (b == NULL) {
    return a;
  }

  if (a->val > b->val) {
    swap(a, b);
  }
  a->r = merge(a->r, b);
  swap(a->l, a->r);

  return a;
}

template <class T>
class SkewHeap {
private:
  Node<T> *root;
  T default_val;
  // void delete_recursively(Node<T> *n);
public:
  SkewHeap() : root(NULL), default_val(INF) {};
  void meld(SkewHeap *sh);
  T first();
  T second();
  void push(T x);
  void pop();
};

template <class T>
void SkewHeap<T>::meld(SkewHeap<T> *sh) {
  root = merge(root, sh->root);
  return;
}

template <class T>
T SkewHeap<T>::first() {
  return (root == NULL) ? default_val : root->val;
}

template <class T>
T SkewHeap<T>::second() {
  T l_val, r_val;
  if (root == NULL) {
    return default_val;
  }
  l_val = (root->l == NULL) ? default_val : root->l->val;
  r_val = (root->r == NULL) ? default_val : root->r->val;
  return min(l_val, r_val);
}

template <class T>
void SkewHeap<T>::push(T x) {
  Node<T> *n = new Node<T>;
  n->val = x;
  root = merge(root, n);
  return;
}

template <class T>
void SkewHeap<T>::pop() {
  Node<T> *n = root;
  root = merge(root->l, root->r);
  delete n;
  return;
}


typedef long long int ll;
typedef pair<int, pair<int, int> > type_piii;

int N;
SkewHeap<ll> sh[MAX_N + 2];
bool is_leaf[MAX_N + 2];
int l_idxs[MAX_N + 2], r_idxs[MAX_N + 2];
priority_queue<type_piii, vector<type_piii>, greater<type_piii> > q;
ll ans;

int meld_lr(int l_idx, int r_idx) {
  // printf("meld_lr l: %d r: %d\n", l_idx, r_idx);
  sh[l_idx].meld(&sh[r_idx]);
  is_leaf[l_idx] = false;
  l_idxs[r_idxs[r_idx]] = l_idxs[r_idx];
  r_idxs[l_idxs[r_idx]] = r_idxs[r_idx];
  l_idxs[r_idx] = -1;
  r_idxs[r_idx] = -1;
  return l_idx;
}

int main() {

  int w, idx, r_idx;
  ll sum, cost;
  pair<ll, pair<int, int> > piii;

  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &w);
    sh[i].push(w);
    is_leaf[i] = true;
    l_idxs[i] = i - 1;
    r_idxs[i] = i + 1;
  }
  is_leaf[0] = true;
  l_idxs[0] = 0;
  r_idxs[0] = 1;
  is_leaf[N + 1] = true;
  l_idxs[N + 1] = N;
  r_idxs[N + 1] = N + 1;

  for (int i = 1; i <= N - 1; i++) {
    q.push(make_pair(sh[i].first() + sh[i + 1].first(), make_pair(i, i + 1)));
  }

  ans = 0;
  while (!q.empty()) {
    piii = q.top();
    q.pop();
    cost = piii.first;
    idx = piii.second.first;
    r_idx = piii.second.second;
    // printf("cost: %lld, idx: %d, r_idx: %d, q_size: %lu\n", cost, idx, r_idx, q.size());
    if (cost >= INF) {
      continue;
    }
    if (idx == 0 || r_idx == N + 1) {
      continue;
    }
    if (l_idxs[idx] == -1 || l_idxs[r_idx] == -1) {
      continue;
    }
    if (idx == r_idx) {
      if (sh[idx].first() + sh[idx].second() != cost) {
        continue;
      }
    } else {
      if (sh[idx].first() + sh[r_idx].first() != cost) {
        continue;
      }
    }

    ans += cost;

    sum = 0;
    sum += sh[idx].first();
    sh[idx].pop();
    sum += sh[r_idx].first();
    sh[r_idx].pop();
    sh[idx].push(sum);
    if (idx != r_idx) {
      idx = meld_lr(idx, r_idx);
      if (l_idxs[idx] != 0 && !is_leaf[l_idxs[idx]]) {
        idx = meld_lr(l_idxs[idx], idx);
      }
      if (r_idxs[idx] != N + 1 && !is_leaf[r_idxs[idx]]) {
        idx = meld_lr(idx, r_idxs[idx]);
      }
    }
    // for (int i = 1; i <= N; i++) {
    //   printf("[%d] is_leaf: %c, l_idx: %d, r_idx: %d, first: %lld\n", i, is_leaf[i] ? 'T' : 'F', l_idxs[i], r_idxs[i], sh[i].first());
    // }

    q.push(make_pair(sh[idx].first() + sh[idx].second(), make_pair(idx, idx)));
    q.push(make_pair(sh[l_idxs[idx]].first() + sh[idx].first(), make_pair(l_idxs[idx], idx)));
    q.push(make_pair(sh[idx].first() + sh[r_idxs[idx]].first(), make_pair(idx, r_idxs[idx])));
    q.push(make_pair(sh[l_idxs[idx]].first() + sh[r_idxs[idx]].first(), make_pair(l_idxs[idx], r_idxs[idx])));
    // printf("ans: %lld\n", ans);
  }

  printf("%lld\n", ans);

  return 0;

}
