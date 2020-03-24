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

struct Graph {
    n: usize,
    adj_list: Vec<Vec<usize>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        let adj_list = vec![vec![]; n];
        Graph { n: n, adj_list: adj_list }
    }

    fn add_edge(&mut self, u: usize, v: usize) {
        self.adj_list[u].push(v);
    }
}
fn dfs(
    g: &Graph,
    d: &mut Vec<usize>,
    f: &mut Vec<usize>,
    t: &mut usize,
    i: usize
) {
    *t += 1;
    d[i] = *t;
    for &next_i in g.adj_list[i].iter() {
        if d[next_i] == 0 {
            dfs(g, d, f, t, next_i);
        }
    }
    *t += 1;
    f[i] = *t;
}
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: i64 = sc.input();
    let mut graph = Graph::new(n as usize);
    for _ in 0..n {
        let (u, k): (i64, i64) = (sc.input(), sc.input());
        for _ in 0..k {
            let v: i64 = sc.input();
            graph.add_edge((u - 1) as usize, (v - 1) as usize);
        }
    }

    let mut d = vec![0; graph.n];
    let mut f = vec![0; graph.n];
    let mut t = 0;

    for i in 0..(graph.n) {
        if d[i] == 0 {
            dfs(&graph, &mut d, &mut f, &mut t, i);
        }
    }

    for i in 0..graph.n {
        println!("{} {} {}", i + 1, d[i], f[i]);
    }
}
