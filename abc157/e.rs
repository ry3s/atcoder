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
        let token = self
            .cin
            .by_ref()
            .bytes()
            .map(|c| c.unwrap() as char)
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

use std::collections::BTreeSet;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let mut chs: Vec<char> = sc.input::<String>().chars().collect();
    let q: usize = sc.input();

    let mut vset: Vec<BTreeSet<usize>> = vec![BTreeSet::new(); 26];
    for (i, &ch) in chs.iter().enumerate() {
        vset[(ch as u8 - 'a' as u8) as usize].insert(i);
    }

    for _ in 0..q {
        let t: usize = sc.input();
        if t == 1 {
            let (i, next_ch): (usize, char) = (sc.input(), sc.input());
            let i = i - 1;
            let prev_ch = chs[i];

            chs[i] = next_ch;
            vset[(prev_ch as u8 - 'a' as u8) as usize].remove(&i);
            vset[(next_ch as u8 - 'a' as u8) as usize].insert(i);
        } else {
            // t == 2
            let (left, right): (usize, usize) = (sc.input(), sc.input());
            let mut cnt = 0usize;

            for ch in 0..26 {
                if vset[ch].is_empty() {
                    continue;
                }

                if vset[ch].range(left - 1..=right - 1).next().is_some() {
                    cnt += 1;
                }
            }
            println!("{}", cnt);
        }
    }
}
