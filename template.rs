use std::io::{stdin, Read, StdinLock};
use std::str::FromStr;

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);
}

// from: http://ir5.hatenablog.com/entry/20171209/1512821837
#[allow(dead_code)]
struct Scanner<'a> {
    cin: StdinLock<'a>,
}
#[allow(dead_code)]
impl<'a> Scanner<'a> {
    fn new(cin: StdinLock<'a>) -> Scanner<'a> {
        Scanner { cin: cin }
    }

    fn read<T: FromStr>(&mut self) -> Option<T> {
        let token = self
            .cin
            .by_ref()
            .bytes()
            .map(|c| c.unwrap() as char)
            .skip_while(|c| c.is_whitespace())
            .take_while(|c| !c.is_whitespace())
            .collect::<String>();
        token.parse::<T>().ok()
    }

    fn input<T: FromStr>(&mut self) -> T {
        self.read().unwrap()
    }
}

trait BinarySearch<T> {
    // key 以上の値が最初に現れる index を返す
    fn lower_bound(&self, &T) -> usize;
    // key より大きい値が最初に現れる index を返す
    fn upper_bound(&self, &T) -> usize;
}
use std::cmp::Ordering;
impl<T: Ord> BinarySearch<T> for [T] {
    fn lower_bound(&self, key: &T) -> usize {
        let mut ng = -1;
        let mut ok = self.len() as i64;
        while (ok - ng).abs() > 1 {
            let mid = (ok + ng) / 2;
            match key.cmp(&self[mid as usize]) {
                Ordering::Less | Ordering::Equal => {
                    ok = mid;
                }
                Ordering::Greater => {
                    ng = mid;
                }
            }
        }
        ok as usize
    }

    fn upper_bound(&self, key: &T) -> usize {
        let mut ng = -1;
        let mut ok = self.len() as i64;
        while (ok - ng).abs() > 1 {
            let mid = (ok + ng) / 2;
            match key.cmp(&self[mid as usize]) {
                Ordering::Less => {
                    ok = mid;
                }
                Ordering::Equal | Ordering::Greater => {
                    ng = mid;
                }
            }
        }
        ok as usize
    }
}

fn count_digit(n: i64) -> i64 {
    let mut n = n;
    let mut ret = 0;
    while n > 0 {
        ret += 1;
        n /= 10;
    }
    ret
}

fn digit_sum(n: i64) -> i64 {
    let mut n = n;
    let mut ret = 0;
    while n > 0 {
        ret += n % 10;
        n /= 10;
    }
    ret
}
fn enumerate_divisors(n: i64) -> Vec<i64> {
    let mut ret = Vec::new();
    let mut i = 1;
    while i * i <= n {
        if n % i == 0 {
            ret.push(i);
            if i != 1 && i * i != n {
                ret.push(n / i);
            }
        }
        i += 1;
    }
    ret
}

fn gcd(m: i64, n: i64) -> i64 {
    if m < n {
        gcd(n, m)
    } else {
        if n == 0 {
            m
        } else {
            gcd(n, m % n)
        }
    }
}

fn lcm(m: i64, n: i64) -> i64 {
    m / gcd(m, n) * n
}

fn mod_pow(x: i64, n: i64, modulo: i64) -> i64 {
    let mut n = n;
    let mut x = x;
    let mut ret = 1;
    while n > 0 {
        if n & 1 == 1 {
            ret = ret * x % modulo;
        }
        x = x * x % modulo;
        n >>= 1;
    }
    ret
}

struct UnionFind {
    par: Vec<usize>,
    rank: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let mut vec = vec![0; n];
        for i in 0..n {
            vec[i] = i;
        }
        UnionFind {
            par: vec,
            rank: vec![0; n],
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if x == self.par[x] {
            x
        } else {
            let par = self.par[x];
            let ret = self.find(par);
            self.par[x] = ret;
            ret
        }
    }

