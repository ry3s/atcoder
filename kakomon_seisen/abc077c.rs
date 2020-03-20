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

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: i64 = sc.input();
    let mut a: Vec<i64> = sc.vec(n as usize);
    let mut b: Vec<i64> = sc.vec(n as usize);
    let mut c: Vec<i64> = sc.vec(n as usize);

    a.sort();
    b.sort();
    c.sort();

    let mut ans: i64 = 0;
    for x in b.iter() {
        let lower = a.lower_bound(&x) as i64;
        let upper = c.upper_bound(&x) as i64;
        ans += lower * (n - upper);
    }
    println!("{}", ans);
}
