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

use std::collections::BinaryHeap;
use std::cmp::Reverse;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let m: usize = sc.input();
    let s: usize = sc.input();

    let mut grpah = Graph::new();
    for _ in 0..m {
        let (u, v, a, b): (usize, usize, usize, usize) =
            (sc.input(), sc.input(), sc.input(), sc.input());
        graph.add_edge(u - 1, Edge(v - 1, a, b));
        graph.add_edge(v - 1, Edge(u - 1, a, b));
    }

    let mut cs = Vec::new();
    let mut ds = Vec::new();
    for _ in 0..n {
        let (c, d): (usize, usize) = (sc.input(), sc.input());
        cs.push(c);
        ds.push(d);
    }

    const INF: usize = 1 << 60;
    const MAX: usize = 2500;
    let mut dp = vec![vec![INF, MAX + 1]; n];
    let mut queue = BinaryHeap::new();

    dp[0][s] = 0;
    que.push(std::cmp::Reverse((0, 0, s)));
    while let Some(std::cmp::Reverse((time, u, s))) = queue.pop() {
        let c = cs[u];
        let d = ds[u];

        if s + c <= MAX {
            let (nv, nt, ns) = (u, t + d, s + c);
            if nt < dp[nv][ns] {
                dp[nv][ns] = nt;
                queue.push(std::cmp::Reverse((nt, nv, ns)));
            }
        }

        for &(v, c, d) in graph.adj_list[u].iter() {
            if c <= s {
                let (nv, nt, ns) = (v, t + d, s - c);
                if nt < dp[nv][ns] {
                    dp[nv][ns] = nt;
                    queue.push(std::cmp::Reverse((nt, nv, ns)));
                }
            }
        }
    }

    for cs in dp.iter().skip(1) {
        let c = cs.iter().min().unwrap();
        println!("{}", c);
    }
}

struct Graph {
    n: usize,
    adj_list: Vec<Vec<Edge>>,
}
struct Edge(usize, usize, usize);


impl Graph {
    fn new(n: usize) -> Self {
        let adj_list = vec![vec![]; n];
        Graph { n, adj_list }
    }

    fn add_edge(&mut self, u: usize, v: Edge) {
        self.adj_list[u].push(v);
    }
}
