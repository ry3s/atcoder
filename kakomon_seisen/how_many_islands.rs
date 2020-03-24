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

    loop {
        let (w, h) = (sc.input::<i64>(), sc.input::<i64>());
        if w == 0 && h == 0 {
            break;
        }
        let arr: Vec<Vec<i64>> = sc.mat(h as usize, w as usize);
        let mut m = vec![vec![false; w as usize]; h as usize];
        let mut cnt = 0;
        for y in 0..h {
            for x in 0..w {
                if search(y, x, &arr, &mut m) {
                    cnt += 1;
                }
            }
        }
        println!("{}", cnt);
    }
}
fn search(y: i64, x: i64, arr: &Vec<Vec<i64>>, m: &mut Vec<Vec<bool>>) -> bool {
    let w = arr[0].len() as i64;
    let h = arr.len() as i64;

    if m[y as usize][x as usize] || arr[y as usize][x as usize] == 0 {
        false
    } else {
        m[y as usize][x as usize] = true;

        for &(dy, dx) in &[(-1,-1),(0,-1),(1,-1),(-1,0),(1,0),(-1,1),(0,1),(1,1)] {
            let ny = y + dy;
            let nx = x + dx;
            if ny >= 0 && ny < h && nx >= 0 && nx < w {
                search(ny, nx, arr, m);
            }
        }
        true
    }
}
