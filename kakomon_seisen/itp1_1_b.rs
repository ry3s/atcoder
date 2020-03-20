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

    loop {
        let (n, x): (i64, i64) = (sc.input(), sc.input());
        if n == 0 && x == 0 {
            return;
        }

        let mut count = 0;
        for i in 1..n + 1 {
            for j in i..n + 1 {
                for k in j..n + 1 {
                    if i != j && j != k && k != i
                        && i + j + k == x {
                            count += 1;
                        }
                }
            }
        }
        println!("{}", count);
    }
}
