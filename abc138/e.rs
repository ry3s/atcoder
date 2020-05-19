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
        let token = self
            .cin
            .by_ref()
            .bytes()
            .map(|c| c.unwrap() as char)
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

fn ctoi(ch: char) -> usize {
    (ch as u8 - b'a') as usize
}

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let s: Vec<char> = sc.input::<String>().chars().collect();
    let t: Vec<char> = sc.input::<String>().chars().collect();

    let sn = s.len();
    let tn = t.len();

    let mut nexts = vec![vec![None; 26]; sn];
    let mut lasts = vec![None; 26];

    for (i, &c) in s.iter().rev().enumerate() {
        lasts[ctoi(c)] = Some(i);
    }

    for (i, &c) in s.iter().rev().enumerate() {
        lasts[ctoi(c)] = Some(i);

        for ci in 0..26 {
            nexts[i][ci] = match lasts[ci] {
                None => None,
                Some(ni) => Some((ni, if ni < i { 1_usize } else { 0 })),
            }
        }
    }

    let mut si = 0;
    let mut wrap = 0;
    let mut ok = true;

    for ch in t {
        match nexts[si][ctoi(ch)] {
            Some((ni, w)) => {
                si = ni;
                wrap += w;

                si += 1;
                if si == sn {
                    si = 0;
                    wrap += 1;
                }
            }
            None => {
                ok = false;
                break;
            }
        }
    }

    if ok {
        println!("{}", wrap * sn + si);
    } else {
        println!("-1");
    }
    // let mut sets = vec![BTreeSet::new(); 26];
    // for (i, ch) in s.iter().enumerate() {
    //     sets[(*ch as u8 - 'a' as u8) as usize].insert(i + 1);
    // }

    // let mut cur = 1;
    // for ch in t {
    //     let set = &sets[(ch as u8 - 'a' as u8) as usize];

    //     if set.is_empty() {
    //         println!("-1");
    //         return;
    //     }

    //     let mut ok = false;
    //     for &i in set {
    //         if i > cur % ns {
    //             cur += i - cur % ns;
    //             ok = true;
    //             break;
    //         }
    //     }

    //     if !ok {
    //         cur += set.iter().next().unwrap() + ns - cur % ns;
    //     }
    // }
    // println!("{}", cur);
}
