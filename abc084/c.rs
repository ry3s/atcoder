use std::io::{stdin, Read, StdinLock};
use std::str::FromStr;
use std::cmp;
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

    let n: usize = sc.input();
    let mat: Vec<(isize, isize, isize)> = (0..n - 1)
        .map(|_| {
            (sc.input(), sc.input(), sc.input())
        }).collect();

    for i in 0..n {
        let mut time = 0;
        for j in i..n - 1 {
            let (c, s, f) = mat[j];

            let k = f64::max(0.0 as f64, ((time as f64 - s as f64) / f as f64).ceil());
            time = s + k as isize * f;
            time += c;
        }
        println!("{}", time);
    }
}
