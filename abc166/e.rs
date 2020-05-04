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

use std::collections::HashMap;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let arr: Vec<i64> = sc.vec(n);
    let mut map = HashMap::new();

    for i in 0..(n as i64) {
        let a = arr[i as usize];
        let diff = i - a + 1;
        map.entry(diff).and_modify(|x| *x += 1).or_insert(1);
    }
    let mut ans: i64 = 0;
    for i in 0..(n as i64) {
        let x = arr[i as usize] + i + 1;
        let diff = i - arr[i as usize]  + 1;
        if let Some(cnt) = map.get(&x) {
            ans += cnt;
        }
        map.entry(diff).and_modify(|x| *x -= 1);
    }
    println!("{}", ans);
}
