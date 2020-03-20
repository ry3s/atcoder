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

fn ok(chs: Vec<char>) -> bool {
    for ch in chs {
        match ch {
            'A' | 'C' |'G' | 'T' => {continue},
            _  =>{return false}
        }
    }
    true
}
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let s: String = sc.input();
    let chs: Vec<char> = s.chars().collect();

    let mut ans = 0;
    for i in 0..chs.len() {
        for j in i..chs.len() + 1 {
            if ok(chs[i..j].to_vec()) {
                ans = std::cmp::max(ans, j - i);
            }
        }
    }
    println!("{}", ans);
}
