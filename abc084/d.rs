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

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let q: isize = sc.input();

    let max_n: isize = 1e5 as isize;
    let is_prime = get_primes(max_n);
    let mut cnt = vec![0; max_n as usize + 1];

    let mut i = 3;
    while i <= max_n as usize {
        if is_prime[i] && is_prime[(i + 1) / 2] { cnt[i] += 1; }
        i +=2;
    }
    for i in 0..max_n as usize {
        cnt[i + 1] += cnt[i];
    }
    for _ in 0..q {
        let (l, r): (usize, usize) = (sc.input(), sc.input());
        println!("{}", cnt[r] - cnt[l - 1]);
    }
}

fn get_primes(n: isize) -> Vec<bool> {
    let mut is_prime = vec![true; n as usize + 1];

    let mut i = 2;
    while i * i <= n {
        if is_prime[i as usize] {
            let mut j = i * i;
            while j <= n {
                is_prime[j as usize] = false;
                j += i;
            }
        }
        i += 1;
    }
    is_prime
}
