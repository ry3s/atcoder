use std::io;
use std::str::FromStr;

fn count_divisors(n : usize) -> usize {
    let mut cnt = 0;
    for i in 1..(n + 1) {
        if n % i == 0 {
            cnt += 1;
        }
    }
    cnt
}
fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.read_line(&mut buf).ok();
    let mut it = buf.split_whitespace().map(|n| usize::from_str(n).unwrap());
    let n = it.next().unwrap();
    let mut ans = 0;
    for i in 1..(n + 1) {
        if i % 2 == 1 && count_divisors(i) == 8 { ans += 1; }
    }
    println!("{}", ans);
}
