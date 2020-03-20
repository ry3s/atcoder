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
}

use std::collections::HashSet;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let m: i64 = sc.input();
    let sign: Vec<(i64, i64)> = (0..m)
        .map(|_| (sc.input(), sc.input()))
        .collect();
    let n: i64 = sc.input();
    let photo: Vec<(i64, i64)> = (0..n)
        .map(|_| (sc.input(), sc.input()))
        .collect();

    let mut map = HashSet::new();
    for &(x, y) in &photo {
        map.insert((x, y));
    }

    for &(x, y) in &photo {
        let (z, w) = sign[0];
        let (x_diff, y_diff) = (x - z, y - w);
        let mut ok = true;
        for &(z, w) in &sign[1..] {
            if !map.contains(&(z + x_diff, w + y_diff)) {
               ok = false;
            }
        }
        if ok {
            println!("{} {}", x_diff, y_diff);
            return;
        }
    }
}
