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
}
#[allow(dead_code)]
type Graph = Vec<Vec<(usize, i64)>>;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let (n, m): (i64, i64) = (sc.input(), sc.input());


    let mut graph: Graph = vec![vec![]; n as usize];
    for _ in 0..m {
        let (mut l, mut r, d): (i64, i64, i64) = (sc.input() , sc.input(), sc.input());
        l -= 1; r -=1;
        graph[l as usize].push((r as usize, d));
        graph[r as usize].push((l as usize, -d));
    }
    println!("{}", if dfs(&graph) { "Yes"} else { "No" });
}

fn dfs(graph: &Graph) -> bool {
    let mut dist :Vec<Option<i64>> = vec![None; graph.len()];
    let mut stack = vec![];

    for i in 0..graph.len() {
        if dist[i] != None { continue; }

        dist[i] = Some(0);
        stack.push((i as usize, 0 as usize));
        while let Some((cur, index)) = stack.pop() {
            if index == graph[cur].len() { continue; }

            stack.push((cur, index + 1));
            let (next, d) = graph[cur][index];

            if dist[next] != None {
                if dist[cur].unwrap() as i64 + d
                    != dist[next].unwrap() as i64 { return false; }
            } else {
                dist[next] = Some(dist[cur].unwrap() as i64 + d as i64);
                stack.push((next, 0));
            }
        }
    }
    true
}
