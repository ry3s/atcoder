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

    let (n, k): (i64, i64) = (sc.input(), sc.input());
    let arr: Vec<i64> = sc.vec(n as usize);

    let mut ans = (1i64 << 61);
    for mask in 0..(1 << n) {
        if ((mask as u64).count_ones() as i64) < k {
            continue;
        }

        let mut sum = 0;
        let mut prev_max = 0;
        let mut cnt = 0;
        for i in 0..n {
            if mask >> i & 1 == 1 {
                if prev_max >= arr[i as usize]  {
                    sum += prev_max - arr[i as usize] + 1;
                    prev_max += 1;
                } else {
                    prev_max = arr[i as usize];
                }
                cnt += 1
            } else {
                if prev_max < arr[i as usize] {
                    prev_max = arr[i as usize];
                    cnt += 1;
                }
            }
        }
        if cnt >= k {
            ans = std::cmp::min(ans, sum);
        }
    }
    println!("{}", ans);
}
