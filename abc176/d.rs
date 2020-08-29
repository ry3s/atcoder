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

use std::collections::VecDeque;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    const dy: [i64; 4] = [0, 1, 0, -1];
    const dx: [i64; 4] = [1, 0, -1, 0];
    let (h, w): (usize, usize) = (sc.input(), sc.input());
    let (ch, cw): (usize, usize) = (sc.input::<usize>() - 1, sc.input::<usize>() - 1);
    let (dh, dw): (usize, usize) = (sc.input::<usize>() - 1, sc.input::<usize>() - 1);

    let mut board = vec![];
    for _ in 0..h {
        let line = sc.input::<String>().chars().collect::<Vec<char>>();
        board.push(line);
    }

    let mut counts = vec![vec![100000000usize; w]; h];
    let mut que = VecDeque::new();
    let mut visited = VecDeque::new();
    que.push_back((ch, cw));
    counts[ch][cw] = 0;

    while !que.is_empty() || !visited.is_empty() {
        if !que.is_empty() {
            let (cury, curx) = que.pop_front().unwrap();
            visited.push_back((cury, curx));
            for i in 0..4usize {
                let (ny, nx) = (cury as i64 + dy[i], curx as i64 + dx[i]);
                if ny < 0 || ny > (h - 1) as i64 || nx < 0 || nx > (w - 1)as i64 || board[ny as usize][nx as usize] == '#' {
                    continue;
                }
                let (ny, nx) = (ny as usize, nx as usize);
                if counts[cury][curx] < counts[ny][nx] {
                    counts[ny][nx] = counts[cury][curx];
                    que.push_back((ny, nx));
                }
            }
        } else {
            let (cury, curx) = visited.pop_front().unwrap();
            for iy in -2..=2 {
                for ix in -2..=2 {
                    let (ny, nx) = (cury as i64 + iy, curx as i64 + ix);
                    if ny < 0 || ny > (h - 1) as i64 || nx < 0 || nx > (w - 1) as i64 {
                        continue;
                    }
                    if  board[ny as usize][nx as usize] == '#' {
                        continue;
                    }
                    let (ny, nx) = (ny as usize, nx as usize);
                    if counts[cury][curx] + 1 < counts[ny][nx] {
                        counts[ny][nx] = counts[cury][curx] + 1;
                        que.push_back((ny, nx));
                    }
                }
            }
        }
    }

    if counts[dh][dw] == 100000000 {
        println!("-1");
    } else {
        println!("{}", counts[dh][dw]);
    }
}
