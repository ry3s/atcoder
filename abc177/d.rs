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

    let (n, m): (usize, usize) = (sc.input(), sc.input());
    let mut uf = UnionFind::new(n);
    for _ in 0..m {
        let (x, y): (usize, usize) = (sc.input(), sc.input());
        let (x, y) = (x - 1, y - 1);
        uf.merge(x, y);
    }

    let mut ans = 0;
    for x in 0..n {
        ans = std::cmp::max(ans, uf.tree_size(x));
    }
    println!("{}", ans);
}

struct UnionFind {
    par: Vec<usize>,
    size: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let mut par = vec![0; n];
        let mut size = vec![0; n];
        for i in 0..n {
            par[i] = i;
            size[i] = 1;
        }
        Self { par, size }
    }

    fn is_same(&mut self, x: usize, y: usize) -> bool {
        self.find_root(x) == self.find_root(y)
    }

    fn find_root(&mut self, x: usize) -> usize {
        if x != self.par[x] {
            self.par[x] = self.find_root(self.par[x]);
        }
        self.par[x]
    }

    fn merge(&mut self, x: usize, y: usize) {
        let x = self.find_root(x);
        let y = self.find_root(y);
        if x == y {
            return;
        }

        if self.size[x] > self.size[y] {
            self.par[y] = x;
            self.size[x] += self.size[y];
        } else {
            self.par[x] = y;
            self.size[y] += self.size[x];
        }
    }

    fn tree_size(&mut self, x: usize) -> usize {
        let root = self.find_root(x);
        self.size[root]
    }
}
