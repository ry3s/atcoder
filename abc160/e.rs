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

    let x: i64 = sc.input();
    let y: i64 = sc.input();
    let a: i64 = sc.input();
    let b: i64 = sc.input();
    let c: i64 = sc.input();
    let mut ps: Vec<i64> = sc.vec(a as usize);
    let mut qs: Vec<i64> = sc.vec(b as usize);
    let rs: Vec<i64> = sc.vec(c as usize);

    ps.sort_by_key(|&x| -x);
    qs.sort_by_key(|&x| -x);
    let mut v = [&ps[0..x as usize], &qs[0..y as usize], &rs].concat();
    v.sort_by_key(|&x| -x);

    let ans: i64 = v[..(x + y) as usize].iter().sum();
    println!("{}", ans);
}
