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
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let factors = prime_factor(n);

    let mut ans: usize = 0;
    for (p, cnt) in factors {
        let mut cnt = cnt;
        let mut tmp = 0;
        let mut cur = 1;
        while cnt >= cur {
            cnt -= cur;
            cur += 1;
            tmp += 1;
        }
        ans += tmp;
    }

    println!("{}", ans);
}
