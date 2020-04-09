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
        let token = self.cin.by_ref().bytes().map(|c| c.unwrap() as char)
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
    let mut res = 0;
    while n > 0 {
        res += 1;
        n /= 10;
    }
    res
}

fn digit_sum(n: i64) -> i64 {
    let mut n = n;
    let mut res = 0;
    while n > 0 {
        res += n % 10;
        n /= 10;
    }
    res
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

fn mod_pow(x: i64, n:i64, modulo: i64) -> i64 {
    let mut n = n;
    let mut x = x;
    let mut res = 1;
    while n > 0 {
        if n & 1 == 1{
            res = res * x % modulo;
        }
        x = x * x % modulo;
        n >>= 1;
    }
    res
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
            let res = self.find(par);
            self.par[x] = res;
            res
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

struct Graph {
    n: usize,
    adj_list: Vec<Vec<usize>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        let adj_list = vec![vec![]; n];
        Graph { n: n, adj_list: adj_list }
    }

    fn add_edge(&mut self, u: usize, v: usize) {
        self.adj_list[u].push(v);
    }
}
pub trait LexicalPermutation {
    /// Return `true` if the slice was permuted, `false` if it is already
    /// at the last ordered permutation.
    fn next_permutation(&mut self) -> bool;
    /// Return `true` if the slice was permuted, `false` if it is already
    /// at the first ordered permutation.
    fn prev_permutation(&mut self) -> bool;
}

impl<T> LexicalPermutation for [T] where T: Ord {
    /// Original author in Rust: Thomas Backman <serenity@exscape.org>
    fn next_permutation(&mut self) -> bool {
        // These cases only have 1 permutation each, so we can't do anything.
        if self.len() < 2 { return false; }

        // Step 1: Identify the longest, rightmost weakly decreasing part of the vector
        let mut i = self.len() - 1;
        while i > 0 && self[i-1] >= self[i] {
            i -= 1;
        }

        // If that is the entire vector, this is the last-ordered permutation.
        if i == 0 {
            return false;
        }

        // Step 2: Find the rightmost element larger than the pivot (i-1)
        let mut j = self.len() - 1;
        while j >= i && self[j] <= self[i-1]  {
            j -= 1;
        }

        // Step 3: Swap that element with the pivot
        self.swap(j, i-1);

        // Step 4: Reverse the (previously) weakly decreasing part
        self[i..].reverse();

        true
    }

    fn prev_permutation(&mut self) -> bool {
        // These cases only have 1 permutation each, so we can't do anything.
        if self.len() < 2 { return false; }

        // Step 1: Identify the longest, rightmost weakly increasing part of the vector
        let mut i = self.len() - 1;
        while i > 0 && self[i-1] <= self[i] {
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
        while j >= i && self[j-1] < self[i-1]  {
            j -= 1;
        }

        // Step 4: Swap that element with the pivot
        self.swap(i-1, j);

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
