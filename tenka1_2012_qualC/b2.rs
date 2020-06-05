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

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let s: String = sc.input();
    let flash = vec![
        vec!["S10", "SJ", "SQ", "SK", "SA"],
        vec!["H10", "HJ", "HQ", "HK", "HA"],
        vec!["D10", "DJ", "DQ", "DK", "DA"],
        vec!["C10", "CJ", "CQ", "CK", "CA"],
    ];

    let case: Vec<Vec<Option<usize>>> = flash
        .iter()
        .map(|suit| suit.iter().map(|c| s.find(c)).collect())
        .collect();

    let mut min_index = -1;
    let mut min_count = 200;
    for i in 0..4 {
        let chs: Vec<usize> = case[i]
            .iter()
            .flat_map(|x| x)
            .map(|x| x.clone())
            .collect();

        if chs.len() < 5 {
            continue;
        }

        let mi: i32 = *chs.iter().max().unwrap() as i32;
        if mi < min_count {
            min_count = mi;
            min_index = i as i32;
        }
    }

    let ss = (0..5)
        .fold(s[0..min_count as usize].to_string(), |ans, i| {
            ans.replace(flash[min_index as usize][i], "")
        });

    if ss.len() > 0 {
        println!("{}", ss);
    } else {
        println!("0");
    }
}
