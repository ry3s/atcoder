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
#[derive(Clone, Debug)]
struct Graph {
    n: usize,
    adj_list: Vec<Vec<usize>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        let adj_list = vec![vec![]; n];
        Graph { n, adj_list }
    }

    fn add_edge(&mut self, u: usize, v: usize) {
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
        graph.add_edge(a - 1, b - 1);
        graph.add_edge(b - 1, a - 1);
    }

    use std::collections::BinaryHeap;
    let mut dist: Vec<_> = (0..graph.n).map(|_| std::i64::MAX).collect();
    let mut prev = vec![-1i64; n];
    let mut heap = BinaryHeap::new();
    dist[0] = 0i64;
    heap.push(std::cmp::Reverse((0i64, 0)));

    while let Some(std::cmp::Reverse((cost, cur))) = heap.pop() {
        if cost > dist[cur] {
            continue;
        }

        for &next in graph.adj_list[cur].iter() {
            if cost + 1 < dist[next] {
                dist[next] = cost + 1;
                prev[next] = cur as i64;
                heap.push(std::cmp::Reverse((cost + 1, next)));
            }
        }
    }
    // for d in &dist {
    //     println!("d {}", d);
    // }
    let mut ans = vec![0; n];
    for (i, &p) in prev.iter().enumerate() {
        if p != -1 {
            ans[i] = p;
        }
    }

    let mut g = Graph::new(n);
    for (i, &x) in ans.iter().enumerate() {
        if x != -1 {
            g.add_edge(i, x as usize);
            g.add_edge(x as usize, i);
        }
    }

    let dist2 = shortest_path(&g, 0);
    for i in 0..n {
        if dist2[i] != dist[i] {
            println!("No");
            return;
        }
    }

    println!("Yes");
    for x in ans[1..].iter() {
        println!("{}", x + 1);
    }
}
fn shortest_path(graph: &Graph, start: usize) -> Vec<i64> {
    use std::collections::BinaryHeap;
    let mut dist: Vec<_> = (0..graph.n).map(|_| std::i64::MAX).collect();

    let mut heap = BinaryHeap::new();
    dist[start] = 0i64;
    heap.push(std::cmp::Reverse((0i64, start)));

    while let Some(std::cmp::Reverse((cost, cur))) = heap.pop() {
        if cost > dist[cur] {
            continue;
        }

        for &next in graph.adj_list[cur].iter() {
            if cost + 1 < dist[next] {
                heap.push(std::cmp::Reverse((cost + 1, next)));
                dist[next] = cost + 1;
            }
        }
    }
    dist
}
