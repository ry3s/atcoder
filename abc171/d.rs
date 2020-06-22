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
    let q: usize = sc.input();

    let mut map = BTreeMap::<usize, usize>::new();

    for &a in &arr {
        *map.entry(a).or_insert(0) += 1;
    }

    let mut sum = map.iter().map(|(k, v)| *k * *v).sum::<usize>();

    for _ in 0..q {
        let b: usize = sc.input();
        let c: usize = sc.input();

        if let Some(cnt) = map.get(&b) {
            sum += (c - b) * cnt;
        }

        if let Some(cnt) = map.remove(&b) {
            *map.entry(c).or_insert(0) += cnt;
        }
        println!("{}", sum);

    }
}
