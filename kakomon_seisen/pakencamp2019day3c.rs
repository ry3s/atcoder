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

    let (n, m): (i64, i64) = (sc.input(), sc.input());
    let mut arr = vec![vec![0; m as usize]; n as usize];
    for i in 0..(n as usize) {
        for j in 0..(m as usize) {
            arr[i][j] = sc.input::<i64>();
        }
    }

    let mut ans = 0;
    for i in 0..m {
        for j in i + 1..m {
            let mut score = 0;
            for student in &arr {
                score += std::cmp::max(student[i as usize], student[j as usize]);
            }
            ans = std::cmp::max(ans, score);
        }
    }
    println!("{}", ans);
}
