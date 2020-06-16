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
fn enumerate_divisors(n: usize) -> Vec<usize> {
    let mut ret = Vec::new();
    let mut i = 1;
    while i * i <= n {
        if n % i == 0 {
            ret.push(i);
            if i != 1 && i * i != n {
                ret.push(n / i);
            }
        }
        i += 1;
    }
    ret
}
use std::collections::BTreeSet;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let mut arr: Vec<usize> = sc.vec(n);

    arr.sort();
    let mut sames = BTreeSet::new();
    let mut xs = vec![];
    let mut prev = 0usize;
    let mut same = false;
    for (i, &a) in arr.iter().enumerate() {
        if a != prev {
            xs.push(a);
            prev = a;
        } else {
            sames.insert(a);
        }
    }

    let mut cnt: usize = 0;
    let mut set = BTreeSet::new();
    for a in xs {
        let divs = enumerate_divisors(a);
        let mut ok = true;
        for d in divs {
            if set.contains(&d) {
                ok = false;
            }
        }

        if ok {
            set.insert(a);
            cnt += 1;
        }
    }
    for s in sames {
        if set.contains(&s) {
            cnt -= 1;
        }
    }
    println!("{}", cnt);
}
