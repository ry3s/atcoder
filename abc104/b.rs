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

fn main() {
    let s : String = read();
    let s = s.chars().collect::<Vec<_>>();


    if s[0] != 'A' {
        println!("WA");
        return;
    }
    let mut cnt = 0;
    let mut ok = true;
    for i in 1..s.len() {
        if s[i] == 'C' && i >= 2 && i <= s.len() - 2 {
            cnt += 1;
        } else if !s[i].is_lowercase() {
            ok = false;
        }
    }
    println!("{}", if ok && cnt == 1 {
        "AC"
    } else {
        "WA"
    });
}
