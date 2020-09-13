use std::io::{stdin, Read, StdinLock};
use std::str::FromStr;

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

    fn vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
        (0..len).map(|_| self.input()).collect()
    }

    fn mat<T: FromStr>(&mut self, row: usize, col: usize) -> Vec<Vec<T>> {
        (0..row).map(|_| self.vec(col)).collect()
    }
}

use std::collections::BTreeMap;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let arr: Vec<usize> = sc.vec(n);

    let mut cnt = vec![0; 2000_000];
    let mut g = arr[0];
    for a in arr {
        g = gcd(g, a);
        cnt[a] += 1;
    }

    let mut i = 2;
    while i <= 1000_000 {
        let mut j = i;
        let mut x = 0;
        while j <= 1000_000 {
            x += cnt[j];
            j += i;
        }
        if x >= 2 {
            break;
        }
        i += 1
    }

    if i == 1000_001 {
        println!("pairwise coprime");
    } else if g == 1 {
        println!("setwise coprime");
    } else {
        println!("not coprime");
    }
}

fn prime_factor(n: usize) -> BTreeMap<usize, usize> {
    let mut ret = BTreeMap::new();
    let mut n = n;
    let mut i: usize = 2;
    while i * i <= n {
        while n % i == 0 {
            *ret.entry(i).or_insert(0) += 1;
            n /= i;
        }
        i += 1;
    }

    if n != 1 {
        *ret.entry(n).or_insert(0) += 1;
    }
    ret
}

fn gcd(m: usize, n: usize) -> usize {
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
