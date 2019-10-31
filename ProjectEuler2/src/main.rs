use std::time::{Duration, Instant};

struct Fibonacci {
    curr: u64,
    next: u64,
}

impl Iterator for Fibonacci {
    type Item = u64;

    fn next(&mut self) -> Option<u64> {
        let new_next = self.curr + self.next;

        self.curr = self.next;
        self.next = new_next;

        Some(self.curr)
    }
}

fn fibonacci() -> Fibonacci {
    Fibonacci { curr: 1, next: 1 }
}

fn main() {
    let now = Instant::now();

    let sum:u64 = fibonacci().take_while(|&x| x < 4000000).filter(|&x| x % 2 == 0).sum();

    println!("Sum: {}", sum);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}
