use std::io::{stdin, Read, StdinLock};
use std::str::FromStr;
use std::collections::HashMap;

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

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let a: Vec<usize> = (0..n)
        .map(|_| sc.input())
        .collect();

    let mut hashmap: HashMap<usize, usize> = HashMap::new();

    for num in a {
        let count = hashmap.entry(num).or_insert(0);
        *count += 1;
    }

    let mut rem: usize = 0;
    for (key, value) in &hashmap {
        if *value >= 2 {
            rem += value - 1;
        }
    }

    println!("{}", hashmap.len() - (rem % 2));
}
