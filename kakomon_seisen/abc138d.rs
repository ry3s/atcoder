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
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let (n, q): (i64, i64) = (sc.input(), sc.input());

    let mut graph = Graph::new(n as usize);
    for _ in 0..n - 1 {
        let (a, b): (i64, i64) = (sc.input(), sc.input());
        graph.add_edge((a - 1) as usize, (b - 1) as usize);
    }

    let mut counter = vec![0; n as usize];
    for _ in 0..q {
        let (p, x): (i64, i64) = (sc.input(), sc.input());
        counter[(p - 1) as usize] += x;
    }
    let mut ans = vec![0; n as usize];

    dfs(0, -1, counter[0], &mut ans, &graph, &counter);
    for i in ans {
        print!("{} ", i);
    }
    println!();
}

fn dfs(cur: i64, par: i64, x: i64,
       ans: &mut Vec<i64>, g: &Graph, counter: &Vec<i64>) {
    ans[cur as usize] += x;
    for &next in g.adj_list[cur as usize].iter() {
        if next != (par as usize) {
            dfs(next as i64, cur, x + counter[next as usize], ans, g, counter);
        }
    }
}
