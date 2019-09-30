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

    let (n, h): (usize, usize)= (sc.input(), sc.input());
    let mut katana = vec![];
    for _ in 0..n {
        let (a, b): (isize, isize) = (sc.input(), sc.input());
        katana.push((a, 0)); katana.push((b, 1));
    }
    katana.sort_by(|a, b| b.cmp(a));

    let mut rest: isize = h as isize;
    let mut i = 0;
    let mut ans = 0;
    while rest > 0 {
        let cur = katana[i];
        if cur.1 == 0 {
            ans += (rest + cur.0 - 1) / cur.0;
            rest = 0;
        } else {
            ans += 1;
            rest -= cur.0;
        }
        i += 1;
    }
    println!("{}", ans);
}
