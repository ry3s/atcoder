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
    let mut pairs = vec![];
    for _ in 0..n {
        let (x, y): (i64, i64) = (sc.input(), sc.input());
        pairs.push((x, y));
    }

    let mut x_plus_y = vec![];
    let mut x_minus_y = vec![];
    for (x, y) in &pairs {
        x_plus_y.push(x + y);
        x_minus_y.push(x - y);
    }

    let x_plus_y_max = x_plus_y.iter().max().unwrap();
    let x_plus_y_min = x_plus_y.iter().min().unwrap();
    let x_minus_y_max = x_minus_y.iter().max().unwrap();
    let x_minus_y_min = x_minus_y.iter().min().unwrap();
    println!("{}", std::cmp::max(x_plus_y_max - x_plus_y_min, x_minus_y_max - x_minus_y_min));
}
