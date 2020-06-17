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

    let n: usize = sc.input();
    let mut a = vec![];
    let mut b = vec![];
    for _ in 0..n {
        let ai: usize = sc.input();
        let bi: usize = sc.input();
        a.push(ai);
        b.push(bi);
    }

    a.sort();
    b.sort();
    if n % 2 == 0 {
        let mi = a[n / 2 - 1] + a[n / 2];
        let ma = b[n / 2 - 1] + b[n / 2];
        println!("{}", ma - mi + 1);
    } else {
        let mi = a[n / 2];
        let ma = b[n / 2];
        println!("{}", ma - mi + 1);
    }
}
