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
    let ts: Vec<isize> = (0..n)
        .map(|_| sc.input())
        .collect();

    let m: isize = sc.input();
    let drinks: Vec<(isize, isize)> = (0..m)
        .map(|_| (sc.input(), sc.input()))
        .collect();

    let sum: isize = ts.iter().sum();

    for (p, x) in drinks {
        let index = p - 1;
        println!("{}", sum - ts[index as usize] + x);
    }
}