    fn is_same(&mut self, a: usize, b: usize) -> bool {
        self.find(a) == self.find(b)
    }

    fn merge(&mut self, a: usize, b: usize) {
        let a_par = self.find(a);
        let b_par = self.find(b);

        if self.rank[a_par] > self.rank[b_par] {
            self.par[b_par] = a_par;
        } else {
            self.par[a_par] = b_par;
            if self.rank[a_par] == self.rank[b_par] {
                self.rank[b_par] += 1;
            }
        }
    }
}

#[derive(Clone, Debug, PartialEq)]
struct Edge {
    to: usize,
    cost: i64,
}

impl Edge {
    fn new(to: usize, cost: i64) -> Edge {
        Edge { to: to, cost: cost }
    }
}
#[derive(Clone, Debug)]
struct Graph {
    n: usize,
    adj_list: Vec<Vec<Edge>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        let adj_list = vec![vec![]; n];
        Graph { n, adj_list }
    }

    fn add_edge(&mut self, u: usize, v: Edge) {
        self.adj_list[u].push(v);
    }
}

fn shortest_path(graph: &Graph, start: usize) -> (Vec<i64>, Vec<Option<usize>>) {
    use std::collections::BinaryHeap;

    let n = graph.n;
    let mut dist: Vec<_> = (0..graph.n).map(|_| std::i64::MAX).collect();
    let mut prevs = vec![None; n];
    let mut heap = BinaryHeap::new();
    dist[start] = 0i64;
    heap.push(std::cmp::Reverse((0i64, start)));

    while let Some(std::cmp::Reverse((cost, cur))) = heap.pop() {
        if cost > dist[cur] {
            continue;
        }

        for next in graph.adj_list[cur].iter() {
            if cost + next.cost < dist[next.to] {
                dist[next.to] = cost + 1;
                prevs[next.to] = Some(cur);
                heap.push(std::cmp::Reverse((cost + next.cost, next.to)));
            }
        }
    }
    (dist, prevs)
}

fn get_path(to: usize, prevs: &Vec<Option<usize>>) -> Vec<usize> {
    let mut path = vec![];
    let mut cur = prevs[to].unwrap();
    while let Some(next) = prevs[cur] {
        path.push(cur);
        cur = next;
    }

    path.reverse();
    path
}

/// from https://docs.rs/permutohedron/0.2.4/permutohedron/
pub trait LexicalPermutation {
    /// Return `true` if the slice was permuted, `false` if it is already
    /// at the last ordered permutation.
    fn next_permutation(&mut self) -> bool;
    /// Return `true` if the slice was permuted, `false` if it is already
    /// at the first ordered permutation.
    fn prev_permutation(&mut self) -> bool;
}

impl<T> LexicalPermutation for [T]
where
    T: Ord,
{
    /// Original author in Rust: Thomas Backman <serenity@exscape.org>
    fn next_permutation(&mut self) -> bool {
        // These cases only have 1 permutation each, so we can't do anything.
        if self.len() < 2 {
            return false;
        }

        // Step 1: Identify the longest, rightmost weakly decreasing part of the vector
        let mut i = self.len() - 1;
        while i > 0 && self[i - 1] >= self[i] {
            i -= 1;
        }

        // If that is the entire vector, this is the last-ordered permutation.
        if i == 0 {
            return false;
        }

        // Step 2: Find the rightmost element larger than the pivot (i-1)
        let mut j = self.len() - 1;
        while j >= i && self[j] <= self[i - 1] {
            j -= 1;
        }

        // Step 3: Swap that element with the pivot
        self.swap(j, i - 1);

        // Step 4: Reverse the (previously) weakly decreasing part
        self[i..].reverse();

        true
    }

    fn prev_permutation(&mut self) -> bool {
        // These cases only have 1 permutation each, so we can't do anything.
        if self.len() < 2 {
            return false;
        }

        // Step 1: Identify the longest, rightmost weakly increasing part of the vector
        let mut i = self.len() - 1;
        while i > 0 && self[i - 1] <= self[i] {
            i -= 1;
        }

        // If that is the entire vector, this is the first-ordered permutation.
        if i == 0 {
            return false;
        }

        // Step 2: Reverse the weakly increasing part
        self[i..].reverse();

        // Step 3: Find the rightmost element equal to or bigger than the pivot (i-1)
        let mut j = self.len() - 1;
        while j >= i && self[j - 1] < self[i - 1] {
            j -= 1;
        }

        // Step 4: Swap that element with the pivot
        self.swap(i - 1, j);

        true
    }
}

