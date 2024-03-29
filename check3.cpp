#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int n = 13;
vector<int> a = {1, 2, 4, 5, 7, 6, 7, 8, 11, 10, 11, 12, -1}; // i -> a[i] в 0-индексации, -1 => нет ребра
vector<int> b = {3, 4, 5, 6, 8, 7, 8, 9, 12, 11, 12, -1, -1}; // i -> b[i] в 0-индексации, -1 => нет ребра

bool is_mask_good(int mask) { // возвращает, является ли подмножество удаляемых вершин решением 3-path vertex cover

  for (int i = 0; i < n; ++i) {
    if ((1<<i)&mask) continue; //если вершина i лежит в подмножестве, то дальше ничего не делаем
    if (a[i] != -1 && !((1<<a[i])&mask)) { 
      if (a[a[i]] != -1 && !((1<<a[a[i]])&mask)) return false; // есть путь из 3 вершин
      if (b[a[i]] != -1 && !((1<<b[a[i]])&mask)) return false; // есть путь из 3 вершин
    } 
    if (b[i] != -1 && !((1<<b[i])&mask)) { 
      if (a[b[i]] != -1 && !((1<<a[b[i]])&mask)) return false; // есть путь из 3 вершин
      if (b[b[i]] != -1 && !((1<<b[b[i]])&mask)) return false; // есть путь из 3 вершин
    } 
  }

  return true; //все пути удалены

}

int main(){
#ifdef LOCAL
  freopen("I_input.txt", "r", stdin);
  //freopen("I_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int mask = 0; mask < (1<<n); ++mask) {
    int cnt = __builtin_popcount(mask);
    if (is_mask_good(mask)) {
      assert(cnt >= 7);
    }
  }

}
