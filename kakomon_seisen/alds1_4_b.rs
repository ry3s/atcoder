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

fn bsearch(x: i64, arr: &Vec<i64>) -> bool {
    let mut ok: i64 = arr.len() as i64;
    let mut ng = -1;

    while (ok - ng).abs() > 1 {
        let mid = (ok + ng) / 2;
        if arr[mid as usize] == x {
            return true;
        } else if arr[mid as usize] > x {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    false
}
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: i64 = sc.input();
    let mut s: Vec<i64> = sc.vec(n as usize);
    let q: i64 = sc.input();
    let mut t: Vec<i64> = sc.vec(q as usize);

    s.sort();
    t.sort();

    let mut cnt = 0;
    for x in t {
        if bsearch(x, &s) {
            cnt += 1;
        }
    }
    println!("{}", cnt);
}
