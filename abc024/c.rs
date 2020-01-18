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

    let (n, d, k): (isize, isize, isize) = (sc.input(), sc.input(), sc.input());
    let arr1: Vec<(usize, usize)> = (0..d)
        .map(|_| (sc.input(), sc.input()))
        .collect();
    let arr2: Vec<(usize, usize)> = (0..k)
        .map(|_| (sc.input(), sc.input()))
        .collect();

    for sg in &arr2 {
        let start = sg.0;
        let goal = sg.1;
        let mut now = start;
        let mut count = 0;
        for lr in &arr1 {
            let left = lr.0;
            let right = lr.1;
            if now >= left && now <= right {
                if now >= goal {
                    now = left;
                    if now <= goal {
                        println!("{}", count + 1);
                        break;
                    }
                } else {
                    now = right;
                    if now >= goal {
                        println!("{}", count + 1);
                        break;
                    }
                }
            }
            count += 1;
        }
    }
}
