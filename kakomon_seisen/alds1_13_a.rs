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

fn put(map: &Vec<Vec<bool>>, r: usize, c: usize) -> Vec<Vec<bool>> {
    let mut cln = map.clone();

    for i in 0..8 {
        cln[i][c] = true;
    }
    for j in 0..8 {
        cln[r][j] = true;
        if j <= r + c && r + c < j + 8 {
            cln[r + c - j][j] = true;
        }
        if c <= r + j && r + j < c + 8 {
            cln[r + j - c][j] = true;
        }
    }
    cln
}

fn solve(map: &Vec<Vec<bool>>, v: &mut Vec<(i64, i64)>, cnt: i64) -> bool {
    if cnt == 8 {
        return true;
    }
    for i in 0..8 {
        for j in 0..8 {
            if !map[i][j] {
                let cln = put(&map, i, j);
                let res = solve(&cln, v, cnt + 1);
                if res {
                    v.push((i as i64, j as i64));
                    return true;
                }
            }
        }
    }
    false
}
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let k: i64 = sc.input();
    let mut arr: Vec<(i64, i64)> = (0..k)
        .map(|_| (sc.input(), sc.input()))
        .collect();

    let mut map = vec![vec![false; 8]; 8];
    for rc in &arr {
        map = put(&map, rc.0 as usize, rc.1 as usize);
    }

    solve(&map, &mut arr, k);

    let mut ans = vec![vec!['.'; 8]; 8];
    for p in arr {
        ans[p.0 as usize][p.1 as usize] = 'Q';
    }
    for a in ans {
        for b in a {
            print!("{}", b);
        }
        println!("");
    }
}
