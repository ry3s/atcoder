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

use std::collections::BTreeSet;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let s: String = sc.input();
    let chs: Vec<char> = s.chars().collect();
    let n: usize = chs.len();

    let mut cards = vec![];
    let mut i = 0;
    while i + 1 < n {
        if chs[i + 1] == '1' {
            cards.push(chs[i].to_string() + "10");
            i += 3;
        } else {
            cards.push(chs[i].to_string() + &chs[i + 1].to_string());
            i += 2;
        }
    }
    let mut arr = vec![];
    arr.push(check('S', &cards));
    arr.push(check('H', &cards));
    arr.push(check('D', &cards));
    arr.push(check('C', &cards));


    let mut ans = vec![];
    for (ok, _cnt, bin) in arr {
        if !ok {
            continue;
        }

        if ans.len() == 0 || ans.len() > bin.len() {
            ans = bin.clone();
        }
    }

    if ans.is_empty() {
        println!("0");
    } else {
        for ch in ans {
            print!("{}", ch);
        }
        println!();
    }

}

fn check(mark: char, cards: &Vec<String>) -> (bool, usize, Vec<String>) {
    let mut flash = BTreeSet::new();
    for s in ["10", "J", "Q", "K", "A"].iter() {
        flash.insert(mark.to_string() + s);
    }

    let mut ok = false;
    let mut set = BTreeSet::new();
    let mut bin = vec![];
    let mut cnt = 0;
    for card in cards.iter() {
        if set == flash {
            ok = true;
            break;
        }
        if flash.contains(card) {
            if set.contains(card) {
                bin.push(card.to_string());
            } else {
                set.insert(card.to_string());
            }
        } else {
            bin.push(card.to_string());
        }
        cnt += 1;
    }

    (ok, cnt, bin)
}
