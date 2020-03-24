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

    let n: i64 = sc.input();
    let arr: Vec<i64> = sc.vec(n as usize);

    let mut map = BTreeMap::new();
    for a in &arr {
        map.entry(a).and_modify(|x| *x += 1).or_insert(1);
    }

    let mut sum = 0;
    for (k, v) in &map {
        sum += if v * (v - 1) / 2 > 0 {
            v * (v - 1) / 2
        } else {
            0
        };
    }

    for a in &arr {
        let x = map.get(a).unwrap();
        let ans = sum - x * (x - 1) / 2 + if x - 1 > 1 {
            (x - 1) * (x - 2) / 2
        } else {
            0
        };
        println!("{}", ans);
    }
}
