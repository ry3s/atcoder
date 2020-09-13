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

    let n: usize = sc.input();
    const MOD: usize = 1000_000_007;

    let all = mod_pow(10 as i64, n as i64, MOD as i64);
    let complement = mod_pow(8 as i64, n as i64, MOD as i64);
    let nonzero = mod_pow(9 as i64, n as i64, MOD as i64);
    let x = if nonzero - complement < 0 {
        nonzero - complement + MOD as i64
    } else {
        nonzero - complement
    };
    let x = x * 2 % MOD as i64;
    let rest = if all - complement < 0 {
         all - complement + MOD as i64
    } else {
         all - complement
    };

    let ans = if rest - x < 0 {
        rest - x+ MOD as i64
    } else {
        rest - x
    };
    println!("{}", ans);
}

fn mod_pow(x: i64, n: i64, modulo: i64) -> i64 {
    let mut n = n;
    let mut x = x;
    let mut ret = 1;
    while n > 0 {
        if n & 1 == 1 {
            ret = ret * x % modulo;
        }
        x = x * x % modulo;
        n >>= 1;
    }
    ret
}

struct Combination {
    fac: Vec<usize>,
    finv: Vec<usize>,
    modulo: usize,
}

impl Combination {
    fn new(max_n: usize, modulo: usize) -> Combination {
        let mut fac = vec![0; max_n];
        let mut finv = vec![0; max_n];
        let mut inv = vec![0; max_n];
        fac[0] = 1;
        fac[1] = 1;
        finv[0] = 1;
        finv[1] = 1;
        inv[1] = 1;
        for i in 2..max_n {
            fac[i] = fac[i - 1] * i % modulo;
            inv[i] = modulo - inv[modulo % i] * (modulo / i) % modulo;
            finv[i] = finv[i - 1] * inv[i] % modulo;
        }
        Combination {
            fac: fac,
            finv: finv,
            modulo: modulo,
        }
    }

    fn get(&self, n: usize, k: usize) -> usize {
        assert!(n >= k);
        self.fac[n] * (self.finv[k] * self.finv[n - k] % self.modulo) % self.modulo
    }

    #[allow(dead_code)]
    fn h(&self, n: usize, k: usize) -> usize {
        self.get(n + k - 1, k)
    }

    #[allow(dead_code)]
    fn p(&self, n: usize, k: usize) -> usize {
        assert!(n >= k);
        self.fac[n] * self.finv[n - k]
    }
}
