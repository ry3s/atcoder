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

    let mut is_pillar = vec![vec![false; 5001]; 5001];
    for g in &arr {
        let (x, y) = *g;
        is_pillar[x as usize][y as usize] = true;
    }

    let mut ans = 0;
    for i in 0..n {
        for j in i + 1..n {
            let (x1, y1) = arr[i as usize];
            let (x2, y2) = arr[j as usize];

            let square = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            if square <= ans {
                continue;
            }

            let x3 = x2 + y2 - y1;
            let y3 = y2 + x1 - x2;
            if x3 < 0 || x3 > 5000
                || y3 < 0 || y3 > 5000 || is_pillar[x3 as usize][y3 as usize] == false{
                continue;
            }
            let x4 = x1 + y2 - y1;
            let y4 = y1 + x1 - x2;
            if x4 >= 0 && x4 <= 5000
                && y4 >= 0 && y4 <= 5000 && is_pillar[x4 as usize][y4 as usize]  {
                ans = square;
            }
        }
    }
    println!("{}", ans);
}
