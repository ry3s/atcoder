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
    let (n, m): (i64, i64) = (sc.input(), sc.input());
    let mut arr = vec![vec![false; n as usize]; n as usize];
    for i in 0..m {
        let (mut x, mut y): (usize, usize) = (sc.input(), sc.input());
        x -= 1;
        y -= 1;
        arr[x][y] = true;
        arr[y][x] = true;
    }

    let mut ans = 0;
    for mask in 0..(1 << n) {
        let cnt = (mask as u32).count_ones();
        if cnt <= ans {
            continue;
        }

        let mut ok = true;
        for i in 0..n {
            for j in 0..i {
                if mask >> i & mask >> j & 1 == 1
                    && arr[i as usize][j as usize] != true {
                    ok = false;
                }
            }
        }
        if ok {
            ans = cnt;
        }
    }
    println!("{}", ans);
}
