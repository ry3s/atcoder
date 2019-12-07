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

    let (w, h, n): (i64, i64, i64) = (sc.input(), sc.input(), sc.input());
    let points: Vec<(i64, i64, i64)> = (0..n)
        .map(|_| (sc.input(), sc.input(), sc.input()) )
        .collect();

    let mut rectangle = vec![vec![0; w as usize]; h as usize];

    for (x, y, a)  in points {
        let x = x - 1;
        let y = y - 1;

        if a == 1 {
            for ix in 0..x + 1 {
                for y in 0..h {
                    rectangle[y as usize][ix as usize] = 1;
                }
            }
        } else if a == 2 {
            for ix in x + 1..w {
                for y in 0..h {
                    rectangle[y as usize][ix as usize] = 1;
                }
            }
        } else if a == 3 {
            for iy in 0..y + 1 {
                for x in 0..w {
                    rectangle[iy as usize][x as usize] = 1;
                }
            }
        } else if a == 4 {
            for iy in y + 1..h {
                for x in 0..w {
                    rectangle[iy as usize][x as usize] = 1;
                }
            }
        }

    }

    let mut ans = 0;
    for i in 0..h as usize {
        for j in 0..w as usize {
            if rectangle[i][j] == 0 {
                ans += 1;
            }
        }
    }
    println!("{}", ans);
}
