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

    let (n, m): (usize, usize) = (sc.input(), sc.input());
    let mut a = vec![0; m];
    let mut b = vec![0; m];
    for i in 0..m {
        a[i] = sc.input();
        b[i] = sc.input();
    }
    let k: usize = sc.input();
    let mut c = vec![0; k];
    let mut d = vec![0; k];
    for i in 0..k {
        c[i] = sc.input();
        d[i] = sc.input();
    }

    let mut max_count = 0;
    for bits in 0..(1 << k) {
        let mut plates = vec![0; n];
        for i in 0..k {
            if bits >> i & 1 == 1 {
                plates[c[i] - 1] = 1;
            } else {
                plates[d[i] - 1] = 1;
            }
        }
        let mut count = 0;
        for i in 0..m {
            if plates[a[i] - 1] > 0 && plates[b[i] - 1] > 0 {
                count += 1;
            }
        }
        if count > max_count {
            max_count = count;
        }
    }
    println!("{}", max_count);
}
