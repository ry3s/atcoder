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
    let m: i64 = sc.input();
    let mut arr = vec![Vec::<i64>::new(); m as usize];
    for i in 0..m {
        let k: i64 = sc.input();
        for _ in 0..k {
            arr[i as usize].push(sc.input());
        }
    }
    let ps: Vec<i64> = sc.vec(m as usize);

    let mut ans = 0;
    for mask in 0..(1 << n) {
        let mut ok = true;
        for i in 0..m {
            let mut cnt = 0;
            for sw in &arr[i as usize] {
                if mask >> (sw - 1) & 1 == 1 {
                    cnt += 1;
                }
            }
            if cnt % 2 != ps[i as usize] {
                ok = false;
            }
        }
        if ok {
            ans += 1;
        }
    }
    println!("{}", ans);
}
