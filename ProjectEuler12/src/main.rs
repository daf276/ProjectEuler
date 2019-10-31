extern crate primal;

use std::time::Instant;

const NUM_OF_DIVISORS: u64 = 500;

struct Triangle {
    curr: usize,
    next_summand: usize,
}

impl Iterator for Triangle {
    type Item = usize;

    fn next(&mut self) -> Option<usize> {
        self.curr = self.curr + self.next_summand;
        self.next_summand += 1;

        Some(self.curr)
    }
}

fn triangle() -> Triangle {
    Triangle {
        curr: 1,
        next_summand: 2,
    }
}

fn main() {
    let now = Instant::now();
    let sieve = primal::Sieve::new(NUM_OF_DIVISORS.pow(2) as usize);

    let result = triangle()
        .map(|triangle_num| {
            let product = sieve
                .factor(triangle_num)
                .unwrap()
                .iter()
                .map(|x| (x.1 as u64) + 1)
                .fold(1, |mut product, x| product * x);
            (product, triangle_num)
        })
        .filter(|pair| pair.0 > NUM_OF_DIVISORS)
        .next()
        .unwrap()
        .1;

    println!("Triangle number: {}", result);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}
