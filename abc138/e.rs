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

fn ctoi(ch: char) -> usize {
    (ch as u8 - b'a') as usize
}

use std::collections::BTreeMap;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let s: Vec<char> = sc.input::<String>().chars().collect();
    let t: Vec<char> = sc.input::<String>().chars().collect();

    let sn = s.len();
    let tn = t.len();

    let mut map = BTreeMap::new();
    for (i, ch) in s.iter().enumerate() {
        map.entry(ch).or_insert(vec![]).push(i as usize);
    }

    let keys = map.keys().cloned().collect::<Vec<_>>();
    for k in keys {
        let v = map.get_mut(&k).unwrap();
        for i in v.clone() {
            v.push(i + sn);
        }
    }

    let mut res = 0;
    let mut pos = 0;
    for ch in t {
        let posv = if let Some(v) = map.get(&ch) {
            v
        } else {
            println!("-1");
            return;
        };

        let i = search(posv.len(), |x| {
            let p = posv[x];
            pos < p
        });

        if let Some(i) = i {
            let p = posv[i];
            res += p - pos;
            pos = p % sn;
        }
    }

    println!("{}", res + 1);
}

fn search<F>(ok: usize, check: F) -> Option<usize>
where
    F: Fn(usize) -> bool,
{
    let mut x = ok as i64;
    let mut ok = ok as i64;
    let mut ng = -1 as i64;
    while (ok - ng).abs() > 1 {
        let mid = (ok + ng) / 2;
        if check(mid as usize) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    if ok == x {
        None
    } else {
        Some(ok as usize)
    }
}
