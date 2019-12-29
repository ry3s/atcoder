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


    let n: isize = sc.input();
    let a: Vec<isize> = (0..n)
        .map(|_| sc.input())
        .collect();

    let mut dp = vec![std::isize::MAX; n as usize];
    dp[0] = 0;
    dp[1] = (a[0] - a[1]).abs();
    for i in 0..((n - 2) as usize) {
        dp[i + 2] = std::cmp::min(
            dp[i + 1] + (a[i + 2] - a[i + 1]).abs(),
            dp[i] + (a[i + 2] - a[i]).abs()
        );
    }
    println!("{}", dp[n as usize - 1]);
}
