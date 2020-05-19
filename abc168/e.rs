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
fn gcd(m: i64, n: i64) -> i64 {
    if m < n {
        gcd(n, m)
    } else {
        if n == 0 {
            m
        } else {
            gcd(n, m % n)
        }
    }
}

fn mod_pow(x: i64, n: i64, modulo: i64) -> i64 {
    let mut n = n;
    let mut x = x;
    let mut res = 1;
    while n > 0 {
        if n & 1 == 1 {
            res = res * x % modulo;
        }
        x = x * x % modulo;
        n >>= 1;
    }
    res
}
#[derive(Clone, Copy)]
struct ModInt(usize);
const MOD: usize = 1_000_000_007;

#[allow(dead_code)]
impl ModInt {
    fn new(n: usize) -> ModInt {
        ModInt(n % MOD)
    }

    fn zero() -> ModInt {
        ModInt(0)
    }

    fn one() -> ModInt {
        ModInt(1)
    }

    fn pow(self, mut n: usize) -> ModInt {
        let mut ret = ModInt::one();
        let mut x = self;
        while n > 0 {
            if n & 1 == 1 {
                ret *= x;
            }
            x *= x;
            n >>= 1;
        }
        ret
    }

    fn inv(self) -> ModInt {
        assert!(self.0 > 0);
        self.pow(MOD - 2)
    }
}

impl std::ops::Add for ModInt {
    type Output = ModInt;
    fn add(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::AddAssign for ModInt {
    fn add_assign(&mut self, rhs: ModInt) {
        *self = *self + rhs;
    }
}

impl std::ops::Sub for ModInt {
    type Output = ModInt;
    fn sub(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + MOD - rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::SubAssign for ModInt {
    fn sub_assign(&mut self, rhs: ModInt) {
        *self = *self - rhs;
    }
}

impl std::ops::Mul for ModInt {
    type Output = ModInt;
    fn mul(self, rhs: ModInt) -> Self::Output {
        ModInt((self.0 * rhs.0 % MOD))
    }
}

impl std::ops::MulAssign for ModInt {
    fn mul_assign(&mut self, rhs: ModInt) {
        *self = *self * rhs;
    }
}

impl std::ops::Neg for ModInt {
    type Output = ModInt;
    fn neg(self) -> Self::Output {
        ModInt(if self.0 == 0 { 0 } else { MOD - self.0 })
    }
}

impl std::fmt::Display for ModInt {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

impl std::str::FromStr for ModInt {
    type Err = std::num::ParseIntError;
    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let val = s.parse::<usize>()?;
        Ok(ModInt::new(val))
    }
}

use std::collections::BTreeMap;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let mut arr: Vec<(i64, i64)> = (0..n).map(|_| (sc.input(), sc.input())).collect();

    let mut map = BTreeMap::new();

    for p in arr.iter_mut() {
        if p.0 == 0 || p.1 == 0 {
            if p.0 != 0 {
                p.0 = 1;
            }
            if p.1 != 0 {
                p.1 = 1;
            }
        } else {
            let g = gcd(p.0.abs(), p.1.abs());
            if p.0 < 0 {
                p.0 = -p.0;
                p.1 = -p.1;
            }
            p.0 /= g;
            p.1 /= g;
        }
        *map.entry((p.0, p.1)).or_insert(0) += 1;
    }

    let mut ans = ModInt::one();
    let zero = map.remove(&(0, 0)).map_or(ModInt::zero(), |c| ModInt(c));
    while let Some((&key, &c)) = map.iter().next() {
        map.remove(&key);
        let p = if key.1 < 0 {
            (-key.1, key.0)
        } else {
            (key.1, -key.0)
        };

        if let Some(d) = map.remove(&p) {
            ans *= ModInt(2).pow(c) + ModInt(2).pow(d) - ModInt::one();
        } else {
            ans *= ModInt(2).pow(c);
        }
    }

    ans += zero - ModInt::one();
    println!("{}", ans);
}
