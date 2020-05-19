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
    let d: i64 = sc.input();
    let a: i64 = sc.input();
    let mut arr: Vec<(i64, i64)> = (0..n).map(|_| (sc.input(), sc.input())).collect();

    arr.sort();

    let mut ans: i64 = 0;
    let mut bit = Bit::new(n + 1);

    for i in 0..n {
        let (x, mut h) = arr[i].clone();
        h -= bit.sum(i + 1);

        if h <= 0 {
            continue;
        }

        let num = (h + a - 1) / a;
        ans += num;
        let damage = num * a;
        bit.add(i, damage);
        let rx = x + d * 2;

        let mut ok = 0;
        let mut ng = n as i64;
        while (ok - ng).abs() > 1 {
            let mid = (ok + ng) / 2;
            if arr[mid as usize].0 <= rx {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        bit.add(ng as usize + 1, -damage);
    }

    println!("{}", ans);
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
