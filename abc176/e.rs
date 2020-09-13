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

    let (h, w, m): (usize, usize, usize) = (sc.input(), sc.input(), sc.input());

    let mut bombs = vec![];
    let mut h_cnt = vec![0usize; h];
    let mut w_cnt = vec![0usize; w];
    for _ in 0..m {
        let (h, w): (usize, usize) = (sc.input(), sc.input());
        bombs.push((h - 1, w - 1));
        h_cnt[h - 1] += 1;
        w_cnt[w - 1] += 1;
    }

    let h_max = h_cnt.iter().max().unwrap();
    let mut h_indices = vec![];
    for i in 0..h {
        if h_cnt[i] == *h_max {
            h_indices.push(i);
        }
    }

    let w_max = w_cnt.iter().max().unwrap();
    let mut w_indices = vec![];
    for i in 0..w {
        if w_cnt[i] == *w_max {
            w_indices.push(i);
        }
    }

    let point = h_indices.len() * w_indices.len();
    let mut point_cnt = 0;
    for &(y, x) in &bombs {
        if h_cnt[y] == *h_max && w_cnt[x] == *w_max {
            point_cnt += 1;
        }
    }
    let a = if point == point_cnt { 1 } else { 0 };
    println!("{}", h_max + w_max - a);
}
