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

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);
    let a: i64 = sc.input();
    let b: i64 = sc.input();
    let c: i64 = sc.input();
    let x: i64 = sc.input();
    let y: i64 = sc.input();

    let mut ans = c * std::cmp::max(x * 2, y * 2);
    for z in 0..std::cmp::max(x * 2, y * 2) {
        let na = if x > z / 2 { x - z / 2 } else { 0 };
        let nb = if y > z / 2 { y - z / 2 } else { 0 };
        ans = std::cmp::min(ans, a * na + b * nb + c * z);
    }
    println!("{}", ans);
}
