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
    let a: usize = sc.input();
    let b: usize = sc.input();
    let c: usize = sc.input();
    let ss: Vec<String> = sc.vec(n);

    let mut ans = vec![];
    dfs(0, a as i64, b as i64, c as i64, &ss, &mut ans);

    if ans.len() == 0 {
        println!("{}", "No");
    } else {
        println!("{}", "Yes");
        ans.reverse();
        for ch in ans {
            println!("{}", ch);
        }
    }
}


fn dfs(cur: i64, a: i64, b: i64, c: i64, ss: &Vec<String>, mut ans: &mut Vec<char>) -> bool {
    let n = ss.len();
    if cur == n as i64 {
        return true;
    }

    match &*ss[cur as usize] {
        "AB" => {
            if a == 0 && b == 0 {
                false
            } else if 0 < a && dfs(cur + 1, a - 1, b + 1, c, &ss, &mut ans) {
                ans.push('B');
                true
            } else if 0 < b && dfs(cur + 1, a + 1, b - 1, c, &ss, &mut ans) {
                ans.push('A');
                true
            } else {
                false
            }
        },
        "AC" => {
            if a == 0 && c == 0 {
                false
            } else if 0 < a && dfs(cur + 1, a - 1, b, c + 1, &ss, &mut ans) {
                ans.push('C');
                true
            } else if 0 < c && dfs(cur + 1, a + 1, b, c - 1, &ss, &mut ans) {
                ans.push('A');
                true
            } else {
                false
            }
        },
        "BC" => {
            if b == 0 && c == 0 {
                false
            } else if 0 < b && dfs(cur + 1, a, b - 1, c + 1, &ss, &mut ans) {
                ans.push('C');
                true
            } else if 0 < c && dfs(cur + 1, a, b + 1, c - 1, &ss, &mut ans) {
                ans.push('B');
                true
            } else {
                false
            }
        }
        _ => unreachable!()
    }
}
