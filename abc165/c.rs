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
    let m: usize = sc.input();
    let q: usize = sc.input();

    let arr: Vec<(usize, usize, usize, usize)> = (0..q)
        .map(|_| (sc.input(), sc.input(), sc.input(), sc.input()))
        .collect();

    let mut acc = vec![];
    let mut res = vec![vec![]];
    dfs(n, m, &mut acc, &mut res);

    let mut ans = 0usize;
    for xs in res {
        let mut sum = 0usize;
        for &(a, b, c, d) in &arr {
            if xs[b - 1] - xs[a - 1] == c {
                sum += d;
            }
        }
        ans = std::cmp::max(ans, sum);
    }
    println!("{}", ans);
}


fn dfs(n: usize, m: usize, mut acc: &mut Vec<usize>, mut res: &mut Vec<Vec<usize>>) {
    if acc.len() == n {
        return res.push(acc.clone());
    }
    let &prev_last = acc.last().unwrap_or(&1);
    for v in prev_last..=m {
        acc.push(v);
        dfs(n, m, &mut acc, &mut res);
        acc.pop();
    }
}
