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

use std::collections::BTreeMap;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    const MOD: i64 = 1000_000_000 + 7;

    let n: i64 = sc.input();
    let a: Vec<i64> = (0..n).map(|_| sc.input()).collect();

    let mut map = BTreeMap::new();

    for x in a {
        let count = map.entry(x).or_insert(0);
        *count += 1;
    }

    let mut ans = 1_i64;
    let mut index = if n % 2 == 0 { 1 } else { 0 };

    for (key, cnt) in map {
        if (key != index || cnt != 2) && !(key == 0 && cnt == 1){
            ans = 0;
            break;
        }

        index += 2;
        ans = (ans * cnt) % MOD;
    }

    println!("{}", ans);
}
