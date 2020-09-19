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
fn enumerate_divisors(n: usize) -> Vec<usize> {
    let mut ret = Vec::new();
    let mut i = 1;
    while i * i <= n {
        if n % i == 0 {
            ret.push(i);
            if i * i != n {
                ret.push(n / i);
            }
        }
        i += 1;
    }
    ret
}
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();

    let mut cnt = 0usize;
    for a in 1..n + 1 {
        let b = n / a;
        cnt += b;
        if n % a == 0 {
            cnt -= 1;
        }

    }
    // for c in 1..n + 1 {
    //     let rest = n - c;
    //     let divs = enumerate_divisors(rest);
    //     cnt += divs.len();
    // }
    println!("{}", cnt);
}
