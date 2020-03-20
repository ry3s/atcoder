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

    let n: i64 = sc.input();
    let a: Vec<i64> = (0..n)
        .map(|_| sc.input())
        .collect();
    let q: i64 = sc.input();
    let query: Vec<i64> = (0..q)
        .map(|_| sc.input())
        .collect();

    let mut flag = vec![false; 2001];
    for mask in 0..(1 << n) {
        let sum = (0..n)
            .fold(0, |s, i| {
                if mask >> i & 1 == 1 {
                    s + a[i as usize]
                } else {
                    s
                }
            }) as isize;
        if sum <= 2000 {
            flag[sum as usize] = true;
        }
    }
    for m in query {
        if flag[m as usize] {
            println!("yes");
        } else {
            println!("no");
        }
    }
}
