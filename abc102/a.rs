use std::io::*;
use std::str::FromStr;

fn read<T: FromStr>() -> T {
    let stdin = stdin();
    let stdin = stdin.lock();
    let token: String = stdin
        .bytes()
        .map(|c| c.expect("failed to read char") as char)
        .skip_while(|c| c.is_whitespace())
        .take_while(|c| !c.is_whitespace())
        .collect();
    token.parse().ok().expect("failed to parse token")
}
fn gcd(m: usize, n:usize) -> usize {
    if n > m {
        gcd(n, m)
    } else if n == 0 {
        m
    } else {
        gcd(n, m % n)
    }
}

fn main() {
    let n: usize = read();
    println!("{}", 2 * n / gcd(2, n));
}
