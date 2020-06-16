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

    let (n, q): (usize, usize) = (sc.input(), sc.input());
    let infants: Vec<(usize, usize)> = (0..n)
        .map(|_| (sc.input(), sc.input()))
        .collect();

    let mut whr = vec![0; n];
    for (j, (rate, i)) in infants.iter().enumerate() {
        whr[j] = i - 1;
    }
    let mut rates = vec![MultiSet::new(); 200_000];
    for (rate, i) in &infants {
        rates[i - 1].insert(rate.clone());
    }

    let mut segtree = SegmentTree::init(vec![std::usize::MAX; 200_000]);

    for (i, rate) in rates.iter().enumerate() {
        if let Some(maxi) = rate.iter().next_back() {
            segtree.update(i, *maxi);
        }
    }


    // println!("{:?}, {:?}, {:?}", rates[0], rates[2], rates[3]);
    println!();
    for _ in 0..q {
        let c: usize = sc.input();
        let nxt: usize = sc.input();
        let prv = whr[c - 1];
        let rate = infants[c - 1].0.clone();
        rates[prv].remove(&rate);
        rates[nxt].insert(rate);
        if let Some(maxi) = rates[prv].iter().next_back() {
            println!("{}", maxi);
            segtree.update(prv, *maxi);
        } else {
            segtree.update(prv, std::usize::MAX);
        }
        if let Some(maxi) = rates[nxt].iter().next_back() {
            println!("{}", maxi);
            segtree.update(nxt, *maxi);
        } else {
            segtree.update(nxt, std::usize::MAX);
        }

        // println!("{:?}, {:?}, {:?}", rates[0], rates[2], rates[3]);
        whr[c - 1] = nxt;
        let ans = segtree.fold(0, 200_000);
        // println!("{}", ans);
    }
}

impl Magma for usize {
    fn op(&self, rhs: &Self) -> Self {
        *self.min(rhs)
    }
}

impl Associative for usize {}

impl Unital for usize {
    fn identity() -> Self {
        std::usize::MAX
    }
}

pub trait Magma: Sized + Clone {
  fn op(&self, rhs: &Self) -> Self;
}

pub trait Associative: Magma {}

pub trait Unital: Magma {
  fn identity() -> Self;
}

pub trait Monoid: Magma + Associative + Unital {}

impl<T: Magma + Associative + Unital> Monoid for T {}

pub struct SegmentTree<T: Monoid> {
    node: Vec<T>,
    sz: usize,
}

impl<T: Monoid> SegmentTree<T> {
    pub fn init(vec: Vec<T>) -> Self {
        let mut sz = 1;
        while sz < vec.len() { sz *= 2; }
        let mut node = vec![T::identity(); sz << 1];
        for i in 0..vec.len() { node[i + sz] = vec[i].clone(); }
        for i in (1..sz).rev() { node[i] = node[i << 1].op(&node[(i << 1) + 1]); }
        SegmentTree { node: node, sz: sz }
    }

    pub fn update(&mut self, i: usize, x: T) {
        let mut idx = i + self.sz;
        self.node[idx] = x;
        while idx > 1 {
            idx = idx >> 1;
            self.node[idx] = self.node[idx << 1].op(&self.node[(idx << 1)  + 1]);
        }
    }

    pub fn fold(&self, left: usize, right: usize) -> T {
        let mut lx = T::identity();
        let mut rx = T::identity();
        let mut l = left + self.sz;
        let mut r = right + self.sz;
        while l < r {
            if (l & 1) == 1 { lx = lx.op(&self.node[l]); }
            if (r & 1) == 0 { rx = self.node[r].op(&rx); }
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        if l == r { lx = lx.op(&self.node[l]); }
        lx.op(&rx)
    }
}

#[derive(Clone)]
struct MultiSet<T: std::cmp::Ord> {
    elem_counts: std::collections::BTreeMap<T, usize>,
    size: usize
}

impl<T: std::cmp::Ord + std::fmt::Debug> MultiSet<T> {
    fn new() -> Self {
        Self {
            elem_counts: std::collections::BTreeMap::<T, usize>::new(),
            size: 0,
        }
    }

    fn is_empty(&self) -> bool {
        self.elem_counts.is_empty()
    }

    fn contains(&self, value: &T) -> bool {
        self.elem_counts.contains_key(value)
    }

    fn len(&self) -> usize {
        self.size
    }

    fn insert(&mut self, value: T) {
        self.size += 1;
        self.elem_counts
            .entry(value)
            .and_modify(|x| *x += 1)
            .or_insert(1);
    }

    fn remove(&mut self, value: &T) -> bool {
        if let Some(count) = self.elem_counts.get_mut(value) {
            if *count > 0 {
                *count -= 1;
                self.size -= 1;
                return true;
            }
        }
        self.elem_counts.remove(value).is_some()
    }

    fn remove_all(&mut self, value: &T) -> bool {
        self.size -= self.elem_counts.get(value).unwrap_or(&0);
        self.elem_counts.remove(value).is_some()
    }

    fn iter(&self) -> MultiSetIter<T> {
        MultiSetIter {
            iter: self.elem_counts.iter(),
            duplicate: None,
            duplicate_index: 0,
        }
    }
}

#[derive(Clone)]
struct MultiSetIter<'a, T: 'a> {
    iter: std::collections::btree_map::Iter<'a, T, usize>,
    duplicate: Option<(&'a T, &'a usize)>,
    duplicate_index: usize,
}

impl<'a, T> Iterator for MultiSetIter<'a, T> {
    type Item = &'a T;

    fn next(&mut self) -> Option<&'a T> {
        if self.duplicate.is_none() {
            self.duplicate = self.iter.next();
        }
        if let Some((key, count)) = self.duplicate {
            self.duplicate_index += 1;
            if self.duplicate_index >= *count {
                self.duplicate = None;
                self.duplicate_index = 0;
            }
            Some(key)
        } else {
            None
        }
    }
}

impl<'a, T> DoubleEndedIterator for MultiSetIter<'a, T> {
    fn next_back(&mut self) -> Option<&'a T> {
        if self.duplicate.is_none() {
            self.duplicate = self.iter.next_back();
        }
        if let Some((key, count)) = self.duplicate {
            if self.duplicate_index <= 0 {
                self.duplicate = None;
                self.duplicate_index = 0;
            } else {
                self.duplicate_index -= 1;
            }
            Some(key)
        } else {
            None
        }
    }
}

impl<T: Ord> std::fmt::Debug for MultiSet<T> {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        f.debug_set().entries(self.iter()).finish()
    }
}
