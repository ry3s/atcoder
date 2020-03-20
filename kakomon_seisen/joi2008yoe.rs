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

    let (r, c): (i64, i64) = (sc.input(), sc.input());
    let arr: Vec<Vec<i64>> = sc.mat(r as usize, c as usize);

    let mut ans = 0;
    for mask in 0.. (1 << r) {
        let mut sum = 0;
        for j in 0..c {
            let mut d = 0;
            for i in 0..r {
                if mask >> i & 1 == 1 {
                    d += (arr[i as usize][j as usize] == 1) as i64;
                } else {
                    d += (arr[i as usize][j as usize] == 0) as i64;
                }
            }
            sum += std::cmp::max(d, r - d);
        }
        ans = std::cmp::max(ans, sum);
    }
    println!("{}", ans);
}