#[test]
fn lexical() {
    let mut data = [1, 2, 3];
    data.next_permutation();
    assert_eq!(&data, &[1, 3, 2]);
    data.next_permutation();
    assert_eq!(&data, &[2, 1, 3]);
    data.prev_permutation();
    assert_eq!(&data, &[1, 3, 2]);
    data.prev_permutation();
    assert_eq!(&data, &[1, 2, 3]);
    assert!(!data.prev_permutation());
    let mut c = 0;
    while data.next_permutation() {
        c += 1;
    }
    assert_eq!(c, 5);
}

struct Combination {
    max_n: usize,
    fac: Vec<usize>,
    finv: Vec<usize>,
    inv: Vec<usize>,
}

impl Combination {
    const MOD: usize = 1_000_000_007;
    fn new(max_n: usize) -> Combination {
        let mut fac = vec![0; max_n];
        let mut finv = vec![0; max_n];
        let mut inv = vec![0; max_n];
        fac[0] = 1;
        fac[1] = 1;
        finv[0] = 1;
        finv[1] = 1;
        inv[1] = 1;
        for i in 2..max_n {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
        Combination {
            max_n: max_n,
            fac: fac,
            finv: finv,
            inv: inv,
        }
    }

    fn com(&self, n: usize, k: usize) -> usize {
        if n < k || n < 0 || k < 0 {
            0
        } else {
            self.fac[n] * (self.finv[k] * self.finv[n - k] % MOD) % MOD
        }
    }

    fn hcom(&self, n: usize, k: usize) -> usize {
        if n == 0 && k == 0 {
            1
        } else {
            self.com(n + k - 1, k)
        }
    }
}

struct Bit {
    // Binary Indexed Tree (1-indexed)
    n: usize,
    data: Vec<i64>,
}

impl Bit {
    fn new(n: usize) -> Bit {
        let mut m = 1;
        while m < n {
            m *= 2;
        }
        Bit {
            n: n,
            data: vec![0; m],
        }
    }

    fn sum(&self, i: usize) -> i64 {
        let mut i = i;
        let mut ret = 0;
        while i > 0 {
            ret += self.data[i - 1];
            i -= (i as i64 & -(i as i64)) as usize;
        }
        ret
    }

    fn add(&mut self, i: usize, x: i64) {
        let mut i = i;
        while i < self.n {
            self.data[i - 1] += x;
            i += (i as i64 & -(i as i64)) as usize;
        }
    }
}

#[derive(Clone, Copy)]
struct ModInt(usize);
const MOD: usize = 1_000_000_007;

#[allow(dead_code)]
impl ModInt {
    fn new(n: usize) -> ModInt {
        ModInt(n % MOD)
    }

    fn zero() -> ModInt {
        ModInt(0)
    }

    fn one() -> ModInt {
        ModInt(1)
    }

    fn pow(self, mut n: usize) -> ModInt {
        let mut ret = ModInt::one();
        let mut x = self;
        while n > 0 {
            if n & 1 == 1 {
                ret *= x;
            }
            x *= x;
            n >>= 1;
        }
        ret
    }

