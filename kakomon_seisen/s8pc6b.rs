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
    let arr: Vec<(i64, i64)> = (0..n)
        .map(|_| (sc.input(), sc.input()))
        .collect();

    let diffs: Vec<i64> = arr.iter()
        .map(|z| z.1 - z.0)
        .collect();

    let mut ans = 1 << 60;
    for i in &arr {
        for j in &arr {
            let start = std::cmp::min(i.0, j.1);
            let end = std::cmp::max(i.0, j.1);
            let mut sum = 0;
            for (i, z) in arr.iter().enumerate() {
                let x = z.0;
                let y = z.1;
                sum += (start - x).abs() + (end - y).abs() + diffs[i as usize];
            }
            ans = std::cmp::min(ans, sum);
        }
    }
    println!("{}", ans);
}
