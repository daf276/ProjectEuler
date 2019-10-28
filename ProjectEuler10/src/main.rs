extern crate num_iter;

use std::time::Instant;

fn sieve_of_eratosthenes(limit: usize) -> Vec<bool> {
    let mut primes = vec![true; limit];
    primes[0] = false;
    primes[1] = false;

    let slimit = f64::sqrt(limit as f64) as usize;
    for i in 2..=slimit {
        if primes[i] {
            for j in num_iter::range_step(i*i, limit, i) {
                primes[j] = false;
            }
        }
    }

    return primes;
}

fn main() {
    let now = Instant::now();

    let primes = sieve_of_eratosthenes(2000000);
    let mut sum = 0;

    for (index, is_prime) in primes.into_iter().enumerate(){
        if is_prime {
            sum += index;
        }
    }

    println!("Sum: {}", sum);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}