    fn inv(self) -> ModInt {
        assert!(self.0 > 0);
        self.pow(MOD - 2)
    }
}

impl std::ops::Add for ModInt {
    type Output = ModInt;
    fn add(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::AddAssign for ModInt {
    fn add_assign(&mut self, rhs: ModInt) {
        *self = *self + rhs;
    }
}

impl std::ops::Sub for ModInt {
    type Output = ModInt;
    fn sub(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + MOD - rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::SubAssign for ModInt {
    fn sub_assign(&mut self, rhs: ModInt) {
        *self = *self - rhs;
    }
}

impl std::ops::Mul for ModInt {
    type Output = ModInt;
    fn mul(self, rhs: ModInt) -> Self::Output {
        ModInt(self.0 * rhs.0 % MOD)
    }
}

impl std::ops::MulAssign for ModInt {
    fn mul_assign(&mut self, rhs: ModInt) {
        *self = *self * rhs;
    }
}

impl std::ops::Neg for ModInt {
    type Output = ModInt;
    fn neg(self) -> Self::Output {
        ModInt(if self.0 == 0 { 0 } else { MOD - self.0 })
    }
}

impl std::fmt::Display for ModInt {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

impl std::str::FromStr for ModInt {
    type Err = std::num::ParseIntError;
    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let val = s.parse::<usize>()?;
        Ok(ModInt::new(val))
    }
}


impl Magma for usize {
    fn op(&self, rhs: &Self) -> Self {
        *self.min(rhs)
    }
}

impl Associative for usize {}

impl Unital for usize {
    fn identity() -> Self {
        std::usize::MAX
    }
}

pub trait Magma: Sized + Clone {
  fn op(&self, rhs: &Self) -> Self;
}

pub trait Associative: Magma {}

pub trait Unital: Magma {
  fn identity() -> Self;
}

pub trait Monoid: Magma + Associative + Unital {}

impl<T: Magma + Associative + Unital> Monoid for T {}

pub struct SegmentTree<T: Monoid> {
    node: Vec<T>,
    sz: usize,
}

impl<T: Monoid> SegmentTree<T> {
    pub fn init(vec: Vec<T>) -> Self {
        let mut sz = 1;
        while sz < vec.len() { sz *= 2; }
        let mut node = vec![T::identity(); sz << 1];
        for i in 0..vec.len() { node[i + sz] = vec[i].clone(); }
        for i in (1..sz).rev() { node[i] = node[i << 1].op(&node[(i << 1) + 1]); }
        SegmentTree { node: node, sz: sz }
    }

    pub fn update(&mut self, i: usize, x: T) {
        let mut idx = i + self.sz;
        self.node[idx] = x;
        while idx > 1 {
            idx = idx >> 1;
            self.node[idx] = self.node[idx << 1].op(&self.node[(idx << 1)  + 1]);
        }
    }

    pub fn fold(&self, left: usize, right: usize) -> T {
        let mut lx = T::identity();
        let mut rx = T::identity();
        let mut l = left + self.sz;
        let mut r = right + self.sz;
        while l < r {
            if (l & 1) == 1 { lx = lx.op(&self.node[l]); }
            if (r & 1) == 0 { rx = self.node[r].op(&rx); }
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        if l == r { lx = lx.op(&self.node[l]); }
        lx.op(&rx)
    }
}

trait MultiSet<T> {
    fn add(&mut self, key: T);
    fn del(&mut self, key: T);
    fn least(&self) -> Option<T>;
    fn most(&self) -> Option<T>;
}

impl<T: Ord + Clone> MultiSet<T> for BTreeMap<T, usize> {
    fn add(&mut self, key: T) {
        *self.entry(key).or_insert(0) += 1;
    }

    fn del(&mut self, key: T) {
        if let Some(value) = self.get_mut(&key) {
            *value -= 1;
            if *value == 0 {
                self.remove(&key);
            }
        }
    }

    fn least(&self) -> Option<T> {
        self.iter().next().map(|(k, _)| k.clone())
    }

    fn most(&self) -> Option<T> {
        self.iter().next_back().map(|(k, _)| k.clone())
    }
}
