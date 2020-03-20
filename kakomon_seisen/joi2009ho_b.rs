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

fn bsearch(key: i64, arr: &Vec<i64>) -> i64 {
    let mut ok = arr.len() as i64;
    let mut ng = -1;
    while (ok - ng).abs() > 1 {
        let mid = (ok + ng) / 2;
        if arr[mid as usize] >= key {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    ok
}

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let d: i64 = sc.input();
    let n: i64 = sc.input();
    let m: i64 = sc.input();
    let mut ds: Vec<i64> = sc.vec((n - 1) as usize);
    let ks: Vec<i64> = sc.vec(m as usize);

    ds.push(0);
    ds.sort();
    let mut ans = 0;
    for i in ks {
        let j = bsearch(i, &ds);
        let d1 = ds[((j + n - 1) % n) as usize];
        let d2 = if j % n == 0 {
            d
        } else {
            ds[(j % n) as usize]
        };

        let l = if i == 0 { d } else { i };
        ans += std::cmp::min(l - d1, d2 - l);
    }
    println!("{}", ans);
}
