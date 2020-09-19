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

const MOD: usize = 998244353;
fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);

    let n: usize = sc.input();
    let k: usize = sc.input();
    let mut sections = vec![];
    for _ in 0..k {
        let l: usize = sc.input();
        let r: usize = sc.input();
        sections.push((l, r));
    }

    let mut dp = vec![ModInt::zero(); n * 2+ 1];
    let mut acc = vec![ModInt::zero(); n * 2 + 2];
    dp[n - 1] = ModInt::one();
    acc[n - 1] = ModInt::one();

    for i in (0..n - 1).rev() {
        let mut cur = ModInt::zero();
        for (l, r) in &sections {
            let l = i + *l;
            let r = i + *r + 1;
            cur += acc[l] - acc[r];
        }
        dp[i] = cur;
        acc[i] = cur + acc[i + 1];
    }
    let x: ModInt = 1.into();
    println!("{}", dp[0]);
}

#[derive(Clone, Copy, Debug)]
struct ModInt(usize);
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

    fn as_usize(&self) -> usize {
        self.0
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
        ModInt(self.0 * rhs.0 % MOD)
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

impl From<usize> for ModInt {
    fn from(n: usize) -> Self {
        Self::new(n)
    }
}
