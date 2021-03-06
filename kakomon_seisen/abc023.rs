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

    let n: i64 = sc.input();
    let arr: Vec<(i64, i64)> = (0..n)
        .map(|_| (sc.input(), sc.input()))
        .collect();

    // x[m] 以下にできるか？
    let check = |x| {
        let mut ts = vec![0; n as usize];
        for y in arr.iter().enumerate() {
            let (i, &(h, s)) = y;
            if x - h < 0 { return false; }

            ts[i] = std::cmp::min(111110i64, (x - h) / s);
        }
        ts.sort();
        for (i, t) in ts.iter().enumerate() {
            if t < &(i as i64) { return false; }
        }
        true
    };

    let mut ok = 10000000000 * 1000000;
    let mut ng = -1i64;
    while (ok - ng).abs() > 1 {
        let mid = (ok + ng) / 2;
        if check(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    println!("{}", ok);
}
