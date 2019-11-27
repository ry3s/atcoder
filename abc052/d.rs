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
    let xs: Vec<isize> = (0..n)
        .map(|_| sc.input())
        .collect();

    let mut acc = 0;
    for iter in xs.windows(2) {
        let next = iter[1];
        let cur = iter[0];
        let dist = next - cur;

        acc += if dist * a < b {
            dist * a
        } else {
            b
        };
    }

    println!("{}", acc);
}
