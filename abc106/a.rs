use std::io;
use std::str::FromStr;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.read_line(&mut buf).ok();
    let mut it = buf.split_whitespace().map(|n| usize::from_str(n).unwrap());
    let (a, b) = (it.next().unwrap(), it.next().unwrap());
    println!("{}", a * b - a - b + 1);
}
