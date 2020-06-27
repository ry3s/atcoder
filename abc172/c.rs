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

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let m: usize = sc.input();
    let k: usize = sc.input();
    let ax: Vec<usize> = sc.vec(n);
    let bx: Vec<usize> = sc.vec(m);

    let mut aacc = vec![0; n + 1];
    let mut bacc = vec![0; m + 1];

    for i in 0..n {
        aacc[i + 1] = ax[i] + aacc[i];
    }
    for i in 0..m {
        bacc[i + 1] = bx[i] + bacc[i];
    }

    let mut cnt = 0usize;
    for i in 0..=n {
        let time = aacc[i];
        if time <= k {
            let rest = k - time;
            let idx = bacc.upper_bound(&rest);
            let idx = if idx == 0 { 0 } else { idx - 1 };
            cnt = std::cmp::max(cnt, i + idx);
        }
    }
    println!("{}", cnt);
}

trait BinarySearch<T> {
    fn lower_bound(&self, key: &T) -> usize;
    fn upper_bound(&self, key: &T) -> usize;
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
