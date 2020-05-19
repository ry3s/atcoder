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

#[derive(Clone, Debug, PartialEq)]
struct Edge {
    to: usize,
    cost: i64,
}

impl Edge {
    fn new(to: usize, cost: i64) -> Edge {
        Edge { to, cost }
    }
}
#[derive(Clone, Debug)]
struct Graph {
    n: usize,
    adj_list: Vec<Vec<Edge>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        let adj_list = vec![vec![]; n];
        Graph { n, adj_list }
    }

    fn add_edge(&mut self, u: usize, v: Edge) {
        self.adj_list[u].push(v);
    }
}
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let m: usize = sc.input();
    let mut graph = Graph::new(n);
    for _ in 0..m {
        let a: usize = sc.input();
        let b: usize = sc.input();
        graph.add_edge(a - 1, Edge { to: b - 1, cost: 1 });
        graph.add_edge(b - 1, Edge { to: a - 1, cost: 1 });
    }

    let (dist, prev) = shortest_path(&graph, 0);
    // for d in &dist {
    //     println!("d {}", d);
    // }
    let mut ans = vec![None; n];
    for (i, &p) in prev.iter().enumerate() {
        ans[i] = p;
    }

    let mut g = Graph::new(n);
    for (i, &x) in ans.iter().enumerate() {
        if let Some(x) = x {
            g.add_edge(
                i,
                Edge {
                    to: x as usize,
                    cost: 1,
                },
            );
            g.add_edge(x as usize, Edge { to: i, cost: 1 });
        }
    }

    let (dist2, _) = shortest_path(&g, 0);
    for i in 0..n {
        if dist2[i] != dist[i] {
            println!("No");
            return;
        }
    }

    println!("Yes");
    for x in ans[1..].iter() {
        println!("{}", x.unwrap() + 1);
    }
}
fn shortest_path(graph: &Graph, start: usize) -> (Vec<i64>, Vec<Option<usize>>) {
    use std::collections::BinaryHeap;

    let n = graph.n;
    let mut dist: Vec<_> = (0..graph.n).map(|_| std::i64::MAX).collect();
    let mut prevs = vec![None; n];
    let mut heap = BinaryHeap::new();
    dist[start] = 0i64;
    heap.push(std::cmp::Reverse((0i64, start)));

    while let Some(std::cmp::Reverse((cost, cur))) = heap.pop() {
        if cost > dist[cur] {
            continue;
        }

        for next in graph.adj_list[cur].iter() {
            if cost + next.cost < dist[next.to] {
                dist[next.to] = cost + 1;
                prevs[next.to] = Some(cur);
                heap.push(std::cmp::Reverse((cost + next.cost, next.to)));
            }
        }
    }
    (dist, prevs)
}

fn get_path(to: usize, prevs: &Vec<Option<usize>>) -> Vec<usize> {
    let mut path = vec![];
    let mut cur = prevs[to].unwrap();
    while let Some(next) = prevs[cur] {
        path.push(cur);
        cur = next;
    }

    path.reverse();
    path
}
