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

    fn vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
        (0..len).map(|_| self.input()).collect()
    }

    fn mat<T: FromStr>(&mut self, row: usize, col: usize) -> Vec<Vec<T>> {
        (0..row).map(|_| self.vec(col)).collect()
    }
}

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let s: String = sc.input();
    let chs: Vec<char> = s.chars().collect();

    let (red, green, blue): (usize, usize, usize) = chs
        .iter()
        .fold((0, 0, 0), |(r, g, b), &ch| {
            match ch {
                'R' => (r + 1, g, b),
                'G' => (r, g + 1, b),
                'B' => (r, g, b + 1),
                _ => unreachable!(),
            }
        });

    let sum: usize = red * green * blue;
    let mut sub: usize = 0;
    for i in 0..n - 2 {
        for j in i + 1..n - 1{
            if chs[i] == chs[j] {
                continue;
            }

            let k = j * 2 - i;
            if k >= n || chs[k] == chs[i] || chs[k] == chs[j] {
                continue;
            }
            sub += 1;
        }
    }
    println!("{}", sum - sub);
}
