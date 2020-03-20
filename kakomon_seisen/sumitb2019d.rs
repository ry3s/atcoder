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

    let n: i64 = sc.input();
    let s: String = sc.input();
    let chs: Vec<u32> = s.chars().map(|x| x.to_digit(10).unwrap()).collect();

    let mut ans = 0;
    for i in 0..1000 {
        let first = if i < 100 { 0 } else { i / 100 };
        let second = if i < 10 { 0 } else { i % 100 / 10 };
        let third = i % 10;

        let x = match chs.iter().position(|x| x == &first) {
            Some(s) => s,
            None => continue,
        };
        let y = match chs[x + 1..].iter().position(|x| x == &second) {
            Some(s) => s,
            None => continue,
        };
        match chs[x + 1..][y + 1..].iter().position(|x| x == &third) {
            Some(s) => ans += 1,
            None => continue,
        }

    }
    println!("{}", ans);
}
