extern crate primal;
use std::time::Instant;

const NUM_OF_DIVISORS: u64 = 500;

fn main() {

    let now = Instant::now();

    let sieve = primal::Sieve::new(NUM_OF_DIVISORS.pow(2) as usize);

    let mut triangle_number = 1;
    let mut next_summand = 2;
    let mut number_found = false;

    while !number_found {
        let cnt:u64 = sieve.factor(triangle_number).unwrap().iter()
            .map(|x| (x.1 as u64) + 1).fold(1, |mut product, x| {product *= x; product});

        if cnt > NUM_OF_DIVISORS {
            number_found = true;
        } else {
            triangle_number += next_summand;
            next_summand += 1;
        }
    }

    println!("Triangle number: {}", triangle_number);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}