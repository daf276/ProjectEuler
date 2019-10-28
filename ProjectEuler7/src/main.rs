extern crate primal_check;

use std::time::Instant;

use primal_check::miller_rabin;

struct Prime {
    curr: u64,
}

impl Iterator for Prime {
    type Item = u64;
    fn next(&mut self) -> Option<u64> {
        let mut new_next = self.curr + 1;

        while !miller_rabin(new_next) {
            new_next += 1;
        }

        self.curr = new_next;

        Some(self.curr)
    }
}

//Gives an iterator over all primes after the specified value
fn prime_sequence(x: u64) -> Prime {
    Prime { curr: x}
}

fn main() {
    let now = Instant::now();

    let mut number_of_primes = 0;
    let mut the_prime= 0;

    for i in prime_sequence(1) {
        number_of_primes += 1;

        if number_of_primes == 10001 {
            the_prime = i;
            break;
        }
    }

    println!("Prime: {}", the_prime);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}