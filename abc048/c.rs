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


    let (n, x): (i64, i64) = (sc.input(), sc.input());
    let mut a: Vec<i64> = (0..n)
        .map(|_| sc.input())
        .collect();


    let mut index = 0;
    let mut ans = 0;
    while index + 1 < a.len() {
        let cur = a[index];
        let next = a[index + 1];

        if cur + next > x {
            let diff = cur + next - x;
            if diff <= next {
                a[index + 1] = next - diff;
            } else {
                a[index] -= diff - next;
                a[index + 1] = 0;
            }
            ans += diff;

        }

        index += 1;
    }
    println!("{}", ans);
}
