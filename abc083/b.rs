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

    let (n, a, b): (isize, isize, isize) = (sc.input(), sc.input(), sc.input());

    let mut ans = 0;
    for i in 1..n + 1 {
        let sum = digit_sum(i);
        if sum >= a && sum <= b { ans += i; }
    }
    println!("{}", ans);
}

fn digit_sum(n: isize) -> isize {
    let mut res = 0;

    let mut x = n;
    while x > 0 {
        res += x % 10;
        x /= 10;
    }
    res
}
