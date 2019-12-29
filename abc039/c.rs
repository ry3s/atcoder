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

use std::collections::HashMap;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);
    let s: String = sc.input();

    let kenban: Vec<char> = "WBWBWWBWBWBW".chars().collect();
    let cs: Vec<char> = s.as_str().chars().collect();

    let a = vec!["Do", "Re", "Mi", "Fa", "So", "La", "Si"];
    let b = vec![0, 2, 4, 5, 7, 9, 11];
    let result = b
        .iter()
        .zip(a.iter())
        .collect::<HashMap<_, _>>();

    for i in 0..12 {
        let mut ok = true;
        for j in 0..cs.len() {
            if cs[j] != kenban[(i + j) % 12] {
                ok = false;
            }
        }

        if ok {
            println!("{}", result.get(&i).unwrap());
            break;
        }
    }
}
